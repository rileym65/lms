#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "terminal.h"
#include "map.h"
#include "lunarref.h"
#include "common.h"

#define GROUND 1738300
#define METERS ((GROUND*2*PI) / 360.0)
#define MAPCELL           (1.0/(METERS/10.0))
#define CELL (METERS / 10)

Map::Map() {
  Int32 i;
  Int32 x,y;
  features = NULL;
  numFeatures = 0;
  lastLongitude = -99999;
  lastLatitude = -99999;
  for (i=0; i<360; i++) numSegments[i] = 0;
  for (y=-90; y<=90; y++)
    for (x=-180; x<=180; x++)
      levelH[y+90][x+180] = '_';
  for (y=0; y<61; y++)
    for (x=0; x<61; x++)
       levelM[y][x] = '_';
//  loadFeatures("lunarref.txt");
  loadFeatures(NULL);
  loadFeatures("userref.txt");
  generateLevelHMap();
  rng.Seed(1);
  for (y=-90; y<=90; y++)
    for (x=-180; x<=180; x++)
      if (levelH[y+90][x+180] == '_') {
        i = rng.Next(100);
        if (i<50) levelH[y+90][x+180] = '~';
        else if (i<75) levelH[y+90][x+180] = '^';
        else levelH[y+90][x+180] = 'u';
        }
  }

Map::~Map() {
  }

void Map::addToSegment(Int32 segment, UInt32 value) {
  segment += 180;
  while (segment < 0) segment += 360;
  while (segment >= 360) segment -= 360;
  ++numSegments[segment];
  segments[segment][numSegments[segment]-1] = value;
  }

void Map::processFeature(const char* line) {
  Int32 i;
  char  name[100];
  Double lng;
  Double lat;
  Double diam;
  Double rad;
  Double width;
  Double peak;
  Int32  cellX;
  Int32  cellY;
  char   symbol[64];
    sscanf(line,"%[^,], %lf, %lf, %lf, %lf, %1s",name,&lat,&lng,&diam,&peak,symbol);
    cellX = Cell(lng);
    cellY = Cell(lat);
    numFeatures++;
    if (numFeatures == 1) features = (FEATURE*)malloc(sizeof(FEATURE));
      else features = (FEATURE*)realloc(features,sizeof(FEATURE)*numFeatures);
    if (features == NULL) {
      WriteLn("Could not allocate needed memory. aborting");
      exit(1);
      }
    rad = (diam * 1000) / 2;
    peak = (peak * 1000.0) / 2.0;
    strcpy(features[numFeatures-1].name, name);
    features[numFeatures-1].longitude = lng;
    features[numFeatures-1].latitude = lat;
    features[numFeatures-1].diameter = diam;
    features[numFeatures-1].peak = peak;
    features[numFeatures-1].symbol = symbol[0];
    features[numFeatures-1].cellX = cellX;
    features[numFeatures-1].cellY = cellY;
    features[numFeatures-1].minLongitude = lng - (rad / METERS) - 0.5;
    features[numFeatures-1].maxLongitude = lng + (rad / METERS) + 0.5;
    features[numFeatures-1].minLatitude = lat - (rad / METERS) - 0.5;
    features[numFeatures-1].maxLatitude = lat + (rad / METERS) + 0.5;
    features[numFeatures-1].minCellX = Cell(features[numFeatures-1].minLongitude);
    features[numFeatures-1].maxCellX = Cell(features[numFeatures-1].maxLongitude);
    features[numFeatures-1].minCellY = Cell(features[numFeatures-1].minLatitude);
    features[numFeatures-1].maxCellY = Cell(features[numFeatures-1].maxLatitude);
    features[numFeatures-1].cellRadius = 
      (features[numFeatures-1].maxCellX - cellX) * (features[numFeatures-1].maxCellX - cellX);
    features[numFeatures-1].radius = rad * rad;
    features[numFeatures-1].radius = rad;
    width = 25;
    if (rad < 200) width = 7;
    features[numFeatures-1].rad1 = (rad-width) * (rad-width);
    features[numFeatures-1].rad2 = (rad+width) * (rad+width);
    features[numFeatures-1].rad3 = peak * peak;
    for (i=(int)(lng-2); i<=(int)(lng+2); i++)
      addToSegment(i, numFeatures-1);
  }

