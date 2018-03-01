#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_throttle.h"
#include "terminal.h"

G_Throttle::G_Throttle(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 7;
  height = 1;
  Reset();
  }

G_Throttle::~G_Throttle() {
  }

void G_Throttle::Reset() {
  lastThrottle = -999;
  }

void G_Throttle::Display() {
  GotoXY(x,y+0); printf("THR:   ");
  }

void G_Throttle::Update() {
  if (vehicle->Throttle() != lastThrottle) {
    GotoXY(x+5,y); printf("%2d",vehicle->Throttle());
    lastThrottle = lm->Throttle();
    }
  }

