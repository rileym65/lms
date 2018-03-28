#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_lamps.h"
#include "terminal.h"

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
  GotoXY(x,y+0); printf("ASC ALO ATT OXY BAT ");
  GotoXY(x,y+1); printf("DSC DLO DCK EMG EMG ");
  GotoXY(x,y+2); printf("RCS RLO LCT ELO ELO ");
  }

void G_Lamps::Update() {
  GotoXY(x+0,y+0);
  if (lm->DescentJettisoned() && lm->Throttle() > 0)
    printf("ASC"); else printf("   ");
  GotoXY(x+0,y+1);
  if (!lm->DescentJettisoned() && lm->Throttle() > 0)
    printf("DSC"); else printf("   ");
  GotoXY(x+0,y+2);
  if (lm->RcsFbMode() != ' ' || lm->RcsLrMode() != ' ' ||
      lm->RcsUdMode() != ' ')
    printf("RCS"); else printf("   ");

  GotoXY(x+4,y+0);
  if (lm->AscentFuel() < (FUEL_ASC * 0.10))
    printf("ALO"); else printf("   ");

  GotoXY(x+4,y+1);
  if (!lm->DescentJettisoned() && lm->DescentFuel() < (FUEL_DES * 0.10))
    printf("DLO"); else printf("   ");

  GotoXY(x+4,y+2);
  if (lm->RcsFuel() < (FUEL_RCS * 0.10))
    printf("RLO"); else printf("   ");

  GotoXY(x+8,y+0);
  if (lm->PitchRate() != 0 || lm->RollRate() != 0 || lm->YawRate() != 0)
    printf("ATT"); else printf("   ");

  GotoXY(x+8,y+1);
  if (docked) printf("DCK"); else printf("   ");
  GotoXY(x+8,y+2);
  if (lm->Landed()) printf("LCT"); else printf("   ");

  if (!lm->DescentJettisoned()) {
    GotoXY(x+12,y+0);
    if (lm->Oxygen() < (LM_OXYGEN * 0.10))
      printf("OXY"); else printf("   ");
    GotoXY(x+16,y+0);
    if (lm->Battery() < (LM_BATTERY * 0.10))
      printf("BAT"); else printf("   ");
    GotoXY(x+12,y+1);
    if (lm->Oxygen() <= 0.0)
      printf("EMG"); else printf("   ");
    GotoXY(x+16,y+1);
    if (lm->Battery() <= 0.0)
      printf("EMG"); else printf("   ");
    GotoXY(x+12,y+2);
    if (lm->EOxygen() < (LM_EOXYGEN * 0.10))
      printf("ELO"); else printf("   ");
    GotoXY(x+16,y+2);
    if (lm->EBattery() < (LM_EBATTERY * 0.10))
      printf("ELO"); else printf("   ");
    }
  else {
    GotoXY(x+12,y+0);
    if (lm->Oxygen() < (ASC_OXYGEN * 0.10))
      printf("OXY"); else printf("   ");
    GotoXY(x+16,y+0);
    if (lm->Battery() < (ASC_BATTERY * 0.10))
      printf("BAT"); else printf("   ");
    GotoXY(x+12,y+1);
    if (lm->Oxygen() <= 0.0)
      printf("EMG"); else printf("   ");
    GotoXY(x+16,y+1);
    if (lm->Battery() <= 0.0)
      printf("EMG"); else printf("   ");
    GotoXY(x+12,y+2);
    if (lm->EOxygen() < (ASC_EOXYGEN * 0.10))
      printf("ELO"); else printf("   ");
    GotoXY(x+16,y+2);
    if (lm->EBattery() < (ASC_EBATTERY * 0.10))
      printf("ELO"); else printf("   ");
    }


  }