void Map::loadFeatures(const char* filename) {
  FILE* file;
  char  line[1024];
  Int32  pos;
  if (filename != NULL) {
    file = fopen(filename,"r");
    if (file == NULL) return;
    while (fgets(line,1024,file) != NULL) {
      processFeature(line);
      }
    fclose(file);
    }
  else {
    pos = 0;
    while (featureList[pos].valid != 0) {
      processFeature(featureList[pos].data);
      pos++;
      }
    }
  }

FEATURE* Map::Features() {
  return features;
  }

Int32 Map::NumFeatures() {
  return numFeatures;
  }

/* ****************************************************** */
/* ***** Routines for generating high altitude maps ***** */
/* ****************************************************** */
void Map::drawCrater(Double longitude, Double latitude, Double diameter) {
  Double x,y;
  Double radius;
  Int32  ix,iy;
  Int32  cx,cy;
  Int32  i;
  cx = 180 + (int)longitude;
  cy = 90 - (int)latitude;
  radius = diameter / 2;
  x = radius;
  radius *= radius;
  while (x >= 0) {
    y = sqrt(radius - x*x);
    ix = (int)(x / 30.0);
    iy = (int)(y / 30.0);
    for (i=cx-ix; i<=cx+ix; i++) {
      if (cy+iy >= 0 && cy+iy <= 180 && i >= 0 && i <= 360) {
        if (i == cx-ix || i == cx+ix) levelH[cy+iy][i] = '(';
          else if (levelH[cy+iy][i] != '^' &&
                   levelH[cy+iy][i] != '.' &&
                   levelH[cy+iy][i] != 'o' &&
                   levelH[cy+iy][i] != 'O') levelH[cy+iy][i] = ' ';
        }
      if (cy-iy >= 0 && cy-iy <= 180 && i >= 0 && i <= 360) {
        if (i == cx-ix || i == cx+ix) levelH[cy-iy][i] = ')';
          else if (levelH[cy-iy][i] != '^' &&
                   levelH[cy-iy][i] != '.' &&
                   levelH[cy-iy][i] != 'o' &&
                   levelH[cy-iy][i] != 'O') levelH[cy-iy][i] = ' ';
        }
      }
    x -= 5;
    }
  }

void Map::drawMare(Double longitude, Double latitude, Double diameter,char ch) {
  Double x,y;
  Double radius;
  Int32  ix,iy;
  Int32  cx,cy;
  Int32  i;
  cx = 180 + (int)longitude;
  cy = 90 - (int)latitude;
  radius = diameter / 2;
  x = radius;
  radius *= radius;
  while (x >= 0) {
    y = sqrt(radius - x*x);
    ix = (int)(x / 30.0);
    iy = (int)(y / 30.0);
    for (i=cx-ix; i<=cx+ix; i++) {
      if (cy+iy >= 0 && cy+iy <= 180 && i >= 0 && i <= 360) {
        if (levelH[cy+iy][i] == '_') levelH[cy+iy][i] = ch;
        }
      if (cy-iy >= 0 && cy-iy <= 180 && i >= 0 && i <= 360) {
        if (levelH[cy-iy][i] == '_') levelH[cy-iy][i] = ch;
        }
      }
    x -= 1;
    }
  }

void Map::drawRill(Double longitude, Double latitude, Double diameter,char ch) {
//  Double x,y;
//  Double radius;
//  Int32  ix,iy;
  Int32  cx,cy;
//  Int32  i;
  cx = 180 + (int)longitude;
  cy = 90 - (int)latitude;
  levelH[cy][cx] = ch;
/*
  radius = diameter / 2;
  x = radius;
  radius *= radius;
  while (x >= 0) {
    y = sqrt(radius - x*x);
    ix = (int)(x / 30.0);
    iy = (int)(y / 30.0);
    for (i=cx-ix; i<=cx+ix; i++) {
      if (cy+iy >= 0 && cy+iy <= 180 && i >= 0 && i <= 360) {
        levelH[cy+iy][i] = ch;
        }
      if (cy-iy >= 0 && cy-iy <= 180 && i >= 0 && i <= 360) {
        levelH[cy-iy][i] = ch;
        }
      }
    x -= 1;
    }
*/
  }

