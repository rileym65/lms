#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_plss.h"
#include "terminal.h"

G_Plss::G_Plss(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 6;
  height = 6;
  Reset();
  }

G_Plss::~G_Plss() {
  }

void G_Plss::Reset() {
  lastOxygen = -9999;
  lastBattery = -9999;
  lastCarrying = 0xff;
  lastEOxygen = -9999;
  lastEBattery = -9999;
  }

void G_Plss::Display() {
  GotoXY(x,y+0); printf("  plss");
  GotoXY(x,y+1); printf("OXY:  ");
  GotoXY(x,y+2); printf("BAT:  ");
  GotoXY(x,y+3); printf("EOX:  ");
  GotoXY(x,y+4); printf("EBT:  ");
  GotoXY(x,y+5); printf("CRY:  ");
  }

void G_Plss::Update() {
  Int32 i;
  i = (int)(plss->Oxygen() / PLSS_OXYGEN * 100);
  if (i>99) i = 99;
  if (i != lastOxygen) {
    GotoXY(x+4,y+1); printf("%2d",i);
    lastOxygen = i;
    }
  i = (int)(plss->Battery() / PLSS_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastBattery) {
    GotoXY(x+4,y+2); printf("%2d",i);
    lastBattery = i;
    }
  i = (int)(plss->EOxygen() / PLSS_EOXYGEN * 100);
  if (i>99) i = 99;
  if (i != lastEOxygen) {
    GotoXY(x+4,y+3); printf("%2d",i);
    lastEOxygen = i;
    }
  i = (int)(plss->EBattery() / PLSS_EBATTERY * 100);
  if (i>99) i = 99;
  if (i != lastEBattery) {
    GotoXY(x+4,y+4); printf("%2d",i);
    lastEBattery = i;
    }
  if (plss->Carrying() != lastCarrying) {
    GotoXY(x+5,y+5);
    lastCarrying = plss->Carrying();
    switch (lastCarrying) {
      case 'R':printf("S"); break;
      case 'B':printf("B"); break;
      case 'F':printf("F"); break;
      case 'L':printf("L"); break;
      default :printf("-"); break;
      }
    }
  }

