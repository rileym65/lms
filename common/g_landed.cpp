#include "types.h"
#include "gauge.h"
#include "g_landed.h"
#include "terminal.h"
#include "common.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "lm.h"

G_Landed::G_Landed(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 3;
  height = 1;
  Reset();
  }

G_Landed::~G_Landed() {
  }

void G_Landed::Reset() {
  lastLanded = -999;
  }

void G_Landed::Display() {
  GotoXY(x,y+0); Write(" TD");
  }

void G_Landed::Update() {
  LunarModule* sc;
  if ((vehicle->Type() & VT_LANDER) == 0) return;
  sc = (LunarModule*)vehicle;
  if (sc->Landed() != lastLanded) {
    GotoXY(x+0,y+0);
    if (sc->Landed()) Write("^"); else Write(" ");
    lastLanded = sc->Landed();
    }
  }