void Map::drawFeature(Double longitude, Double latitude, Double diameter,char ch) {
  Double x,y;
  Double radius;
  Int32  ix,iy;
  Int32  cx,cy;
  Int32  i;
  cx = 180 + (int)longitude;
  cy = 90 - (int)latitude;
  radius = diameter / 2;
  x = radius;
  radius *= radius;
  while (x >= 0) {
    y = sqrt(radius - x*x);
    ix = (int)(x / 30.0);
    iy = (int)(y / 30.0);
    for (i=cx-ix; i<=cx+ix; i++) {
      if (cy+iy >= 0 && cy+iy <= 180 && i >= 0 && i <= 360) {
        levelH[cy+iy][i] = ch;
        }
      if (cy-iy >= 0 && cy-iy <= 180 && i >= 0 && i <= 360) {
        levelH[cy-iy][i] = ch;
        }
      }
    x -= 1;
    }
  }

char Map::symbolAt(Double longitude, Double latitude) {
  UInt32 i;
  char   ret;
  Double dx,dy,dist;
  ret = '_';
  for (i=0; i<numFeatures; i++)
    if (features[i].diameter > 0 &&
        features[i].symbol != '/') {
      if (longitude >= features[i].minLongitude &&
          longitude <= features[i].maxLongitude &&
          latitude >= features[i].minLatitude &&
          latitude <= features[i].maxLatitude) {
        if (features[i].symbol == 'o') {
          if (features[i].diameter < 5) ret = '.';
          if (features[i].diameter < 15) ret = 'o';
          if (features[i].diameter < 60) ret = 'X';
          else ret = ' ';
          }
        else if (ret == '_') {
          dx = (longitude - features[i].longitude) * METERS;
          dy = (latitude - features[i].latitude) * METERS;
          dist = dx*dx + dy*dy;
          if (dist <= features[i].radius)
            ret = features[i].symbol;
          if (ret == 'O') ret = ' ';
          }
        }
    }
  return ret;
  }

/*
void Map::generateLevelHMap() {
  Int32 x,y;
  for (y=-90; y<=90; y++)
    for (x=-180; x<=180; x++)
      levelH[y+90][x+180] = symbolAt(x, -y);
  }
*/

void Map::generateLevelHMap() {
  Int32  i;
  Double lng;
  Double lat;
  Double diam;
  Int32  ilng;
  Int32  ilat;
//  Int32  cellX;
//  Int32  cellY;
//  char   symbol[64];
  for (i=0; (UInt32)i<numFeatures; i++) {
    lng = features[i].longitude;
    lat = features[i].latitude;
    diam = features[i].diameter;
    ilng = (int)features[i].longitude;
    ilat = (int)features[i].latitude;
    if (strncasecmp(features[i].name,"Crater",6) == 0) {
      if (diam< 5) levelH[ilat+90][ilng+180] = ' ';
      else if (diam< 15) levelH[ilat+90][ilng+180] = '.';
      else if (diam < 30) levelH[ilat+90][ilng+180] = 'o';
      else if (diam < 90) levelH[ilat+90][ilng+180] = 'O';
      else drawCrater(lng,lat,diam);
      }
    if (strncasecmp(features[i].name,"Mare ",5) == 0) {
      drawMare(lng,lat,diam,' ');
      }
    if (strncasecmp(features[i].name,"Rima ",5) == 0) {
      drawRill(lng,lat,diam,'/');
      }
    if (strncasecmp(features[i].name,"Rimae ",6) == 0) {
      drawRill(lng,lat,diam,'#');
      }
    if (strncasecmp(features[i].name,"Lacus ",6) == 0) {
      drawMare(lng,lat,diam,' ');
      }
    if (strncasecmp(features[i].name,"Mons ",5) == 0) {
      drawFeature(lng,lat,diam,'^');
      }
    if (strncasecmp(features[i].name,"Montes ",7) == 0) {
      drawMare(lng,lat,diam,'^');
      }
    if (strncasecmp(features[i].name,"Vallis ",7) == 0) {
      drawMare(lng,lat,diam,' ');
      }
    if (strncasecmp(features[i].name,"Promontorium ",13) == 0) {
      drawFeature(lng,lat,diam,'~');
      }
    if (strncasecmp(features[i].name,"Palus ",6) == 0 ||
        strncasecmp(features[i].name,"Sinus ",6) == 0) {
      drawMare(lng,lat,diam,' ');
      }
    if (strncasecmp(features[i].name,"Manmade ",8) == 0) {
      }
    }
  }

