#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amscons.h"
#include "terminal.h"

G_AmsCons::G_AmsCons(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
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
  GotoXY(x,y+0); Write(" consum");
  GotoXY(x,y+1); Write(" ASC:  ");
  GotoXY(x,y+2); Write(" RCS:  ");
  GotoXY(x,y+3); Write(" DES:  ");
  GotoXY(x,y+4); Write(" THR:  ");
  GotoXY(x,y+5); Write(" OXY:  ");
  GotoXY(x,y+6); Write(" BAT:  ");
  }

void G_AmsCons::Update() {
  Int32 i;
  char buffer[32];
  i = (int)(lm->AscentFuel() / FUEL_ASC * 100);
  if (i>99) i = 99;
  if (i != lastAscentFuel) {
    GotoXY(x+5,y+1); sprintf(buffer,"%2d",i); Write(buffer);
    lastAscentFuel = i;
    }
  i = (int)(lm->RcsFuel() / FUEL_RCS * 100);
  if (i>99) i = 99;
  if (i != lastRcsFuel) {
    GotoXY(x+5,y+2); sprintf(buffer,"%2d",i); Write(buffer);
    lastRcsFuel = i;
    }
  i = (int)(lm->DescentFuel() / FUEL_DES * 100);
  if (i>99) i = 99;
  if (i != lastDescentFuel) {
    GotoXY(x+5,y+3);
    if (!lm->DescentJettisoned()) {
      sprintf(buffer,"%2d",i);
      Write(buffer);
      }
      else Write("**");
    lastDescentFuel = i;
    }
  i = lm->Throttle();
  i = currentVehicle->Throttle();
  if (i > 99) i = 99;
  if (i != lastThrottle) {
    GotoXY(x+5,y+4);
    if (!lm->DescentJettisoned()) {
      sprintf(buffer,"%2d",i);
      Write(buffer);
      }
      else Write("**");
    if (!lm->DescentJettisoned()) GotoXY(x,y+3); else GotoXY(x, y+1);
    if (i > 0 && pilotLocation == PILOT_LM) Write("^"); else Write(" ");
    lastThrottle = i;
    }
  i = (int)(lm->Oxygen() / (LM_ASC_OXYGEN + LM_DSC_OXYGEN) * 100);
  if (i>99) i = 99;
  if (i != lastOxygen) {
    GotoXY(x+5,y+5); sprintf(buffer,"%2d",i); Write(buffer);
    lastOxygen = i;
    }
  i = (int)(lm->Battery() / (LM_ASC_BATTERY + LM_DSC_BATTERY) * 100);
  if (i>99) i = 99;
  if (i != lastBattery) {
    GotoXY(x+5,y+6); sprintf(buffer,"%2d",i); Write(buffer);
    lastBattery = i;
    }
  if (lm->RcsThrottle() != lastRcsThrottle) {
    GotoXY(x,y+2);
    switch (lm->RcsThrottle()) {
      case   1: Write("v"); break;
      case  10: Write(" "); break;
      case 100: Write("^"); break;
      }
    lastRcsThrottle = lm->RcsThrottle();
    }
  }

