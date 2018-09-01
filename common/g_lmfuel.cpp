#include "types.h"
#include "gauge.h"
#include "g_lmfuel.h"
#include "terminal.h"
#include "common.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "lm.h"

G_LmFuel::G_LmFuel(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 7;
  height = 2;
  Reset();
  }

G_LmFuel::~G_LmFuel() {
  }

void G_LmFuel::Reset() {
  lastAscentFuel = -9999;
  lastDescentFuel = -9999;
  lastDescentJettisoned = 5;
  }

void G_LmFuel::Display() {
  GotoXY(x,y+0); Write("ASC:   ");
  GotoXY(x,y+1); Write("DSC:   ");
  }

void G_LmFuel::Update() {
  Int32 i;
  char buffer[32];
  LunarModule* v;
  if ((vehicle->Type() & VT_LANDER) == 0) return;
  v = (LunarModule*)vehicle;
  i = (int)(v->AscentFuel() / v->MaxAscentFuel() * 100);
  if (i>99) i = 99;
  if (i != lastAscentFuel) {
    GotoXY(x+5,y+0); sprintf(buffer,"%2d",i); Write(buffer);
    lastAscentFuel = i;
    }
  i = (int)(v->DescentFuel() / v->MaxDescentFuel() * 100);
  if (i>99) i = 99;
  if (i != lastDescentFuel || lastDescentJettisoned != v->DescentJettisoned()) {
    GotoXY(x+5,y+1);
    if (!v->DescentJettisoned()) {
      sprintf(buffer,"%2d",i); Write(buffer);
      }
      else Write("**");
    lastDescentFuel = i;
    lastDescentJettisoned = v->DescentJettisoned();
    }
  }

