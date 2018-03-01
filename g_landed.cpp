#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_landed.h"
#include "terminal.h"

G_Landed::G_Landed(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 3;
  height = 1;
  Reset();
  }

G_Landed::~G_Landed() {
  }

void G_Landed::Reset() {
  lastLanded = -999;
  }

void G_Landed::Display() {
  GotoXY(x,y+0); printf(" TD");
  }

void G_Landed::Update() {
  if (lm->Landed() != lastLanded) {
    GotoXY(x+0,y+0);
    if (lm->Landed()) printf("^"); else printf(" ");
    lastLanded = lm->Landed();
    }
  }

