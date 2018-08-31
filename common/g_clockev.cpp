#include "types.h"
#include "gauge.h"
#include "common.h"
#include "g_clockev.h"
#include "terminal.h"

G_ClockEV::G_ClockEV(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_ClockEV::~G_ClockEV() {
  }

void G_ClockEV::Reset() {
  lastClock = -9999;
  }

void G_ClockEV::Display() {
  GotoXY(x,y+0); Write("EV:   :  :  ");
  }

void G_ClockEV::Update() {
  if (clockEv != lastClock) {
    displayClock(x+3, y+0, clockEv);
    lastClock = clockEv;
    }
  }

