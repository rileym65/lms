#include "header.h"
#include "types.h"
#include "gauge.h"
#include "map.h"
#include "g_mapmed.h"
#include "terminal.h"

G_MapMed::G_MapMed(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 25;
  height = 14;
  Reset();
  }

G_MapMed::~G_MapMed() {
  }

void G_MapMed::Reset() {
  UInt8 i;
  lastCellX = -99999999;
  lastCellY = -99999999;
  for (i=0; i<11; i++)
    strcpy(data[i],".....................");
  }

void G_MapMed::Display() {
  GotoXY(x,y+ 0); Write("                         ");
  GotoXY(x,y+ 1); Write(" +------west|----------+ ");
  GotoXY(x,y+ 2); Write(" |                     |n");
  GotoXY(x,y+ 3); Write(" |                     |o");
  GotoXY(x,y+ 4); Write(" |                     |r");
  GotoXY(x,y+ 5); Write(" |                     |t");
  GotoXY(x,y+ 6); Write(" |                     |h");
  GotoXY(x,y+ 7); Write("--                     --");
  GotoXY(x,y+ 8); Write("s|                     | ");
  GotoXY(x,y+ 9); Write("o|                     | ");
  GotoXY(x,y+10); Write("u|                     | ");
  GotoXY(x,y+11); Write("t|                     | ");
  GotoXY(x,y+12); Write("h|                     | ");
  GotoXY(x,y+13); Write(" +----------|east------+ ");
  }

void G_MapMed::Update() {
  Int32 i,j;
  Int32 cellX, cellY;
  Double lat,lng;
  char buffer[64];
  lng = currentVehicle->Longitude();
  lat = currentVehicle->Latitude();
  cellX = map->Cell(currentVehicle->Longitude());
  cellY = map->Cell(currentVehicle->Latitude());
  if (cellX != lastCellX || cellY != lastCellY) {
    for (j=0; j<11; j++)
      for (i=0; i<21; i++)
        data[j][i] = map->Lurrain(lng+(j-5)*MAPCELL,lat+(i-10)*MAPCELL);
//        data[j][i] = map->Lurrain(cellX+j-5,cellY+i-10);
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
    if (cellX >= - 5 && cellX <= 5 && cellY >= -10 && cellY <= 10)
      data[cellX+5][cellY+10] = 'm';
    data[5][10] = '@';
    for (i=0; i<11; i++) {
      GotoXY(x+2,y+i+2); sprintf(buffer,"%s",data[i]); Write(buffer);
      }
    }
  }

