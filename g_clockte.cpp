#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_clockte.h"
#include "terminal.h"

G_ClockTE::G_ClockTE(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_ClockTE::~G_ClockTE() {
  }

void G_ClockTE::Reset() {
  lastClock = -9999;
  }

void G_ClockTE::Display() {
  GotoXY(x,y+0); printf("TE:   :  :  ");
  }

void G_ClockTE::Update() {
  if (clockUt != lastClock) {
    displayClock(x+3, y+0, clockTe);
    lastClock = clockUt;
    }
  }

