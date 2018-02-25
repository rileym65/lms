#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amscons.h"
#include "terminal.h"

G_AmsCons::G_AmsCons(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
  width = 7;
  height = 7;
  Reset();
  }

G_AmsCons::~G_AmsCons() {
  }

void G_AmsCons::Reset() {
  lastAscentFuel = -9999;
  lastRcsFuel = -9999;
  lastDescentFuel = -9999;
  lastThrottle = -9999;
  lastRcsThrottle = -9999;
  lastOxygen = -9999;
  lastBattery = -9999;
  }

void G_AmsCons::Display() {
  GotoXY(x,y+0); printf(" consum");
  GotoXY(x,y+1); printf(" ASC:  ");
  GotoXY(x,y+2); printf(" RCS:  ");
  GotoXY(x,y+3); printf(" DES:  ");
  GotoXY(x,y+4); printf(" THR:  ");
  GotoXY(x,y+5); printf(" OXY:  ");
  GotoXY(x,y+6); printf(" BAT:  ");
  }

void G_AmsCons::Update() {
  Int32 i;
  i = (int)(lm->AscentFuel() / FUEL_ASC * 100);
  if (i>99) i = 99;
  if (i != lastAscentFuel) {
    GotoXY(x+5,y+1); printf("%2d",i);
    lastAscentFuel = i;
    }
  i = (int)(lm->RcsFuel() / FUEL_RCS * 100);
  if (i>99) i = 99;
  if (i != lastRcsFuel) {
    GotoXY(x+5,y+2); printf("%2d",i);
    lastRcsFuel = i;
    }
  i = (int)(lm->DescentFuel() / FUEL_DES * 100);
  if (i>99) i = 99;
  if (i != lastDescentFuel) {
    GotoXY(x+5,y+3);
    if (!lm->DescentJettisoned()) printf("%2d",i);
      else printf("**");
    lastDescentFuel = i;
    }
  i = lm->Throttle();
  i = currentVehicle->Throttle();
  if (i > 99) i = 99;
  if (i != lastThrottle) {
    GotoXY(x+5,y+4);
    if (!lm->DescentJettisoned()) printf("%2d",i);
      else printf("**");
    if (!lm->DescentJettisoned()) GotoXY(x,y+3); else GotoXY(x, y+1);
    if (i > 0 && pilotLocation == PILOT_LM) printf("^"); else printf(" ");
    lastThrottle = i;
    }
  i = (int)(lm->Oxygen() / LM_OXYGEN * 100);
  if (i>99) i = 99;
  if (i != lastOxygen) {
    GotoXY(x+5,y+5); printf("%2d",i);
    lastOxygen = i;
    }
  i = (int)(lm->Battery() / LM_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastBattery) {
    GotoXY(x+5,y+6); printf("%2d",i);
    lastBattery = i;
    }
  if (lm->RcsThrottle() != lastRcsThrottle) {
    GotoXY(x,y+2);
    switch (lm->RcsThrottle()) {
      case   1: printf("v"); break;
      case  10: printf(" "); break;
      case 100: printf("^"); break;
      }
    lastRcsThrottle = lm->RcsThrottle();
    }
  }

