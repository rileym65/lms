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

void G_Clocks::displayClock(Int32 x, Int32 y, Int32 clock) {
  Int32 hours, minutes, seconds;
  hours = clock / 3600;
  clock -= (hours * 3600);
  minutes = clock / 60;
  seconds = clock - (minutes * 60);
  GotoXY(x, y);
  printf("%3d:%02d:%02d",hours,minutes,seconds);
  }

void G_Clocks::Reset() {
  lastClockUt = -9999;
  lastClockMi = -9999;
  lastClockBu = -9999;
  lastClockEv = -9999;
  lastClockDk = -9999;
  }

void G_Clocks::Display() {
  GotoXY(x,y+0); printf("UT:   :  :  ");
  GotoXY(x,y+1); printf("MI:   :  :  ");
  GotoXY(x,y+2); printf("BU:   :  :  ");
  GotoXY(x,y+3); printf("EV:   :  :  ");
  GotoXY(x,y+4); printf("DK:   :  :  ");
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

