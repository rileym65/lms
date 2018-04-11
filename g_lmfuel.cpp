#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_lmfuel.h"
#include "terminal.h"

G_LmFuel::G_LmFuel(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 7;
  height = 2;
  Reset();
  }

G_LmFuel::~G_LmFuel() {
  }

void G_LmFuel::Reset() {
  lastAscentFuel = -9999;
  lastDescentFuel = -9999;
  }

void G_LmFuel::Display() {
  GotoXY(x,y+0); Write("ASC:   ");
  GotoXY(x,y+1); Write("DES:   ");
  }

void G_LmFuel::Update() {
  Int32 i;
  char buffer[32];
  i = (int)(lm->AscentFuel() / FUEL_ASC * 100);
  if (i>99) i = 99;
  if (i != lastAscentFuel) {
    GotoXY(x+5,y+0); sprintf(buffer,"%2d",i); Write(buffer);
    lastAscentFuel = i;
    }
  i = (int)(lm->DescentFuel() / FUEL_DES * 100);
  if (i>99) i = 99;
  if (i != lastDescentFuel) {
    GotoXY(x+5,y+1);
    if (!lm->DescentJettisoned()) {
      sprintf(buffer,"%2d",i); Write(buffer);
      }
      else Write("**");
    lastDescentFuel = i;
    }
  }

