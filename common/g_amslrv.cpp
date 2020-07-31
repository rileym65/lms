#include "types.h"
#include "gauge.h"
#include "g_amslrv.h"
#include "terminal.h"
#include "common.h"
#include "vehicle.h"
#include "groundvehicle.h"
#include "lrv.h"

G_AmsLrv::G_AmsLrv(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
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
  GotoXY(x,y+0); Write("   lrv");
  GotoXY(x,y+1); Write("BAT:  ");
  GotoXY(x,y+2); Write("BOX:  ");
  GotoXY(x,y+3); Write("RK:   ");
  }

void G_AmsLrv::Update() {
  Int32 i;
  char buffer[32];
  i = (int)(lrv->Battery() / lrv->MaxBattery() * 100);
  if (i>99) i = 99;
  if (i != lastBattery) {
    GotoXY(x+4,y+1); sprintf(buffer,"%2d",i); Write(buffer);
    lastBattery = i;
    }
  if (lrv->Boxes() != lastSampleBoxes) {
    GotoXY(x+4,y+2); sprintf(buffer,"%2d",lrv->Boxes()); Write(buffer);
    lastSampleBoxes = lrv->Boxes();
    }
  if (lrv->Rock() != lastRock) {
    i = lrv->Rock();
    GotoXY(x+3,y+3); sprintf(buffer,"%3d",i); Write(buffer);
    lastRock = lrv->Rock();
    }
  if (lrv->IsSetup() != lastSetup) {
    GotoXY(x,y);
    if (lrv->IsSetup()) Write("^"); else Write(" ");
    lastSetup = lrv->IsSetup();
    }
  }

