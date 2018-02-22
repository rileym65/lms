#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsclocks.h"
#include "terminal.h"

G_AmsClocks::G_AmsClocks(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
  Reset();
  width = 12;
  height = 7;
  }

G_AmsClocks::~G_AmsClocks() {
  }

void G_AmsClocks::displayClock(Int32 x, Int32 y, Int32 clock) {
  Int32 hours, minutes, seconds;
  hours = clock / 3600;
  clock -= (hours * 3600);
  minutes = clock / 60;
  seconds = clock - (minutes * 60);
  GotoXY(x, y);
  printf("%3d:%2d:%2d",hours,minutes,seconds);
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
  GotoXY(x,y+0); printf("      clocks");
  GotoXY(x,y+1); printf("UT:   :  :  ");
  GotoXY(x,y+2); printf("MI:   :  :  ");
  GotoXY(x,y+3); printf("BU:   :  :  ");
  GotoXY(x,y+4); printf("EV:   :  :  ");
  GotoXY(x,y+5); printf("DK:   :  :  ");
  GotoXY(x,y+6); printf("OR:   :  :  ");
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

