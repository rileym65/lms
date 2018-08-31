#include "types.h"
#include "gauge.h"
#include "common.h"
#include "g_days.h"
#include "terminal.h"
#include "vehicle.h"

G_Days::G_Days(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Days::~G_Days() {
  }

void G_Days::Reset() {
  lastDay = 9999;
  }

void G_Days::Display() {
  GotoXY(x,y+0); Write("DY:         ");
  }

void G_Days::Update() {
  char buffer[20];
  if (days != lastDay) {
    sprintf(buffer,"%8d",days);
    GotoXY(x+4,y+0); Write(buffer);
    lastDay = days;
    }
  }

