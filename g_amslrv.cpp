#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amslrv.h"
#include "terminal.h"

G_AmsLrv::G_AmsLrv(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
  width = 6;
  height = 4;
  Reset();
  }

G_AmsLrv::~G_AmsLrv() {
  }

void G_AmsLrv::Reset() {
  lastBattery = -9999;
  lastSampleBoxes = -9999;
  lastRock = -9999;
  lastSetup = false;
  }

void G_AmsLrv::Display() {
  GotoXY(x,y+0); printf("   lrv");
  GotoXY(x,y+1); printf("BAT:  ");
  GotoXY(x,y+2); printf("BOX:  ");
  GotoXY(x,y+3); printf("ROK:  ");
  }

void G_AmsLrv::Update() {
  Int32 i;
  i = (int)(lrv->Battery() / LRV_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastBattery) {
    GotoXY(x+4,y+1); printf("%2d",i);
    lastBattery = i;
    }
  if (lrv->Boxes() != lastSampleBoxes) {
    GotoXY(x+4,y+2); printf("%2d",lrv->Boxes());
    lastSampleBoxes = lrv->Boxes();
    }
  if (lrv->Rock() != lastRock) {
    GotoXY(x+4,y+3); printf("%2d",lrv->Rock());
    lastRock = lrv->Rock();
    }
  if (lrv->IsSetup() != lastSetup) {
    GotoXY(x,y);
    if (lrv->IsSetup()) printf("^"); else printf(" ");
    lastSetup = lrv->IsSetup();
    }
  }

