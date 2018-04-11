#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsland.h"
#include "terminal.h"

G_AmsLand::G_AmsLand(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 13;
  height = 8;
  Reset();
  }

G_AmsLand::~G_AmsLand() {
  }

void G_AmsLand::Reset() {
  Int8 i;
  lastMode = ' ';
  lastLongitude = -9999;
  lastLatitude = -9999;
  for (i=0; i<5; i++)
    strcpy(data[i],".........");
  }

void G_AmsLand::Display() {
  GotoXY(x,y+0); Write("    land     ");
  GotoXY(x,y+1); Write(" +---w|----+ ");
  GotoXY(x,y+2); Write(" |         | ");
  GotoXY(x,y+3); Write(" |         |n");
  GotoXY(x,y+4); Write("--         --");
  GotoXY(x,y+5); Write("s|         | ");
  GotoXY(x,y+6); Write(" |         | ");
  GotoXY(x,y+7); Write(" +----|e---+ ");
  }

void G_AmsLand::Update() {
  Int32  i;
  Int32  ix,iy;
  Double alt;
  Int32  lng;
  Int32  lat;
  char   mode;
  char   buffer[32];
  lat = (int)currentVehicle->Latitude();
  lng = (int)currentVehicle->Longitude();
  alt = currentVehicle->Altitude();
  if (alt < 12000) mode = 'L';
  else if (alt < 20000) mode = 'M';
  else mode = 'H';
  if (mode != lastMode || lat != lastLatitude || lng != lastLongitude) {
    for (ix=-2; ix<=2; ix++)
      for (iy=-4; iy <= 4; iy++) {
        data[ix+2][iy+4] = map->CellH(lng+ix,lat+iy);
        }
    for (i=0; i<5; i++) {
      GotoXY(x+2, y+2+i);
      sprintf(buffer,"%s",data[i]);
      Write(buffer);
      }
    lastMode = mode;
    lastLatitude = lat;
    lastLongitude = lng;
    }
  if (landingRadarOn && alt < 18000 && ins->AttUr() <= 60) {
    if (lm->VelocityAltitude() <= -3) {
      GotoXY(x+1,y+2); Write("+");
      GotoXY(x+11,y+2); Write("+");
      }
    else {
      GotoXY(x+1,y+2); Write("|");
      GotoXY(x+11,y+2); Write("|");
      }
    GotoXY(x+10,y+1);
    if (lm->VelocityEast() < -0.2) Write("^"); else Write("-");
    GotoXY(x+10,y+7);
    if (lm->VelocityEast() > 0.2) Write("v"); else Write("-");
    GotoXY(x+11,y+6);
    if (lm->VelocityNorth() > 0.2) Write(">"); else Write("|");
    GotoXY(x+1,y+6);
    if (lm->VelocityNorth() < -0.2) Write("<"); else Write("|");
    }
  else {
    GotoXY(x+1,y+2); Write("|");
    GotoXY(x+11,y+2); Write("|");
    GotoXY(x+10,y+1); Write("-");
    GotoXY(x+10,y+7); Write("-");
    GotoXY(x+11,y+6); Write("|");
    GotoXY(x+1,y+6); Write("|");
    }
  }

