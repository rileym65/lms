#include "types.h"
#include "gauge.h"
#include "g_amsclocks.h"
#include "terminal.h"
#include "common.h"

G_AmsClocks::G_AmsClocks(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 7;
  }

G_AmsClocks::~G_AmsClocks() {
  }

void G_AmsClocks::Reset() {
  lastClockUt = -9999;
  lastClockMi = -9999;
  lastClockBu = -9999;
  lastClockEv = -9999;
  lastClockDk = -9999;
  lastClockOr = -9999;
  }

void G_AmsClocks::Display() {
  GotoXY(x,y+0); Write("      clocks");
  GotoXY(x,y+1); Write("UT:   :  :  ");
  GotoXY(x,y+2); Write("MI:   :  :  ");
  GotoXY(x,y+3); Write("BU:   :  :  ");
  GotoXY(x,y+4); Write("EV:   :  :  ");
  GotoXY(x,y+5); Write("DK:   :  :  ");
  GotoXY(x,y+6); Write("OR:   :  :  ");
  }

void G_AmsClocks::Update() {
  if (clockUt != lastClockUt) {
    displayClock(x+3, y+1, clockUt);
    lastClockUt = clockUt;
    }
  if (clockMi != lastClockMi) {
    displayClock(x+3, y+2, clockMi);
    lastClockMi = clockMi;
    }
  if (clockBu != lastClockBu) {
    displayClock(x+3, y+3, clockBu);
    lastClockBu = clockBu;
    }
  if (clockEv != lastClockEv) {
    displayClock(x+3, y+4, clockEv);
    lastClockEv = clockEv;
    }
  if (clockDk != lastClockDk) {
    displayClock(x+3, y+5, clockDk);
    lastClockDk = clockDk;
    }
  if (clockOr != lastClockOr) {
    displayClock(x+3, y+6, clockOr);
    lastClockOr = clockOr;
    }
  }

