#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsspin.h"
#include "terminal.h"

G_AmsSpin::G_AmsSpin(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 6;
  height = 4;
  Reset();
  }

G_AmsSpin::~G_AmsSpin() {
  }

void G_AmsSpin::Reset() {
  lastPitchRate = -9999;
  lastRollRate = -9999;
  lastYawRate = -9999;
  }

void G_AmsSpin::Display() {
  GotoXY(x,y+0); printf("  spin");
  GotoXY(x,y+1); printf("PIT:  ");
  GotoXY(x,y+2); printf("ROL:  ");
  GotoXY(x,y+3); printf("YAW:  ");
  }

void G_AmsSpin::Update() {
  int i;
  i = (int)(lm->PitchRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastPitchRate) {
    GotoXY(x+4, y+1);
    printf("%2d",i);
    lastPitchRate = i;
    }
  i = (int)(lm->RollRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastRollRate) {
    GotoXY(x+4, y+2);
    printf("%2d",i);
    lastRollRate = i;
    }
  if (pilotLocation == PILOT_LM) i = (int)(lm->YawRate());
  if (pilotLocation == PILOT_EVA) i = (int)(plss->TurnRate());
  if (pilotLocation == PILOT_LRV) i = (int)(lrv->TurnRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastYawRate) {
    GotoXY(x+4, y+3);
    printf("%2d",i);
    lastYawRate = i;
    }
  }

