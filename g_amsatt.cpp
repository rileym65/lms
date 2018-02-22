#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsatt.h"
#include "terminal.h"

G_AmsAtt::G_AmsAtt(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
  width = 7;
  height = 4;
  Reset();
  }

G_AmsAtt::~G_AmsAtt() {
  }

void G_AmsAtt::Reset() {
  lastUr = -9999;
  lastFr = -9999;
  lastLs = -9999;
  }

void G_AmsAtt::Display() {
  GotoXY(x,y+0); printf("    att");
  GotoXY(x,y+1); printf("u/r:   ");
  GotoXY(x,y+2); printf("f/r:   ");
  GotoXY(x,y+3); printf("l/s:   ");
  }

void G_AmsAtt::Update() {
  Int32 i;
  i = (int)(ins->AttUr()+.4);
  if (lastUr != i) {
    GotoXY(x+4, y+1); printf("%3d",i);
    lastUr = i;
    }
  i = (int)(ins->AttFr()+.4);
  if (lastFr != i) {
    GotoXY(x+4, y+2); printf("%3d",i);
    lastFr = i;
    }
  i = (int)(ins->AttLs()+.4);
  if (lastLs != i) {
    GotoXY(x+4, y+3); printf("%3d",i);
    lastLs = i;
    }
  }

