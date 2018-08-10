#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_clockot.h"
#include "terminal.h"

G_ClockOT::G_ClockOT(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_ClockOT::~G_ClockOT() {
  }

void G_ClockOT::Reset() {
  lastClock = -9999;
  }

void G_ClockOT::Display() {
  GotoXY(x,y+0); Write("OT:   :  :  ");
  }

void G_ClockOT::Update() {
  if (clockUt != lastClock) {
    displayClock(x+3, y+0, vehicle->OrbitTime());
    lastClock = clockUt;
    }
  }

