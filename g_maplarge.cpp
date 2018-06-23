#include "header.h"
#include "types.h"
#include "gauge.h"
#include "map.h"
#include "g_maplarge.h"
#include "terminal.h"

G_MapLarge::G_MapLarge(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 45;
  height = 23;
  Reset();
  }

G_MapLarge::~G_MapLarge() {
  }

void G_MapLarge::Reset() {
  Int8 i;
  lastCellX = -99999999;
  lastCellY = -99999999;
  for (i=0; i<19; i++)
    strcpy(data[i],".........................................");
  }

void G_MapLarge::Display() {
  GotoXY(x,y+ 0); Write("                                             ");
  GotoXY(x,y+ 1); Write(" +----------------west|--------------------+ ");
  GotoXY(x,y+ 2); Write(" |                                         | ");
  GotoXY(x,y+ 3); Write(" |                                         | ");
  GotoXY(x,y+ 4); Write(" |                                         | ");
  GotoXY(x,y+ 5); Write(" |                                         | ");
  GotoXY(x,y+ 6); Write(" |                                         |n");
  GotoXY(x,y+ 7); Write(" |                                         |o");
  GotoXY(x,y+ 8); Write(" |                                         |r");
  GotoXY(x,y+ 9); Write(" |                                         |t");
  GotoXY(x,y+10); Write(" |                                         |h");
  GotoXY(x,y+11); Write("--                                         --");
  GotoXY(x,y+12); Write("s|                                         | ");
  GotoXY(x,y+13); Write("o|                                         | ");
  GotoXY(x,y+14); Write("u|                                         | ");
  GotoXY(x,y+15); Write("t|                                         | ");
  GotoXY(x,y+16); Write("h|                                         | ");
  GotoXY(x,y+17); Write(" |                                         | ");
  GotoXY(x,y+18); Write(" |                                         | ");
  GotoXY(x,y+19); Write(" |                                         | ");
  GotoXY(x,y+20); Write(" |                                         | ");
  GotoXY(x,y+21); Write(" +--------------------|east----------------+ ");
  }

void G_MapLarge::Update() {
  Int32 i,j;
  Int32 cellX, cellY;
  Double lat,lng;
  char buffer[80];
  lng = currentVehicle->Longitude();
  lat = currentVehicle->Latitude();
  cellX = map->Cell(currentVehicle->Longitude());
  cellY = map->Cell(currentVehicle->Latitude());
  if (cellX != lastCellX || cellY != lastCellY) {
    for (j=0; j<19; j++)
      for (i=0; i<41; i++)
        data[j][i] = map->Lurrain(lng+(j-9)*MAPCELL,lat+(i-20)*MAPCELL);
//        data[j][i] = map->Lurrain(cellX+j-9,cellY+i-20);
    lastCellX = cellX;
    lastCellY = cellY;
    if (lrv->IsSetup()) {
      cellX = map->Cell(lrv->Longitude()) - lastCellX;
      cellY = map->Cell(lrv->Latitude()) - lastCellY;
      if (cellX >= - 9 && cellX <= 9 && cellY >= -20 && cellY <= 20)
        data[cellX+9][cellY+20] = 'l';
      }
    if (flagPlanted) {
      cellX = map->Cell(flagLongitude) - lastCellX;
      cellY = map->Cell(flagLatitude) - lastCellY;
      if (cellX >= - 9 && cellX <= 9 && cellY >= -20 && cellY <= 20)
        data[cellX+9][cellY+20] = 'f';
      }
    if (laserSetup) {
      cellX = map->Cell(laserLongitude) - lastCellX;
      cellY = map->Cell(laserLatitude) - lastCellY;
      if (cellX >= - 9 && cellX <= 9 && cellY >= -20 && cellY <= 20)
        data[cellX+9][cellY+20] = '_';
      }
    if (alsepSetup) {
      cellX = map->Cell(alsepLongitude) - lastCellX;
      cellY = map->Cell(alsepLatitude) - lastCellY;
      if (cellX >= - 9 && cellX <= 9 && cellY >= -20 && cellY <= 20)
        data[cellX+9][cellY+20] = '"';
      }
    cellX = map->Cell(lm->Longitude()) - lastCellX;
    cellY = map->Cell(lm->Latitude()) - lastCellY;
    if (cellX >= - 9 && cellX <= 9 && cellY >= -20 && cellY <= 20)
      data[cellX+9][cellY+20] = 'm';
    data[9][20] = '@';

    for (i=0; i<19; i++) {
      GotoXY(x+2,y+i+2); sprintf(buffer,"%s",data[i]); Write(buffer);
      }
    }
  }

