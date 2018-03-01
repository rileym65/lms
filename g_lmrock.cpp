#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_lmrock.h"
#include "terminal.h"

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
  GotoXY(x,y+0); printf("RK:   ");
  }

void G_LmRock::Update() {
  if (lm->Rock() != lastRock) {
    GotoXY(x+3,y); printf("%3d",lm->Rock());
    lastRock = lm->Rock();
    }
  }

