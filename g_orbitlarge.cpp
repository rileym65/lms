#include "header.h"
#include "types.h"
#include "gauge.h"
#include "map.h"
#include "g_orbitlarge.h"
#include "terminal.h"

G_OrbitLarge::G_OrbitLarge(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 45;
  height = 23;
  Reset();
  }

G_OrbitLarge::~G_OrbitLarge() {
  }

void G_OrbitLarge::Reset() {
  Int8 i;
  lastCellX = -99999999;
  lastCellY = -99999999;
  for (i=0; i<19; i++)
    strcpy(data[i],".........................................");
  }

void G_OrbitLarge::Display() {
  GotoXY(x,y+ 0); printf("                                             ");
  GotoXY(x,y+ 1); printf(" +----------------west|--------------------+ ");
  GotoXY(x,y+ 2); printf(" |                                         | ");
  GotoXY(x,y+ 3); printf(" |                                         | ");
  GotoXY(x,y+ 4); printf(" |                                         | ");
  GotoXY(x,y+ 5); printf(" |                                         | ");
  GotoXY(x,y+ 6); printf(" |                                         |n");
  GotoXY(x,y+ 7); printf(" |                                         |o");
  GotoXY(x,y+ 8); printf(" |                                         |r");
  GotoXY(x,y+ 9); printf(" |                                         |t");
  GotoXY(x,y+10); printf(" |                                         |h");
  GotoXY(x,y+11); printf("--                                         --");
  GotoXY(x,y+12); printf("s|                                         | ");
  GotoXY(x,y+13); printf("o|                                         | ");
  GotoXY(x,y+14); printf("u|                                         | ");
  GotoXY(x,y+15); printf("t|                                         | ");
  GotoXY(x,y+16); printf("h|                                         | ");
  GotoXY(x,y+17); printf(" |                                         | ");
  GotoXY(x,y+18); printf(" |                                         | ");
  GotoXY(x,y+19); printf(" |                                         | ");
  GotoXY(x,y+20); printf(" |                                         | ");
  GotoXY(x,y+21); printf(" +--------------------|east----------------+ ");
  }

void G_OrbitLarge::Update() {
  Int32 i,j;
  Int32 cellX, cellY;
  cellX = (int)currentVehicle->Longitude();
  cellY = (int)currentVehicle->Latitude();
  if (cellX != lastCellX || cellY != lastCellY) {
    for (j=0; j<19; j++)
      for (i=0; i<41; i++)
        data[j][i] = map->CellH(cellX+j-9,cellY+i-20);
    lastCellX = cellX;
    lastCellY = cellY;

    for (i=0; i<19; i++) {
      GotoXY(x+2,y+i+2); printf("%s",data[i]);
      }
    }
  }

