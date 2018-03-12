#define MAIN

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "types.h"
#include "map.h"

#define GROUND 1738300
#define METERS (1.0/30.0)

Map *map;
char data[81][81];
Double longitude;
Double latitude;

void clearMap() {
  UInt8 pos;
  UInt8 i;
  pos = 0;
  strcpy(data[pos++],"                                                                                ");
  strcpy(data[pos++],"         |         |         |         |         |         |         |          ");
  strcpy(data[pos++],"        ++---------+---------+---------+---------+---------+---------++         ");
  for (i=0; i<61; i++) {
    if ((i-0)%10 == 0)
      strcpy(data[pos++],"       -+                                                             +-        ");
    else
      strcpy(data[pos++],"        |                                                             |         ");
    }
  strcpy(data[pos++],"        ++---------+---------+---------+---------+---------+---------++         ");
  strcpy(data[pos++],"         |         |         |         |         |         |         |          ");
  strcpy(data[pos++],"                                                                                ");
  }

void fillMapH() {
  Int32 x,y;
  UInt32 i,j;
  Double l;
  char n[8];
  l = latitude - 30.0;
  for (i=0; i<7; i++) {
    if (l >= 0) sprintf(n,"%5.2fN",l);
      else sprintf(n,"%5.2fS",-l);
    for (j=0; j<strlen(n); j++) {
      data[0][i*10+j+7]=n[j];
      data[66][i*10+j+7]=n[j];
      }
    l += 10.0;
    }
  l = longitude - 30.0;
  for (i=0; i<7; i++) {
    if (l >= 0) sprintf(n,"%6.2fE",l);
      else sprintf(n,"%6.2fW",-l);
    for (j=0; j<strlen(n); j++) {
      data[i*10+3][j]=n[j];
      data[i*10+3][j+72]=n[j];
      }
    l += 10.0;
    }
  for (x=-30; x<31; x++)
    for (y=-30; y<31; y++)
      data[x+33][y+39] = map->CellH(longitude+x,latitude+y);
  }

void fillMapM() {
  Int32 x,y;
  Double dx,dy;
  Int32 i;
  UInt32 j;
  Double l;
  char n[8];
  for (i=-3; i<=3; i++) {
    l = latitude + (i * METERS * 10);
    if (l >= 0) sprintf(n,"%6.2fN",l);
      else sprintf(n,"%6.2fS",-l);
    for (j=0; j<strlen(n); j++) {
      data[0][i*10+36+j]=n[j];
      data[66][i*10+36+j]=n[j];
      }
    }

  for (i=-3; i<=3; i++) {
    l = longitude + (i * METERS * 10);
    if (l >= 0) sprintf(n,"%6.2fE",l);
      else sprintf(n,"%6.2fW",-l);
    for (j=0; j<strlen(n); j++) {
      data[33+i*10][j]=n[j];
      data[33+i*10][j+72]=n[j];
      }
    }
  x = map->CellM(longitude,latitude);
  for (x=-30; x<31; x++)
    for (y=-30; y<31; y++) {
      dx = (x * METERS);
      dy = (y * METERS);
      data[x+33][y+39] = map->CellM(longitude+dx,latitude+dy);
      }
  }

void fillMapL() {
  Int32 x,y;
  Int32 cellX,cellY;
  Int32 i;
  UInt32 j;
  Double l;
  char n[8];
  for (i=-3; i<=3; i++) {
    l = latitude + (i * METERS / 10);
    if (l >= 0) sprintf(n,"%6.2fN",l);
      else sprintf(n,"%6.2fS",-l);
    for (j=0; j<strlen(n); j++) {
      data[0][i*10+36+j]=n[j];
      data[66][i*10+36+j]=n[j];
      }
    }

  for (i=-3; i<=3; i++) {
    l = longitude + (i * METERS / 10);
    if (l >= 0) sprintf(n,"%6.2fE",l);
      else sprintf(n,"%6.2fW",-l);
    for (j=0; j<strlen(n); j++) {
      data[33+i*10][j]=n[j];
      data[33+i*10][j+72]=n[j];
      }
    }
  x = map->CellM(longitude,latitude);
  cellX = map->Cell(longitude);
  cellY = map->Cell(latitude);
  for (x=-30; x<31; x++)
    for (y=-30; y<31; y++) {
      data[x+33][y+39] = map->Lurrain(cellX+x, cellY+y);
      }
  }

int main(int argc, char** argv) {
  FILE *file;
  Int32 y;
  char line[1024];
  char mode;
  map = new Map();
  longitude = -99990;
  latitude = -99990;
  mode = ' ';
  printf("\n\n\n");
  printf("Lunar Mission Simulator\n\n");
  printf("Map generator\n\n");
  while (latitude <-90 || latitude > 90) {
    printf("Enter center latitude: ");
    fgets(line,1000,stdin);
    latitude = atof(line);
    }
  while (longitude <-180 || longitude > 180) {
    printf("Enter center longitude: ");
    fgets(line,1000,stdin);
    longitude = atof(line);
    }
  while (mode != 'H' && mode != 'M' && mode != 'L') {
    printf("<H>igh altitude, <M>edium altitude, or <L>ow altitude ?");
    fgets(line,1000,stdin);
    mode = line[0];
    if (mode == 'h') mode = 'H';
    if (mode == 'm') mode = 'M';
    if (mode == 'l') mode = 'L';
    }
  clearMap();
  if (mode == 'H') fillMapH();
  if (mode == 'M') fillMapM();
  if (mode == 'L') fillMapL();

  if ((file = fopen("map.doc","w")) == NULL) {
    printf("Could not open output file.  Aborting\n\n");
    exit(1);
    }
  for (y=0;y<67;y++)
    fprintf(file,"%s\n",data[y]);
  fclose(file);

  delete(map);
  }

