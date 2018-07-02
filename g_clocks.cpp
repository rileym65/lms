#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_clocks.h"
#include "terminal.h"

G_Clocks::G_Clocks(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 6;
  }

G_Clocks::~G_Clocks() {
  }

void G_Clocks::Reset() {
  lastClockUt = -9999;
  lastClockMi = -9999;
  lastClockBu = -9999;
  lastClockEv = -9999;
  lastClockDk = -9999;
  }

void G_Clocks::Display() {
  GotoXY(x,y+0); Write("UT:   :  :  ");
  GotoXY(x,y+1); Write("ME:   :  :  ");
  GotoXY(x,y+2); Write("BU:   :  :  ");
  GotoXY(x,y+3); Write("EV:   :  :  ");
  GotoXY(x,y+4); Write("DK:   :  :  ");
  }

void G_Clocks::Update() {
  if (clockUt != lastClockUt) {
    displayClock(x+3, y+0, clockUt);
    lastClockUt = clockUt;
    }
  if (clockMi != lastClockMi) {
    displayClock(x+3, y+1, clockMi);
    lastClockMi = clockMi;
    }
  if (clockBu != lastClockBu) {
    displayClock(x+3, y+2, clockBu);
    lastClockBu = clockBu;
    }
  if (clockEv != lastClockEv) {
    displayClock(x+3, y+3, clockEv);
    lastClockEv = clockEv;
    }
  if (clockDk != lastClockDk) {
    displayClock(x+3, y+4, clockDk);
    lastClockDk = clockDk;
    }
  }

