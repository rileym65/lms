#include "types.h"
#include "gauge.h"
#include "g_plss.h"
#include "terminal.h"
#include "common.h"
#include "vehicle.h"

G_Plss::G_Plss(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 6;
  height = 6;
  Reset();
  }

G_Plss::~G_Plss() {
  }

void G_Plss::Reset() {
  lastCart = 9999;
  lastOxygen = -9999;
  lastBattery = -9999;
  lastCarrying = 0xff;
  lastEOxygen = -9999;
  lastEBattery = -9999;
  }

void G_Plss::Display() {
  GotoXY(x,y+0); Write("  plss");
  GotoXY(x,y+1); Write("OXY:  ");
  GotoXY(x,y+2); Write("BAT:  ");
  GotoXY(x,y+3); Write("      ");
  GotoXY(x,y+4); Write("CRT:  ");
  GotoXY(x,y+5); Write("CRY:  ");
  }

void G_Plss::Update() {
  Int32 i;
  char buffer[32];
  i = (int)(plss->Oxygen() / PLSS_OXYGEN * 100);
  if (i>99) i = 99;
  if (i != lastOxygen) {
    GotoXY(x+4,y+1); sprintf(buffer,"%2d",i); Write(buffer);
    lastOxygen = i;
    }
  i = (int)(plss->Battery() / PLSS_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastBattery) {
    GotoXY(x+4,y+2); sprintf(buffer,"%2d",i); Write(buffer);
    lastBattery = i;
    }
  i = (int)(plss->EOxygen() / PLSS_EOXYGEN * 100);
  if (i>99) i = 99;
  if (i != lastEOxygen && plss->Oxygen() <= 0.0) {
    GotoXY(x,y+3); sprintf(buffer,"EOX:%2d",i); Write(buffer);
    lastEOxygen = i;
    }
  i = (int)(plss->EBattery() / PLSS_EBATTERY * 100);
  if (i>99) i = 99;
  if (i != lastEBattery && plss->Battery() <= 0.0) {
    GotoXY(x,y+4); sprintf(buffer,"EBT:%2d",i); Write(buffer);
    lastEBattery = i;
    }
  if (plss->Cart() != lastCart) {
    GotoXY(x+4,y+4); sprintf(buffer,"%2d",plss->Cart()); Write(buffer);
    lastCart = plss->Cart();
    }
  if (plss->Carrying() != lastCarrying) {
    GotoXY(x+5,y+5);
    lastCarrying = plss->Carrying();
    switch (lastCarrying) {
      case 'R':Write("S"); break;
      case 'B':Write("B"); break;
      case 'F':Write("F"); break;
      case 'L':Write("L"); break;
      case 'A':Write("A"); break;
      default :Write("-"); break;
      }
    }
  }

