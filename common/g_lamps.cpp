#include "types.h"
#include "gauge.h"
#include "g_lamps.h"
#include "terminal.h"
#include "common.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "lm.h"

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
  Spacecraft* sc;
  LunarModule* lem;
  GotoXY(x+8,y+1);
  if (docked) Write("DCK"); else Write("   ");

  GotoXY(x+8,y+0);
  if (vehicle->PitchRate() != 0 || vehicle->RollRate() != 0 || vehicle->YawRate() != 0)
    Write("ATT"); else Write("   ");

  if ((vehicle->Type() & VT_SPACECRAFT) == 0) return;
  sc = (Spacecraft*)vehicle;
  lem = (LunarModule*)vehicle;

  GotoXY(x+0,y+2);
  if (sc->RcsFbMode() != ' ' || sc->RcsLrMode() != ' ' ||
      sc->RcsUdMode() != ' ')
    Write("RCS"); else Write("   ");

  GotoXY(x+4,y+2);
  if (sc->RcsFuel() < (sc->MaxRcsFuel() * 0.10))
    Write("RLO"); else Write("   ");

  if ((vehicle->Type() & VT_LANDER) != 0) {
    GotoXY(x+0,y+0);
    if (lem->DescentJettisoned() && lem->Throttle() > 0)
      Write("ASC"); else Write("   ");
    GotoXY(x+0,y+1);
    if (!lem->DescentJettisoned() && lem->Throttle() > 0)
      Write("DSC"); else Write("   ");
    GotoXY(x+4,y+0);
    if (lem->AscentFuel() < (lem->MaxAscentFuel() * 0.10))
      Write("ALO"); else Write("   ");
    GotoXY(x+4,y+1);
    if (!lem->DescentJettisoned() && lem->DescentFuel() < (lem->MaxDescentFuel() * 0.10))
      Write("DLO"); else Write("   ");
    GotoXY(x+8,y+2);
    if (lem->Landed()) Write("LCT"); else Write("   ");
    if (!lem->DescentJettisoned()) {
      GotoXY(x+12,y+0);
      if (sc->Oxygen() < ((lem->MaxAscentOxygen() + lem->MaxDescentOxygen()) * 0.10))
        Write("OXY"); else Write("   ");
      GotoXY(x+16,y+0);
      if (sc->Battery() < ((lem->MaxAscentBattery() + lem->MaxDescentBattery()) * 0.10))
        Write("BAT"); else Write("   ");
      GotoXY(x+12,y+1);
      if (sc->Oxygen() <= 0.0)
        Write("EMG"); else Write("   ");
      GotoXY(x+16,y+1);
      if (sc->Battery() <= 0.0)
        Write("EMG"); else Write("   ");
      GotoXY(x+12,y+2);
      if (sc->EOxygen() < ((lem->MaxAscentEOxygen() + lem->MaxDescentEOxygen()) * 0.10))
        Write("ELO"); else Write("   ");
      GotoXY(x+16,y+2);
      if (sc->EBattery() < ((lem->MaxAscentEBattery() + lem->MaxDescentEBattery()) * 0.10))
        Write("ELO"); else Write("   ");
      }
    else {
      GotoXY(x+12,y+0);
      if (sc->Oxygen() < (lem->MaxAscentOxygen() * 0.10))
        Write("OXY"); else Write("   ");
      GotoXY(x+16,y+0);
      if (sc->Battery() < (lem->MaxAscentBattery() * 0.10))
        Write("BAT"); else Write("   ");
      GotoXY(x+12,y+1);
      if (sc->Oxygen() <= 0.0)
        Write("EMG"); else Write("   ");
      GotoXY(x+16,y+1);
      if (sc->Battery() <= 0.0)
        Write("EMG"); else Write("   ");
      GotoXY(x+12,y+2);
      if (sc->EOxygen() < (lem->MaxAscentEOxygen() * 0.10))
        Write("ELO"); else Write("   ");
      GotoXY(x+16,y+2);
      if (sc->EBattery() < (lem->MaxAscentEBattery() * 0.10))
        Write("ELO"); else Write("   ");
      }
    }


  }