/* ******************************************************** */
/* ***** Routines for generating medium altitude maps ***** */

/* ******************************************************** */
void Map::drawCraterMedium(Double longitude, Double latitude, Double diameter) {
  Double x,y;
  Double radius;
  Int32  ix,iy;
  Int32  cx,cy;
  Int32  i;
  cx = 180 + (int)longitude;
  cy = 90 - (int)latitude;
  radius = diameter / 2;
  x = radius;
  radius *= radius;
  while (x >= 0) {
    y = sqrt(radius - x*x);
    ix = (int)(x / 30.0);
    iy = (int)(y / 30.0);
    for (i=cx-ix; i<=cx+ix; i++) {
      if (cy+iy >= 0 && cy+iy <= 180 && i >= 0 && i <= 360) {
        if (i == cx-ix || i == cx+ix) levelH[cy+iy][i] = '(';
          else if (levelH[cy+iy][i] != '^' &&
                   levelH[cy+iy][i] != '.' &&
                   levelH[cy+iy][i] != 'o' &&
                   levelH[cy+iy][i] != 'O') levelH[cy+iy][i] = ' ';
        }
      if (cy-iy >= 0 && cy-iy <= 180 && i >= 0 && i <= 360) {
        if (i == cx-ix || i == cx+ix) levelH[cy-iy][i] = '(';
          else if (levelH[cy-iy][i] != '^' &&
                   levelH[cy-iy][i] != '.' &&
                   levelH[cy-iy][i] != 'o' &&
                   levelH[cy-iy][i] != 'O') levelH[cy-iy][i] = ' ';
        }
      }
    x -= 5;
    }
  }

void Map::generateLevelMMap(Double longitude,Double latitude) {
  UInt32  i;
  Double lng;
  Double lat;
  Double diam;
//  Double dist;
//  Int32  ilng;
//  Int32  ilat;
//  Int32  cellX;
//  Int32  cellY;
  Int32 x,y;

  for (y=0; y<=31; y++)
    for (x=0; x<=31; x++)
      levelM[y][x] = CellH((int)longitude+0.5,(int)latitude+0.5);
  for (y=0; y<=31; y++)
    for (x=32; x<=61; x++)
      levelM[y][x] = CellH((int)longitude-0.5,(int)latitude+0.5);
  for (y=32; y<=61; y++)
    for (x=0; x<=31; x++)
      levelM[y][x] = CellH((int)longitude+0.5,(int)latitude-0.5);
  for (y=32; y<=61; y++)
    for (x=32; x<=61; x++)
      levelM[y][x] = CellH((int)longitude-0.5,(int)latitude-0.5);


//  for (y=0; y<=61; y++)
//    for (x=0; x<=61; x++)
//       levelM[y][x] = '_';

//  char   symbol[64];
  for (i=0; i<numFeatures; i++) {
    lng = features[i].longitude;
    lat = features[i].latitude;
    diam = (features[i].diameter * 1000.0) / METERS;
//    dist = sqrt(sqr(longitude-lng) + sqr(latitude-lat));
//    ilng = (int)features[i].longitude;
//    ilat = (int)features[i].latitude;
    if (strncasecmp(features[i].name,"Crater ",7) == 0) {
      drawCraterMedium(lng,lat,diam);
      }
    if (strncasecmp(features[i].name,"Mare ",5) == 0) {
      }
    if (strncasecmp(features[i].name,"Rima ",5) == 0) {
      }
    if (strncasecmp(features[i].name,"Rimae ",6) == 0) {
      }
    if (strncasecmp(features[i].name,"Lacus ",6) == 0) {
      }
    if (strncasecmp(features[i].name,"Mons ",5) == 0) {
      }
    if (strncasecmp(features[i].name,"Montes ",7) == 0) {
      }
    if (strncasecmp(features[i].name,"Vallis ",7) == 0) {
      }
    if (strncasecmp(features[i].name,"Promontorium ",13) == 0) {
      }
    if (strncasecmp(features[i].name,"Palus ",6) == 0 ||
        strncasecmp(features[i].name,"Sinus ",6) == 0) {
      }
    if (strncasecmp(features[i].name,"Manmade ",8) == 0) {
      }
    }

  lastLongitude = longitude;
  lastLatitude = latitude;
  }

