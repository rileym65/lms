#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "map.h"

Map::Map() {
  Int32 i;
  Int32 x,y;
  features = NULL;
  numFeatures = 0;
  lastLongitude = -99999;
  lastLatitude = -99999;
  for (y=-90; y<=90; y++)
    for (x=-180; x<=180; x++)
      levelH[y+90][x+180] = '_';
  for (y=0; y<61; y++)
    for (x=0; x<61; x++)
       levelM[y][x] = '_';
  loadFeatures("lunarref.txt");
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

void Map::loadFeatures(const char* filename) {
  FILE* file;
  char  line[1024];
  char  name[100];
  Double lng;
  Double lat;
  Double diam;
  Int32  cellX;
  Int32  cellY;
  char   symbol[64];
  file = fopen(filename,"r");
  if (file == NULL) return;
  while (fgets(line,1024,file) != NULL) {
    sscanf(line,"%[^,], %lf, %lf, %lf, %1s",name,&lat,&lng,&diam,symbol);
    cellX = Cell(lng);
    cellY = Cell(lat);
    numFeatures++;
    if (numFeatures == 1) features = (FEATURE*)malloc(sizeof(FEATURE));
      else features = (FEATURE*)realloc(features,sizeof(FEATURE)*numFeatures);
    if (features == NULL) {
      WriteLn("Could not allocate needed memory. aborting");
      exit(1);
      }
    strcpy(features[numFeatures-1].name, name);
    features[numFeatures-1].longitude = lng;
    features[numFeatures-1].latitude = lat;
    features[numFeatures-1].diameter = diam;
    features[numFeatures-1].symbol = symbol[0];
    features[numFeatures-1].cellX = cellX;
    features[numFeatures-1].cellY = cellY;
    }
  fclose(file);
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
        if (i == cx-ix || i == cx+ix) levelH[cy+iy][i] = '^';
          else if (levelH[cy+iy][i] != '^' &&
                   levelH[cy+iy][i] != '.' &&
                   levelH[cy+iy][i] != 'o' &&
                   levelH[cy+iy][i] != 'O') levelH[cy+iy][i] = ' ';
        }
      if (cy-iy >= 0 && cy-iy <= 180 && i >= 0 && i <= 360) {
        if (i == cx-ix || i == cx+ix) levelH[cy-iy][i] = '^';
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
  for (i=0; i<numFeatures; i++) {
    lng = features[i].longitude;
    lat = features[i].latitude;
    diam = features[i].diameter;
    ilng = (int)features[i].longitude;
    ilat = (int)features[i].latitude;
    if (strncasecmp(features[i].name,"Crater ",7) == 0) {
      if (diam< 5) levelH[ilat+90][ilng+180] = '.';
      else if (diam < 15) levelH[ilat+90][ilng+180] = 'o';
      else if (diam < 60) levelH[ilat+90][ilng+180] = 'O';
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
    if (strncasecmp(features[i].name,"Feature ",8) == 0) {
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
  Int32  i;
  Double lng;
  Double lat;
  Double diam;
  Double dist;
  Int32  ilng;
  Int32  ilat;
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
    dist = sqrt(sqr(longitude-lng) + sqr(latitude-lat));
    ilng = (int)features[i].longitude;
    ilat = (int)features[i].latitude;
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
    if (strncasecmp(features[i].name,"Feature ",8) == 0) {
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
  Int32 cellX, cellY;
  cellX = Cell(longitude);
  cellY = Cell(latitude);
  char ltype;
  for (i=0; i<numFeatures; i++)
    if (features[i].cellX == cellX && features[i].cellY == cellY)
      return features[i].symbol;
  i = (cellX & 0x7fffffff) ^ (cellY << 15);
  rng.Seed(i);
  i = rng.Next(1000);
  ltype = CellM(longitude, latitude);
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
  Int32 cellX,cellY;
//  latitude = -latitude;
  if (longitude < lastLongitude-1 || longitude > lastLongitude+1 ||
      latitude < lastLatitude-1 || latitude > lastLatitude+1) {
//printf("generate %f,%f > %f,%f\n",longitude,latitude,lastLongitude,lastLatitude);
    generateLevelMMap(longitude,latitude);
    }
  cellX = ((longitude-lastLongitude) / (1.0/30.0));
  cellY = ((latitude - lastLatitude) / (1.0/30.0));
//printf("%f,%f  ->  %d,%d\n",longitude,latitude,cellX,cellY);
  return levelM[cellY+31][cellX+31];
  }



