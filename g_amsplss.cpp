#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsplss.h"
#include "terminal.h"

G_AmsPlss::G_AmsPlss(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 6;
  height = 4;
  Reset();
  }

G_AmsPlss::~G_AmsPlss() {
  }

void G_AmsPlss::Reset() {
  lastOxygen = -9999;
  lastBattery = -9999;
  lastPacks = -9999;
  lastCarrying = 0xff;
  }

void G_AmsPlss::Display() {
  GotoXY(x,y+0); Write("  plss");
  GotoXY(x,y+1); Write("OXY:  ");
  GotoXY(x,y+2); Write("BAT:  ");
  GotoXY(x,y+3); Write("PAK:  ");
  }

void G_AmsPlss::Update() {
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
  if (plssPacks != lastPacks) {
    GotoXY(x+4,y+3);
    sprintf(buffer,"%2d", plssPacks); Write(buffer);
    lastPacks = plssPacks;
    }
  if (plss->Carrying() != lastCarrying) {
    GotoXY(x,y);
    lastCarrying = plss->Carrying();
    switch (lastCarrying) {
      case 'R':Write("^"); break;
      case 'B':Write("v"); break;
      case 'F':Write("F"); break;
      default :Write(" "); break;
      }
    }
  }

