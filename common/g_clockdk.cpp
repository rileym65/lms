#include "types.h"
#include "gauge.h"
#include "common.h"
#include "g_clockdk.h"
#include "terminal.h"

G_ClockDK::G_ClockDK(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_ClockDK::~G_ClockDK() {
  }

void G_ClockDK::Reset() {
  lastClock = -9999;
  }

void G_ClockDK::Display() {
  GotoXY(x,y+0); Write("DK:   :  :  ");
  }

void G_ClockDK::Update() {
  if (clockUt != lastClock) {
    displayClock(x+3, y+0, clockDk);
    lastClock = clockDk;
    }
  }

