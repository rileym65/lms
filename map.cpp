#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "map.h"


Map::Map() {
  Int32 i;
  Int32 x,y;
  craters = NULL;
  numCraters = 0;
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
  readFeatures();
  seed(1);
  for (y=-90; y<=90; y++)
    for (x=-180; x<=180; x++)
      if (levelH[y+90][x+180] == '_') {
        i = random(100);
        if (i<50) levelH[y+90][x+180] = '~';
        else if (i<75) levelH[y+90][x+180] = '^';
        else levelH[y+90][x+180] = 'u';
        }
  }

Map::~Map() {
  }

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

void Map::readFeatures() {
  FILE* file;
  char  line[1024];
  char  name[100];
  Double lng;
  Double lat;
  Double diam;
  Int32  ilng;
  Int32  ilat;
  Int32  cellX;
  Int32  cellY;
  char   symbol[64];
  file = fopen("lunarref.txt","r");
  while (fgets(line,1024,file) != NULL) {
    if (strncasecmp(line,"Crater ",7) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      numCraters++;
      if (numCraters == 1) craters = (FEATURE*)malloc(sizeof(FEATURE));
        else craters = (FEATURE*)realloc(craters,sizeof(FEATURE)*numCraters);
      if (craters == NULL) {
        printf("Could not allocate needed memory. aborting\n");
        exit(1);
        }
      craters[numCraters-1].longitude = lng;
      craters[numCraters-1].latitude = lat;
      craters[numCraters-1].diameter = diam;
      ilng = (int)lng;
      ilat = (int)lat;
      if (diam < 5) levelH[ilat+90][ilng+180] = '.';
      else if (diam < 15) levelH[ilat+90][ilng+180] = 'o';
      else if (diam < 60) levelH[ilat+90][ilng+180] = 'O';
      else drawCrater(lng,lat,diam);
      }
    if (strncasecmp(line,"Mare ",5) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      ilng = (int)lng;
      ilat = (int)lat;
      drawMare(lng,lat,diam,' ');
      }
    if (strncasecmp(line,"Rima ",5) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      ilng = (int)lng;
      ilat = (int)lat;
      drawRill(lng,lat,diam,'/');
      }
    if (strncasecmp(line,"Rimae ",6) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      ilng = (int)lng;
      ilat = (int)lat;
      drawRill(lng,lat,diam,'#');
      }
    if (strncasecmp(line,"Lacus ",6) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      ilng = (int)lng;
      ilat = (int)lat;
      drawMare(lng,lat,diam,' ');
      }
    if (strncasecmp(line,"Mons ",5) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      ilng = (int)lng;
      ilat = (int)lat;
      drawFeature(lng,lat,diam,'^');
      }
    if (strncasecmp(line,"Montes ",7) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      ilng = (int)lng;
      ilat = (int)lat;
      drawMare(lng,lat,diam,'^');
      }
    if (strncasecmp(line,"Vallis ",7) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      ilng = (int)lng;
      ilat = (int)lat;
      drawMare(lng,lat,diam,' ');
      }
    if (strncasecmp(line,"Promontorium ",13) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      ilng = (int)lng;
      ilat = (int)lat;
      drawFeature(lng,lat,diam,'~');
      }
    if (strncasecmp(line,"Palus ",6) == 0 ||
        strncasecmp(line,"Sinus ",6) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      ilng = (int)lng;
      ilat = (int)lat;
      drawMare(lng,lat,diam,' ');
      }
    if (strncasecmp(line,"Feature ",8) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %1s",name,&lat,&lng,symbol);
      cellX = Cell(lng);
      cellY = Cell(lat);
      numFeatures++;
      if (numFeatures == 1) features = (FEATURE*)malloc(sizeof(FEATURE));
        else features = (FEATURE*)realloc(features,sizeof(FEATURE)*numFeatures);
      if (features == NULL) {
        printf("Could not allocate needed memory. aborting\n");
        exit(1);
        }
      features[numFeatures-1].longitude = lng;
      features[numFeatures-1].latitude = lat;
      features[numFeatures-1].symbol = symbol[0];
      features[numFeatures-1].cellX = cellX;
      features[numFeatures-1].cellY = cellY;
      }
    }
  fclose(file);
  }

void Map::generateLevelMMap(Double longitude,Double latitude) {
  Int32 x,y;
  for (y=0; y<=61; y++)
    for (x=0; x<=61; x++)
       levelM[y][x] = '_';


  lastLongitude = longitude;
  lastLatitude = latitude;
  }

void Map::seed(UInt32 s) {
  srand(s);
  }

Int32 Map::random(UInt32 range) {
  Double d;
  d = rand();
  d /= RAND_MAX;
  return (int)(d * range);
  }

Int32 Map::Cell(Double degrees) {
  Int32 ret;
  ret = (int)(degrees * CELL);
  if (degrees >= 0) ret++;
  return ret;
  }

Int32 Map::CellH(Int32 longitude,Int32 latitude) {
  latitude = -latitude;
  if (longitude < -180 || longitude > 180) return '#';
  if (latitude < -90 || latitude > 90) return '#';
  return levelH[latitude+90][longitude+180];
  }

char Map::Lurrain(Int32 cellX, Int32 cellY) {
  Int32 i;
  for (i=0; i<numFeatures; i++)
    if (features[i].cellX == cellX && features[i].cellY == cellY)
      return features[i].symbol;
  i = (cellX & 0xffff) | (cellY << 16);
  srand(i);
  i = rand() & 0x7f;
  if (i >=  0 && i <=  0) return '^';
  if (i >=  1 && i <=  5) return '.';
  if (i >=  6 && i <= 10) return 'o';
  if (i >= 11 && i <= 12) return 'O';
  if (i >= 13 && i <= 15) return '*';
  return ' ';
  }

Int32 Map::CellM(Double longitude, Double latitude) {
  Int32 cellX,cellY;
//  latitude = -latitude;
  if (longitude < lastLongitude-1 || longitude > lastLongitude+1 ||
      latitude < lastLatitude-1 || latitude > lastLatitude+1) {
printf("generate %f,%f > %f,%f\n",longitude,latitude,lastLongitude,lastLatitude);
    generateLevelMMap(longitude,latitude);
    }
  cellX = ((longitude-lastLongitude) / (1.0/30.0));
  cellY = ((latitude - lastLatitude) / (1.0/30.0));
//printf("%f,%f  ->  %d,%d\n",longitude,latitude,cellX,cellY);
  return levelM[cellY+31][cellX+31];
  }



