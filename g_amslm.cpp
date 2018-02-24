#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amslm.h"
#include "terminal.h"

G_AmsLm::G_AmsLm(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
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
  GotoXY(x,y+0); printf("    lm");
  GotoXY(x,y+1); printf("--:   ");
  GotoXY(x,y+2); printf("--:   ");
  GotoXY(x,y+3); printf("RK:   ");
  }

void G_AmsLm::Update() {
  if (lm->Rock() != lastRock) {
    GotoXY(x+3,y+3); printf("%3d",lm->Rock());
    lastRock = lm->Rock();
    }
  }

