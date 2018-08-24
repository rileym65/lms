#include "types.h"
#include "gauge.h"
#include "g_clocktb.h"
#include "terminal.h"
#include "vehicle.h"

G_ClockTB::G_ClockTB(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_ClockTB::~G_ClockTB() {
  }

void G_ClockTB::Reset() {
  lastClock = -9999;
  }

void G_ClockTB::Display() {
  GotoXY(x,y+0); Write("TB:   :  :  ");
  }

void G_ClockTB::Update() {
  if (clockTb != lastClock) {
    displayClock(x+3, y+0, clockTb);
    lastClock = clockTb;
    }
  }

