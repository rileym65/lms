#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_oxybat.h"
#include "terminal.h"

G_OxyBat::G_OxyBat(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 7;
  height = 2;
  Reset();
  }

G_OxyBat::~G_OxyBat() {
  }

void G_OxyBat::Reset() {
  lastOxygen = -9999;
  lastBattery = -9999;
  }

void G_OxyBat::Display() {
  GotoXY(x,y+0); printf("OXY:   ");
  GotoXY(x,y+1); printf("BAT:   ");
  }

void G_OxyBat::Update() {
  Int32 i;
  i = (int)(vehicle->Oxygen() / vehicle->MaxOxygen() * 100);
  if (i>99) i = 99;
  if (i != lastOxygen) {
    GotoXY(x+5,y+0); printf("%2d",i);
    lastOxygen = i;
    }
  i = (int)(vehicle->Battery() / vehicle->MaxBattery() * 100);
  if (i>99) i = 99;
  if (i != lastBattery) {
    GotoXY(x+5,y+1); printf("%2d",i);
    lastBattery = i;
    }
  }

