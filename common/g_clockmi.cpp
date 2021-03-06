#include "types.h"
#include "gauge.h"
#include "g_clockmi.h"
#include "terminal.h"
#include "common.h"

G_ClockMI::G_ClockMI(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_ClockMI::~G_ClockMI() {
  }

void G_ClockMI::Reset() {
  lastClock = -9999;
  }

void G_ClockMI::Display() {
  GotoXY(x,y+0); Write("ME:   :  :  ");
  }

void G_ClockMI::Update() {
  if (clockMi != lastClock) {
    displayClock(x+3, y+0, clockMi);
    lastClock = clockMi;
    }
  }

