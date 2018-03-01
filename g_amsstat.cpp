#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsstat.h"
#include "terminal.h"

G_AmsStatus::G_AmsStatus(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 14;
  height = 7;
  Reset();
  }

G_AmsStatus::~G_AmsStatus() {
  }

void G_AmsStatus::Reset() {
  lastSpaceSuitOn = -9999;
  lastPlssOn = -9999;
  lastCabinPressurized = -9999;
  lastLanded = -9999;
  lastDocked = -9999;
  lastLandingRadarOn = -9999;
  lastDockingRadarOn = -9999;
  lastDsnOn = -9999;
  lastMetabolicRate = -9999;
  lastEfficiency = -9999;
  lastInjury = -9999;
  lastRcsFbMode = '*';
  lastRcsLrMode = '*';
  lastRcsUdMode = '*';
  }

void G_AmsStatus::Display() {
  GotoXY(x,y+0); printf("        status");
  GotoXY(x,y+1); printf(" F/B| SS|MB:  ");
  GotoXY(x,y+2); printf(" L/R| PL|EF:  ");
  GotoXY(x,y+3); printf(" U/D| CB|IN:  ");
  GotoXY(x,y+4); printf(" RAD| --|--:  ");
  GotoXY(x,y+5); printf(" DOK| DK|--:  ");
  GotoXY(x,y+6); printf(" DSN| TD|--:  ");
  }

void G_AmsStatus::Update() {
  Int32 i;
  if (spaceSuitOn != lastSpaceSuitOn) {
    GotoXY(x+5,y+1);
    printf("%c",(spaceSuitOn == 0) ? 'v' : '^');
    lastSpaceSuitOn = spaceSuitOn;
    }
  if (plssOn != lastPlssOn) {
    GotoXY(x+5,y+2);
    printf("%c",(plssOn == 0) ? 'v' : '^');
    lastPlssOn = plssOn;
    }
  if (cabinPressurized != lastCabinPressurized) {
    GotoXY(x+5,y+3);
    printf("%c",(cabinPressurized == 0) ? 'v' : '^');
    lastCabinPressurized = cabinPressurized;
    }
  if (docked != lastDocked) {
    GotoXY(x+5,y+5);
    printf("%c",(docked == 0) ? ' ' : '^');
    lastDocked = docked;
    }
  if (lm->Landed() != lastLanded) {
    GotoXY(x+5,y+6);
    printf("%c",(lm->Landed() == 0) ? ' ' : '^');
    lastLanded = lm->Landed();
    }
  if (landingRadarOn != lastLandingRadarOn) {
    GotoXY(x,y+4);
    printf("%c",(landingRadarOn == 0) ? ' ' : '^');
    lastLandingRadarOn = landingRadarOn;
    }
  if (dockingRadarOn != lastDockingRadarOn) {
    GotoXY(x,y+5);
    printf("%c",(dockingRadarOn == 0) ? ' ' : '^');
    lastDockingRadarOn = dockingRadarOn;
    }
  if (dsnOn != lastDsnOn) {
    GotoXY(x,y+6);
    printf("%c",(dsnOn == 0) ? ' ' : '^');
    lastDsnOn = dsnOn;
    }
  i = (int)metabolicRate;
  if (i != lastMetabolicRate) {
    GotoXY(x+12,y+1);
    printf("%2d",i);
    lastMetabolicRate = i;
    }
  i = (int)efficiency;
  if (i != lastEfficiency) {
    GotoXY(x+12,y+2);
    printf("%2d",i);
    lastEfficiency = i;
    }
  i = (int)injury;
  if (i != lastInjury) {
    GotoXY(x+12,y+3);
    printf("%2d",i);
    lastInjury = i;
    }
  if (lm->RcsFbMode() != lastRcsFbMode) {
    GotoXY(x,y+1);
    lastRcsFbMode = lm->RcsFbMode();
    if (lastRcsFbMode == ' ') printf(" ");
    if (lastRcsFbMode == 'F') printf("^");
    if (lastRcsFbMode == 'B') printf("v");
    }
  if (lm->RcsLrMode() != lastRcsLrMode) {
    GotoXY(x,y+2);
    lastRcsLrMode = lm->RcsLrMode();
    if (lastRcsLrMode == ' ') printf(" ");
    if (lastRcsLrMode == 'L') printf("^");
    if (lastRcsLrMode == 'R') printf("v");
    }
  if (lm->RcsUdMode() != lastRcsUdMode) {
    GotoXY(x,y+3);
    lastRcsUdMode = lm->RcsUdMode();
    if (lastRcsUdMode == ' ') printf(" ");
    if (lastRcsUdMode == 'U') printf("^");
    if (lastRcsUdMode == 'D') printf("v");
    }
  }

