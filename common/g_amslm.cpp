#include "types.h"
#include "gauge.h"
#include "g_amslm.h"
#include "terminal.h"
#include "common.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "lm.h"

G_AmsLm::G_AmsLm(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 6;
  height = 4;
  Reset();
  }

G_AmsLm::~G_AmsLm() {
  }

void G_AmsLm::Reset() {
  lastRock = -9999;
  }

void G_AmsLm::Display() {
  GotoXY(x,y+0); Write("    lm");
  GotoXY(x,y+1); Write("--:   ");
  GotoXY(x,y+2); Write("--:   ");
  GotoXY(x,y+3); Write("RK:   ");
  }

void G_AmsLm::Update() {
  char buffer[32];
  if ((vehicle->Type() & VT_LANDER) == 0) return;
  if (((LunarModule*)lm)->Rock() != lastRock) {
    GotoXY(x+3,y+3); sprintf(buffer,"%3d",((LunarModule*)lm)->Rock()); Write(buffer);
    lastRock = ((LunarModule*)lm)->Rock();
    }
  }

