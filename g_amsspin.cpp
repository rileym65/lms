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
  GotoXY(x,y+0); Write("  spin");
  GotoXY(x,y+1); Write("PIT:  ");
  GotoXY(x,y+2); Write("ROL:  ");
  GotoXY(x,y+3); Write("YAW:  ");
  }

void G_AmsSpin::Update() {
  int i;
  char buffer[32];
  i = (int)(lm->PitchRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastPitchRate) {
    GotoXY(x+4, y+1);
    sprintf(buffer,"%2d",i);
    Write(buffer);
    lastPitchRate = i;
    }
  i = (int)(lm->RollRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastRollRate) {
    GotoXY(x+4, y+2);
    sprintf(buffer,"%2d",i);
    Write(buffer);
    lastRollRate = i;
    }
  if (pilotLocation == PILOT_LM) i = (int)(lm->YawRate());
  if (pilotLocation == PILOT_EVA) i = (int)(plss->TurnRate());
  if (pilotLocation == PILOT_LRV) i = (int)(lrv->TurnRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastYawRate) {
    GotoXY(x+4, y+3);
    sprintf(buffer,"%2d",i);
    Write(buffer);
    lastYawRate = i;
    }
  }

