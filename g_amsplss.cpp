#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsplss.h"
#include "terminal.h"

G_AmsPlss::G_AmsPlss(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
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
  }

void G_AmsPlss::Display() {
  GotoXY(x,y+0); printf("  plss");
  GotoXY(x,y+1); printf("OXY:  ");
  GotoXY(x,y+2); printf("BAT:  ");
  GotoXY(x,y+3); printf("PAK:  ");
  }

void G_AmsPlss::Update() {
  Int32 i;
  i = (int)(plssOxygen / PLSS_OXYGEN * 100);
  if (i>99) i = 99;
  if (i != lastOxygen) {
    GotoXY(x+4,y+1); printf("%2d",i);
    lastOxygen = i;
    }
  i = (int)(plssBattery / PLSS_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastBattery) {
    GotoXY(x+4,y+2); printf("%2d",i);
    lastBattery = i;
    }
  if (plssPacks != lastPacks) {
    GotoXY(x+4,y+3);
    printf("%2d", plssPacks);
    lastPacks = plssPacks;
    }
  }

