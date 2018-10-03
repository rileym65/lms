#include "types.h"
#include "common.h"
#include "gauge.h"
#include "g_engines.h"
#include "terminal.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "booster.h"
#include "command.h"

G_Engines::G_Engines(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 3;
  height = 3;
  Reset();
  }

G_Engines::~G_Engines() {
  }

void G_Engines::Reset() {
  lastEnginesLit = 0xff;
  }

void G_Engines::Display() {
  Booster* lv;
  if ((vehicle->Type() & VT_COMMAND) == 0) return;
  lv = ((CommandModule*)vehicle)->LaunchVehicle();
  switch (lv->MaxEngines()) {
    case 1:
         GotoXY(x,y+0); Write("   ");
         GotoXY(x,y+1); Write(" O ");
         GotoXY(x,y+2); Write("   ");
         break;
    case 2:
         GotoXY(x,y+0); Write("O  ");
         GotoXY(x,y+1); Write("   ");
         GotoXY(x,y+2); Write("  O");
         break;
    case 3:
         GotoXY(x,y+0); Write("O  ");
         GotoXY(x,y+1); Write(" O ");
         GotoXY(x,y+2); Write("  O");
         break;
    case 4:
         GotoXY(x,y+0); Write("O O");
         GotoXY(x,y+1); Write("   ");
         GotoXY(x,y+2); Write("O O");
         break;
    case 5:
         GotoXY(x,y+0); Write("O O");
         GotoXY(x,y+1); Write(" O ");
         GotoXY(x,y+2); Write("O O");
         break;
    case 6:
         GotoXY(x,y+0); Write("OOO");
         GotoXY(x,y+1); Write("   ");
         GotoXY(x,y+2); Write("OOO");
         break;
    case 7:
         GotoXY(x,y+0); Write("OOO");
         GotoXY(x,y+1); Write(" O ");
         GotoXY(x,y+2); Write("OOO");
         break;
    case 8:
         GotoXY(x,y+0); Write("OOO");
         GotoXY(x,y+1); Write("O O");
         GotoXY(x,y+2); Write("OOO");
         break;
    }
  }

void G_Engines::Update() {
  Byte e;
  Byte c;
  c = vehicle->NumEngines();
  e = vehicle->EnginesLit();
  if (e != lastEnginesLit) {
    switch (c) {
      case 1:
           GotoXY(x+1,y+1);
           if (e & 1) Write("*"); else Write("O");
           break;
      case 2:
           GotoXY(x+0,y+0);
           if (e & 1) Write("*"); else Write("O");
           GotoXY(x+2,y+2);
           if (e & 2) Write("*"); else Write("O");
           break;
      case 3:
           GotoXY(x+1,y+1);
           if (e & 1) Write("*"); else Write("O");
           GotoXY(x+0,y+0);
           if (e & 2) Write("*"); else Write("O");
           GotoXY(x+2,y+2);
           if (e & 4) Write("*"); else Write("O");
           break;
      case 4:
           GotoXY(x+0,y+0);
           if (e & 1) Write("*"); else Write("O");
           GotoXY(x+2,y+0);
           if (e & 2) Write("*"); else Write("O");
           GotoXY(x+2,y+2);
           if (e & 4) Write("*"); else Write("O");
           GotoXY(x+0,y+2);
           if (e & 8) Write("*"); else Write("O");
           break;
      case 5:
           GotoXY(x+1,y+1);
           if (e & 1) Write("*"); else Write("O");
           GotoXY(x+0,y+0);
           if (e & 2) Write("*"); else Write("O");
           GotoXY(x+2,y+0);
           if (e & 4) Write("*"); else Write("O");
           GotoXY(x+2,y+2);
           if (e & 8) Write("*"); else Write("O");
           GotoXY(x+0,y+2);
           if (e & 16) Write("*"); else Write("O");
           break;
      case 6:
           GotoXY(x+0,y+0);
           if (e & 1) Write("*"); else Write("O");
           GotoXY(x+1,y+0);
           if (e & 2) Write("*"); else Write("O");
           GotoXY(x+2,y+0);
           if (e & 4) Write("*"); else Write("O");
           GotoXY(x+0,y+2);
           if (e & 8) Write("*"); else Write("O");
           GotoXY(x+1,y+2);
           if (e & 16) Write("*"); else Write("O");
           GotoXY(x+2,y+2);
           if (e & 32) Write("*"); else Write("O");
           break;
      case 7:
           GotoXY(x+0,y+0);
           if (e & 1) Write("*"); else Write("O");
           GotoXY(x+1,y+0);
           if (e & 2) Write("*"); else Write("O");
           GotoXY(x+2,y+0);
           if (e & 4) Write("*"); else Write("O");
           GotoXY(x+0,y+2);
           if (e & 8) Write("*"); else Write("O");
           GotoXY(x+1,y+2);
           if (e & 16) Write("*"); else Write("O");
           GotoXY(x+2,y+2);
           if (e & 32) Write("*"); else Write("O");
           GotoXY(x+1,y+1);
           if (e & 64) Write("*"); else Write("O");
           break;
      case 8:
           GotoXY(x+0,y+0);
           if (e & 1) Write("*"); else Write("O");
           GotoXY(x+1,y+0);
           if (e & 2) Write("*"); else Write("O");
           GotoXY(x+2,y+0);
           if (e & 4) Write("*"); else Write("O");
           GotoXY(x+0,y+2);
           if (e & 8) Write("*"); else Write("O");
           GotoXY(x+1,y+2);
           if (e & 16) Write("*"); else Write("O");
           GotoXY(x+2,y+2);
           if (e & 32) Write("*"); else Write("O");
           GotoXY(x+0,y+1);
           if (e & 64) Write("*"); else Write("O");
           GotoXY(x+2,y+1);
           if (e & 128) Write("*"); else Write("O");
           break;
      }
    lastEnginesLit = e;
    }
  }