Int32 Map::Cell(Double degrees) {
  Int32 ret;
  ret = (int)(degrees * CELL);
  if (degrees >= 0) ret++;
  return ret;
  }

Double Map::Degrees(Int32 cell) {
  Double ret;
  if (cell >= 1) cell--;
  ret = cell / CELL;
  return ret;
  }


Int32 Map::CellH(Int32 longitude,Int32 latitude) {
  latitude = -latitude;
  if (longitude < -180 || longitude > 180) return '#';
  if (latitude < -90 || latitude > 90) return '#';
  return levelH[latitude+90][longitude+180];
  }

char Map::Lurrain(Double longitude, Double latitude) {
  Int32 i;
  UInt32 j;
  Int32 cellX, cellY;
  Double dist;
  Double dx,dy;
  Double cLat,cLong;
  Int32  segment;
  cellX = Cell(longitude);
  cellY = Cell(latitude);
  cLat = Degrees(cellY);
  cLong = Degrees(cellX);
  char ltype;
  ltype = '_';

  segment = (int)longitude;
  segment += 180;
  while (segment <0) segment += 360;
  while (segment >= 360) segment -= 360;
  for (j=0; j<numSegments[segment]; j++) {
    i = segments[segment][j];
    if (features[i].symbol != 'o' &&
        features[i].cellX == cellX && features[i].cellY == cellY)
      return features[i].symbol;

    if (features[i].symbol == 'o' &&
        cLong >= features[i].minLongitude && cLong <= features[i].maxLongitude &&
        cLat >= features[i].minLatitude && cLat <= features[i].maxLatitude) {
      dx = (cLong - features[i].longitude) * METERS;
      dy = (cLat - features[i].latitude) * METERS;
      dist = dx*dx + dy*dy;
      if (dist >= features[i].rad1 && dist <= features[i].rad2) {
        if (latitude < features[i].latitude) return '(';
        return ')';
        }
      else if (dist < features[i].rad3) return '^';
      else if (dist < features[i].rad1) ltype = ' ';
      }

    }

  i = (cellX & 0x7fffffff) ^ (cellY << 15);
i = (cellX & 0x7fff) * ((~cellY) & 0x7fff);
  rng.Seed(i);
//  if (ltype == '_') ltype = CellM(longitude, latitude);
  if (ltype == '_') ltype = CellH(longitude, latitude);
  i = rng.Next(1000);
  switch (ltype) {
    case '~':
         if ((i -= 6) < 0) return '.';
         if ((i -= 6) < 0) return 'o';
         if ((i -= 5) < 0) return 'O';
         if ((i -= 20) < 0) return ',';
         if ((i -= 15) < 0) return '+';
         if ((i -= 9) < 0) return '*';
         if ((i -= 15) < 0) return 'u';
         if ((i -= 15) < 0) return '^';
         return ' ';
         break;
    case '^':
         if ((i -= 8) < 0) return '.';
         if ((i -= 8) < 0) return 'o';
         if ((i -= 6) < 0) return 'O';
         if ((i -= 80) < 0) return ',';
         if ((i -= 40) < 0) return '+';
         if ((i -= 20) < 0) return '*';
         if ((i -= 30) < 0) return 'u';
         if ((i -= 60) < 0) return '^';
         return ' ';
         break;
    case 'u':
         if ((i -= 8) < 0) return '.';
         if ((i -= 8) < 0) return 'o';
         if ((i -= 6) < 0) return 'O';
         if ((i -= 30) < 0) return ',';
         if ((i -= 20) < 0) return '+';
         if ((i -= 12) < 0) return '*';
         if ((i -= 20) < 0) return 'u';
         if ((i -= 20) < 0) return '^';
         return ' ';
         break;
    default:
         if ((i -= 4) < 0) return '.';
         if ((i -= 4) < 0) return 'o';
         if ((i -= 3) < 0) return 'O';
         if ((i -= 10) < 0) return ',';
         if ((i -= 6) < 0) return '+';
         if ((i -= 3) < 0) return '*';
         if ((i -= 1) < 0) return 'u';
         if ((i -= 1) < 0) return '^';
         return ' ';
         break;
    }
  return ' ';
  }

