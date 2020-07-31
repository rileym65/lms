#include "types.h"
#include "gauge.h"
#include "g_lrv.h"
#include "terminal.h"
#include "common.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "lrv.h"

G_Lrv::G_Lrv(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 6;
  height = 4;
  Reset();
  }

G_Lrv::~G_Lrv() {
  }

void G_Lrv::Reset() {
  lastOxygen = -9999;
  lastBattery = -9999;
  lastSampleBoxes = -9999;
  lastRock = -9999;
  lastSetup = false;
  }

void G_Lrv::Display() {
  GotoXY(x,y+0); Write("   lrv");
  GotoXY(x,y+1); Write("OXY:--");
  GotoXY(x,y+2); Write("BAT:  ");
  GotoXY(x,y+3); Write("BOX:  ");
  GotoXY(x,y+4); Write("RK:   ");
  }

void G_Lrv::Update() {
  Int32 i;
  char buffer[32];
  if (lrv->MaxOxygen() > 0) {
    i = (int)(lrv->Oxygen() / lrv->MaxOxygen() * 100);
    if (i > 99) i = 99;
    if (i != lastOxygen) {
      GotoXY(x+4,y+1); sprintf(buffer,"%2d",i); Write(buffer);
      lastOxygen = i;
      }
    }
  i = (int)(lrv->Battery() / lrv->MaxBattery() * 100);
  if (i>99) i = 99;
  if (i != lastBattery) {
    GotoXY(x+4,y+2); sprintf(buffer,"%2d",i); Write(buffer);
    lastBattery = i;
    }
  if (lrv->Boxes() != lastSampleBoxes) {
    GotoXY(x+4,y+3); sprintf(buffer,"%2d",lrv->Boxes()); Write(buffer);
    lastSampleBoxes = lrv->Boxes();
    }
  if (lrv->Rock() != lastRock) {
    i = lrv->Rock();
    GotoXY(x+3,y+4); sprintf(buffer,"%3d",i); Write(buffer);
    lastRock = lrv->Rock();
    }
  if (lrv->IsSetup() != lastSetup) {
    GotoXY(x,y);
    if (lrv->IsSetup()) Write("^"); else Write(" ");
    lastSetup = lrv->IsSetup();
    }
  }

