#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_pilot.h"
#include "terminal.h"

G_Pilot::G_Pilot(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 6;
  height = 3;
  Reset();
  }

G_Pilot::~G_Pilot() {
  }

void G_Pilot::Reset() {
  lastMetabolicRate = -9999;
  lastEfficiency = -9999;
  lastInjury = -9999;
  }

void G_Pilot::Display() {
  GotoXY(x,y+0); Write("MB:   ");
  GotoXY(x,y+1); Write("EF:   ");
  GotoXY(x,y+2); Write("IN:   ");
  }

void G_Pilot::Update() {
  Int32 i;
  char buffer[32];
  i = (int)metabolicRate;
  if (i != lastMetabolicRate) {
    GotoXY(x+4,y+0);
    sprintf(buffer,"%2d",i);
    Write(buffer);
    lastMetabolicRate = i;
    }
  i = (int)efficiency;
  if (i != lastEfficiency) {
    GotoXY(x+4,y+1);
    sprintf(buffer,"%2d",i);
    Write(buffer);
    lastEfficiency = i;
    }
  i = (int)injury;
  if (i != lastInjury) {
    GotoXY(x+4,y+2);
    sprintf(buffer,"%2d",i);
    Write(buffer);
    lastInjury = i;
    }
  }

