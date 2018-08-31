#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_lmrock.h"
#include "terminal.h"
#include "common.h"

G_LmRock::G_LmRock(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 6;
  height = 1;
  Reset();
  }

G_LmRock::~G_LmRock() {
  }

void G_LmRock::Reset() {
  lastRock = -999;
  }

void G_LmRock::Display() {
  GotoXY(x,y+0); Write("RK:   ");
  }

void G_LmRock::Update() {
  char buffer[32];
  if (lm->Rock() != lastRock) {
    GotoXY(x+3,y); sprintf(buffer,"%3d",lm->Rock()); Write(buffer);
    lastRock = lm->Rock();
    }
  }

