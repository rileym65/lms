#include "types.h"
#include "gauge.h"
#include "g_clockbu.h"
#include "terminal.h"
#include "vehicle.h"

G_ClockBU::G_ClockBU(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_ClockBU::~G_ClockBU() {
  }

void G_ClockBU::Reset() {
  lastClock = -9999;
  }

void G_ClockBU::Display() {
  GotoXY(x,y+0); Write("BU:   :  :  ");
  }

void G_ClockBU::Update() {
  if (clockBu != lastClock) {
    displayClock(x+3, y+0, clockBu);
    lastClock = clockBu;
    }
  }

