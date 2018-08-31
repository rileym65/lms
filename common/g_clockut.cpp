#include "types.h"
#include "gauge.h"
#include "common.h"
#include "g_clockut.h"
#include "terminal.h"

G_ClockUT::G_ClockUT(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_ClockUT::~G_ClockUT() {
  }

void G_ClockUT::Reset() {
  lastClock = -9999;
  }

void G_ClockUT::Display() {
  GotoXY(x,y+0); Write("UT:   :  :  ");
  }

void G_ClockUT::Update() {
  if (clockUt != lastClock) {
    displayClock(x+3, y+0, clockUt);
    lastClock = clockUt;
    }
  }

