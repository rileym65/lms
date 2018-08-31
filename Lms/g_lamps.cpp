#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_lamps.h"
#include "terminal.h"
#include "common.h"

G_Lamps::G_Lamps(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 20;
  height = 3;
  Reset();
  }

G_Lamps::~G_Lamps() {
  }

void G_Lamps::Reset() {
  }

void G_Lamps::Display() {
  GotoXY(x,y+0); Write("ASC ALO ATT OXY BAT ");
  GotoXY(x,y+1); Write("DSC DLO DCK EMG EMG ");
  GotoXY(x,y+2); Write("RCS RLO LCT ELO ELO ");
  }

void G_Lamps::Update() {
  GotoXY(x+0,y+0);
  if (lm->DescentJettisoned() && lm->Throttle() > 0)
    Write("ASC"); else Write("   ");
  GotoXY(x+0,y+1);
  if (!lm->DescentJettisoned() && lm->Throttle() > 0)
    Write("DSC"); else Write("   ");
  GotoXY(x+0,y+2);
  if (lm->RcsFbMode() != ' ' || lm->RcsLrMode() != ' ' ||
      lm->RcsUdMode() != ' ')
    Write("RCS"); else Write("   ");

  GotoXY(x+4,y+0);
  if (lm->AscentFuel() < (lm->MaxAscentFuel() * 0.10))
    Write("ALO"); else Write("   ");

  GotoXY(x+4,y+1);
  if (!lm->DescentJettisoned() && lm->DescentFuel() < (lm->MaxDescentFuel() * 0.10))
    Write("DLO"); else Write("   ");

  GotoXY(x+4,y+2);
  if (lm->RcsFuel() < (lm->MaxRcsFuel() * 0.10))
    Write("RLO"); else Write("   ");

  GotoXY(x+8,y+0);
  if (vehicle->PitchRate() != 0 || vehicle->RollRate() != 0 || vehicle->YawRate() != 0)
    Write("ATT"); else Write("   ");

  GotoXY(x+8,y+1);
  if (docked) Write("DCK"); else Write("   ");
  GotoXY(x+8,y+2);
  if (lm->Landed()) Write("LCT"); else Write("   ");

  if (!lm->DescentJettisoned()) {
    GotoXY(x+12,y+0);
    if (lm->Oxygen() < ((lm->MaxAscentOxygen() + lm->MaxDescentOxygen()) * 0.10))
      Write("OXY"); else Write("   ");
    GotoXY(x+16,y+0);
    if (lm->Battery() < ((lm->MaxAscentBattery() + lm->MaxDescentBattery()) * 0.10))
      Write("BAT"); else Write("   ");
    GotoXY(x+12,y+1);
    if (lm->Oxygen() <= 0.0)
      Write("EMG"); else Write("   ");
    GotoXY(x+16,y+1);
    if (lm->Battery() <= 0.0)
      Write("EMG"); else Write("   ");
    GotoXY(x+12,y+2);
    if (lm->EOxygen() < ((lm->MaxAscentEOxygen() + lm->MaxDescentEOxygen()) * 0.10))
      Write("ELO"); else Write("   ");
    GotoXY(x+16,y+2);
    if (lm->EBattery() < ((lm->MaxAscentEBattery() + lm->MaxDescentEBattery()) * 0.10))
      Write("ELO"); else Write("   ");
    }
  else {
    GotoXY(x+12,y+0);
    if (lm->Oxygen() < (lm->MaxAscentOxygen() * 0.10))
      Write("OXY"); else Write("   ");
    GotoXY(x+16,y+0);
    if (lm->Battery() < (lm->MaxAscentBattery() * 0.10))
      Write("BAT"); else Write("   ");
    GotoXY(x+12,y+1);
    if (lm->Oxygen() <= 0.0)
      Write("EMG"); else Write("   ");
    GotoXY(x+16,y+1);
    if (lm->Battery() <= 0.0)
      Write("EMG"); else Write("   ");
    GotoXY(x+12,y+2);
    if (lm->EOxygen() < (lm->MaxAscentEOxygen() * 0.10))
      Write("ELO"); else Write("   ");
    GotoXY(x+16,y+2);
    if (lm->EBattery() < (lm->MaxAscentEBattery() * 0.10))
      Write("ELO"); else Write("   ");
    }


  }

