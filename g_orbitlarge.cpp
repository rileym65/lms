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

void G_OrbitLarge::Update() {
  Int32 i,j;
  Int32 cellX, cellY;
  char buffer[80];
  cellX = (int)currentVehicle->Longitude();
  cellY = (int)currentVehicle->Latitude();
  if (cellX != lastCellX || cellY != lastCellY) {
    for (j=0; j<19; j++)
      for (i=0; i<41; i++)
        data[j][i] = map->CellH(cellX+j-9,cellY+i-20);
    lastCellX = cellX;
    lastCellY = cellY;

    for (i=0; i<19; i++) {
      GotoXY(x+2,y+i+2); sprintf(buffer,"%s",data[i]); Write(buffer);
      }
    }
  }

