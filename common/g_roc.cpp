#include "types.h"
#include "gauge.h"
#include "g_roc.h"
#include "terminal.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "common.h"

G_Roc::G_Roc(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Roc::~G_Roc() {
  }

void G_Roc::Reset() {
  lastAltitude = 0;
  }

void G_Roc::Display() {
  GotoXY(x,y); Write("Roc:-9999999");
  }

void G_Roc::Update() {
  char   buffer[16];
  Double d;
  if ((vehicle->Type() & VT_SPACECRAFT) == 0) return;
  d = ((Spacecraft*)vehicle)->RateOfClimb();
  if (d > 999999) d = 999999;
  if (d < -999999) d = -999999;
  sprintf(buffer,"%8.0f",d);
  GotoXY(x+4,y); Write(buffer);
  }

