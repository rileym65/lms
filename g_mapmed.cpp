#include "header.h"
#include "types.h"
#include "gauge.h"
#include "map.h"
#include "g_mapmed.h"
#include "terminal.h"

G_MapMed::G_MapMed(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
  width = 25;
  height = 14;
  Reset();
  }

G_MapMed::~G_MapMed() {
  }

void G_MapMed::Reset() {
  Int8 i;
  lastCellX = -99999999;
  lastCellY = -99999999;
  for (i=0; i<11; i++)
    strcpy(data[i],".....................");
  }

void G_MapMed::Display() {
  GotoXY(x,y+ 0); printf("                         ");
  GotoXY(x,y+ 1); printf(" +------west|----------+ ");
  GotoXY(x,y+ 2); printf(" |                     |n");
  GotoXY(x,y+ 3); printf(" |                     |o");
  GotoXY(x,y+ 4); printf(" |                     |r");
  GotoXY(x,y+ 5); printf(" |                     |t");
  GotoXY(x,y+ 6); printf(" |                     |h");
  GotoXY(x,y+ 7); printf("--                     --");
  GotoXY(x,y+ 8); printf("s|                     | ");
  GotoXY(x,y+ 9); printf("o|                     | ");
  GotoXY(x,y+10); printf("u|                     | ");
  GotoXY(x,y+11); printf("t|                     | ");
  GotoXY(x,y+12); printf("h|                     | ");
  GotoXY(x,y+13); printf(" +----------|east------+ ");
  }

void G_MapMed::Update() {
  Int32 i,j;
  Int32 cellX, cellY;
  cellX = map->Cell(currentVehicle->Longitude());
  cellY = map->Cell(currentVehicle->Latitude());
  if (cellX != lastCellX || cellY != lastCellY) {
    for (j=0; j<11; j++)
      for (i=0; i<21; i++)
        data[j][i] = map->Lurrain(cellX+j-5,cellY+i-10);
    lastCellX = cellX;
    lastCellY = cellY;
    cellX = map->Cell(lrv->Longitude()) - lastCellX;
    cellY = map->Cell(lrv->Latitude()) - lastCellY;
    if (cellX >= - 5 && cellX <= 5 && cellY >= -10 && cellY <= 10)
      data[cellX+5][cellY+10] = 'l';
    cellX = map->Cell(lm->Longitude()) - lastCellX;
    cellY = map->Cell(lm->Latitude()) - lastCellY;
    if (cellX >= - 5 && cellX <= 5 && cellY >= -10 && cellY <= 10)
      data[cellX+5][cellY+10] = 'm';
    data[5][10] = '@';
    for (i=0; i<11; i++) {
      GotoXY(x+2,y+i+2); printf("%s",data[i]);
      }
    }
  }

