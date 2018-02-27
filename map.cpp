#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "map.h"

Map::Map() {
  Int32 i;
  Int32 x,y;
  for (y=-90; y<=90; y++)
    for (x=-180; x<=180; x++)
      level0[y+90][x+180] = '_';
  readFeatures();
  seed(1);
  for (y=-90; y<=90; y++)
    for (x=-180; x<=180; x++)
      if (level0[y+90][x+180] == '_') {
        i = random(100);
        if (i<50) level0[y+90][x+180] = '~';
        else if (i<75) level0[y+90][x+180] = '^';
        else level0[y+90][x+180] = 'u';
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
        if (i == cx-ix || i == cx+ix) level0[cy+iy][i] = '*';
          else if (level0[cy+iy][i] != '^' &&
                   level0[cy+iy][i] != '.' &&
                   level0[cy+iy][i] != 'o' &&
                   level0[cy+iy][i] != 'O') level0[cy+iy][i] = ' ';
        }
      if (cy-iy >= 0 && cy-iy <= 180 && i >= 0 && i <= 360) {
        if (i == cx-ix || i == cx+ix) level0[cy-iy][i] = '*';
          else if (level0[cy-iy][i] != '^' &&
                   level0[cy-iy][i] != '.' &&
                   level0[cy-iy][i] != 'o' &&
                   level0[cy-iy][i] != 'O') level0[cy-iy][i] = ' ';
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
        if (level0[cy+iy][i] == '_') level0[cy+iy][i] = ch;
        }
      if (cy-iy >= 0 && cy-iy <= 180 && i >= 0 && i <= 360) {
        if (level0[cy-iy][i] == '_') level0[cy-iy][i] = ch;
        }
      }
    x -= 1;
    }
  }

void Map::drawRill(Double longitude, Double latitude, Double diameter,char ch) {
  Double x,y;
  Double radius;
  Int32  ix,iy;
  Int32  cx,cy;
  Int32  i;
  cx = 180 + (int)longitude;
  cy = 90 - (int)latitude;
  level0[cy][cx] = ch;
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
        level0[cy+iy][i] = ch;
        }
      if (cy-iy >= 0 && cy-iy <= 180 && i >= 0 && i <= 360) {
        level0[cy-iy][i] = ch;
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
        level0[cy+iy][i] = ch;
        }
      if (cy-iy >= 0 && cy-iy <= 180 && i >= 0 && i <= 360) {
        level0[cy-iy][i] = ch;
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
  file = fopen("lunarref.txt","r");
  while (fgets(line,1024,file) != NULL) {
    if (strncasecmp(line,"Crater ",7) == 0) {
      sscanf(line,"%[^,], %lf, %lf, %lf",name,&lat,&lng,&diam);
      ilng = (int)lng;
      ilat = (int)lat;
      if (diam < 5) level0[ilat+90][ilng+180] = '.';
      else if (diam < 15) level0[ilat+90][ilng+180] = 'o';
      else if (diam < 60) level0[ilat+90][ilng+180] = 'O';
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
    }
  fclose(file);
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

Int32 Map::Cell0(Int32 longitude,Int32 latitude) {
  latitude = -latitude;
  if (longitude < -180 || longitude > 180) return '#';
  if (latitude < -90 || latitude > 90) return '#';
  return level0[latitude+90][longitude+180];
  }

char Map::Lurrain(Int32 cellX, Int32 cellY) {
  Int32 i;
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