Int32 Map::CellM(Double longitude, Double latitude) {
  Int32 i;
  UInt32 j;
  Int32 cellX, cellY;
  Double dist;
  Double dx,dy;
  Double cLat,cLong;
  Int32  segment;
  cellX = Cell(longitude);
  cellY = Cell(latitude);
  cLat = Degrees(cellY);
  cLong = Degrees(cellX);
  char ltype;
  ltype = '_';

  segment = (int)longitude;
  segment += 180;
  while (segment <0) segment += 360;
  while (segment >= 360) segment -= 360;
  for (j=0; j<numSegments[segment]; j++) {
    i = segments[segment][j];
    if (features[i].symbol != 'o' &&
        features[i].cellX == cellX && features[i].cellY == cellY)
      return features[i].symbol;

    if (features[i].symbol == 'o' &&
        cLong >= features[i].minLongitude && cLong <= features[i].maxLongitude &&
        cLat >= features[i].minLatitude && cLat <= features[i].maxLatitude) {
      dx = (cLong - features[i].longitude) * METERS;
      dy = (cLat - features[i].latitude) * METERS;
      dist = sqrt(dx*dx + dy*dy);
      if (dist >= sqrt(features[i].rad2)-1000 && dist <= sqrt(features[i].rad2)) {
        if (latitude < features[i].latitude) return '(';
        return ')';
        }
      else if (dist < sqrt(features[i].rad3)) return '^';
      else if (dist < sqrt(features[i].rad1)) ltype = ' ';
      }

    }

  i = (cellX & 0x7fffffff) ^ (cellY << 15);
i = (cellX & 0x7fff) * ((~cellY) & 0x7fff);
  rng.Seed(i);
//  if (ltype == '_') ltype = CellM(longitude, latitude);
  if (ltype == '_') ltype = CellH(longitude, latitude);
  i = rng.Next(250);
  switch (ltype) {
    case '~':
         if ((i -= 6) < 0) return '.';
         if ((i -= 6) < 0) return 'o';
         if ((i -= 5) < 0) return 'O';
         if ((i -= 20) < 0) return ',';
         if ((i -= 15) < 0) return '+';
         if ((i -= 9) < 0) return '*';
         if ((i -= 15) < 0) return 'u';
         if ((i -= 15) < 0) return '^';
         return ' ';
         break;
    case '^':
         if ((i -= 8) < 0) return '.';
         if ((i -= 8) < 0) return 'o';
         if ((i -= 6) < 0) return 'O';
         if ((i -= 80) < 0) return ',';
         if ((i -= 40) < 0) return '+';
         if ((i -= 20) < 0) return '*';
         if ((i -= 30) < 0) return 'u';
         if ((i -= 60) < 0) return '^';
         return ' ';
         break;
    case 'u':
         if ((i -= 8) < 0) return '.';
         if ((i -= 8) < 0) return 'o';
         if ((i -= 6) < 0) return 'O';
         if ((i -= 30) < 0) return ',';
         if ((i -= 20) < 0) return '+';
         if ((i -= 12) < 0) return '*';
         if ((i -= 20) < 0) return 'u';
         if ((i -= 20) < 0) return '^';
         return ' ';
         break;
    default:
         if ((i -= 4) < 0) return '.';
         if ((i -= 4) < 0) return 'o';
         if ((i -= 3) < 0) return 'O';
         if ((i -= 10) < 0) return ',';
         if ((i -= 6) < 0) return '+';
         if ((i -= 3) < 0) return '*';
         if ((i -= 1) < 0) return 'u';
         if ((i -= 1) < 0) return '^';
         return ' ';
         break;
    }
  return ' ';
  }



