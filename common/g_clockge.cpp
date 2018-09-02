#include "types.h"
#include "gauge.h"
#include "g_clockge.h"
#include "terminal.h"
#include "common.h"

G_ClockGE::G_ClockGE(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_ClockGE::~G_ClockGE() {
  }

void G_ClockGE::Reset() {
  lastClock = -9999;
  }

void G_ClockGE::Display() {
  GotoXY(x,y+0); Write("GE:   :  :  ");
  }

void G_ClockGE::Update() {
  if (clockGe != lastClock) {
    displayClock(x+3, y+0, clockGe);
    lastClock = clockGe;
    }
  }

