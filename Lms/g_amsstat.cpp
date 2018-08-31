#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsstat.h"
#include "terminal.h"
#include "common.h"

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
  GotoXY(x,y+0); Write("        status");
  GotoXY(x,y+1); Write(" F/B| SS|MB:  ");
  GotoXY(x,y+2); Write(" L/R| PL|EF:  ");
  GotoXY(x,y+3); Write(" U/D| CB|IN:  ");
  GotoXY(x,y+4); Write(" RAD| --|--:  ");
  GotoXY(x,y+5); Write(" DOK| DK|--:  ");
  GotoXY(x,y+6); Write(" DSN| TD|--:  ");
  }

void G_AmsStatus::Update() {
  Int32 i;
  char buffer[32];
  if (spaceSuitOn != lastSpaceSuitOn) {
    GotoXY(x+5,y+1);
    if (spaceSuitOn == 0) Write("v"); else Write("^");
    lastSpaceSuitOn = spaceSuitOn;
    }
  if (plssOn != lastPlssOn) {
    GotoXY(x+5,y+2);
    if (plssOn == 0) Write("v"); else Write("^");
    lastPlssOn = plssOn;
    }
  if (cabinPressurized != lastCabinPressurized) {
    GotoXY(x+5,y+3);
    if (cabinPressurized == 0) Write("v"); else Write("^");
    lastCabinPressurized = cabinPressurized;
    }
  if (docked != lastDocked) {
    GotoXY(x+5,y+5);
    if (docked == 0) Write(" "); else Write("^");
    lastDocked = docked;
    }
  if (lm->Landed() != lastLanded) {
    GotoXY(x+5,y+6);
    if (lm->Landed() == 0) Write(" "); else Write("^");
    lastLanded = lm->Landed();
    }
  if (landingRadarOn != lastLandingRadarOn) {
    GotoXY(x,y+4);
    if (landingRadarOn == 0) Write(" "); else Write("^");
    lastLandingRadarOn = landingRadarOn;
    }
  if (dockingRadarOn != lastDockingRadarOn) {
    GotoXY(x,y+5);
    if (dockingRadarOn == 0) Write(" "); else Write("^");
    lastDockingRadarOn = dockingRadarOn;
    }
  if (dsnOn != lastDsnOn) {
    GotoXY(x,y+6);
    if (dsnOn == 0) Write(" "); else Write("^");
    lastDsnOn = dsnOn;
    }
  i = (int)metabolicRate;
  if (i != lastMetabolicRate) {
    GotoXY(x+12,y+1);
    sprintf(buffer,"%2d",i);
    Write(buffer);
    lastMetabolicRate = i;
    }
  i = (int)efficiency;
  if (i != lastEfficiency) {
    GotoXY(x+12,y+2);
    sprintf(buffer,"%2d",i);
    Write(buffer);
    lastEfficiency = i;
    }
  i = (int)injury;
  if (i != lastInjury) {
    GotoXY(x+12,y+3);
    sprintf(buffer,"%2d",i);
    Write(buffer);
    lastInjury = i;
    }
  if (lm->RcsFbMode() != lastRcsFbMode) {
    GotoXY(x,y+1);
    lastRcsFbMode = lm->RcsFbMode();
    if (lastRcsFbMode == ' ') Write(" ");
    if (lastRcsFbMode == 'F') Write("^");
    if (lastRcsFbMode == 'B') Write("v");
    }
  if (lm->RcsLrMode() != lastRcsLrMode) {
    GotoXY(x,y+2);
    lastRcsLrMode = lm->RcsLrMode();
    if (lastRcsLrMode == ' ') Write(" ");
    if (lastRcsLrMode == 'L') Write("^");
    if (lastRcsLrMode == 'R') Write("v");
    }
  if (lm->RcsUdMode() != lastRcsUdMode) {
    GotoXY(x,y+3);
    lastRcsUdMode = lm->RcsUdMode();
    if (lastRcsUdMode == ' ') Write(" ");
    if (lastRcsUdMode == 'U') Write("^");
    if (lastRcsUdMode == 'D') Write("v");
    }
  }

