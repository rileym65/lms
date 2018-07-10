#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_rcs.h"
#include "terminal.h"

G_Rcs::G_Rcs(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 20;
  height = 3;
  Reset();
  }

G_Rcs::~G_Rcs() {
  }

void G_Rcs::Reset() {
  lastRcsFbMode = '*';
  lastRcsLrMode = '*';
  lastRcsUdMode = '*';
  lastPitch = -99999;
  lastRoll = -99999;
  lastYaw = -99999;
  lastRotationThrottle = -99;
  lastTranslationThrottle = -99;
  lastRcsFuel = -999;
  }

void G_Rcs::Display() {
  GotoXY(x,y+0); Write(" F/B  PT:     RTH:  ");
  GotoXY(x,y+1); Write(" L/R  RL:     TTH:  ");
  GotoXY(x,y+2); Write(" U/D  YW:     PRP:  ");
  }

void G_Rcs::Update() {
  Int32 i;
  char buffer[32];
  if (lm->RcsFbMode() != lastRcsFbMode) {
    lastRcsFbMode = lm->RcsFbMode();
    GotoXY(x+0,y+0); Write(" ");
    GotoXY(x+4,y+0); Write(" ");
    if (lastRcsFbMode == 'F') { GotoXY(x+0,y+0); Write("<"); }
    if (lastRcsFbMode == 'B') { GotoXY(x+4,y+0); Write(">"); }
    }
  if (lm->RcsLrMode() != lastRcsLrMode) {
    lastRcsLrMode = lm->RcsLrMode();
    GotoXY(x+0,y+1); Write(" ");
    GotoXY(x+4,y+1); Write(" ");
    if (lastRcsLrMode == 'L') { GotoXY(x+0,y+1); Write("<"); }
    if (lastRcsLrMode == 'R') { GotoXY(x+4,y+1); Write(">"); }
    }
  if (lm->RcsUdMode() != lastRcsUdMode) {
    lastRcsUdMode = lm->RcsUdMode();
    GotoXY(x+0,y+2); Write(" ");
    GotoXY(x+4,y+2); Write(" ");
    if (lastRcsUdMode == 'U') { GotoXY(x+0,y+2); Write("<"); }
    if (lastRcsUdMode == 'D') { GotoXY(x+4,y+2); Write(">"); }
    }
  i = (int)(vehicle->PitchRate() * 10);
  if (i != lastPitch) {
    GotoXY(x+9,y+0);
    if (i >= 100) Write(">10 ");
    else if (i <= -100) Write("<-10");
    else {
      sprintf(buffer,"%4.1f",i/10.0);
      Write(buffer);
      }
    lastPitch = i;
    }
  i = (int)(vehicle->RollRate() * 10);
  if (i != lastRoll) {
    GotoXY(x+9,y+1);
    if (i >= 100) Write(">10 ");
    else if (i <= -100) Write("<-10");
    else {
      sprintf(buffer,"%4.1f",i/10.0);
      Write(buffer);
      }
    lastRoll = i;
    }
  i = (int)(vehicle->YawRate() * 10);
  if (i != lastYaw) {
    GotoXY(x+9,y+2);
    if (i >= 100) Write(">10 ");
    else if (i <= -100) Write("<-10");
    else {
      sprintf(buffer,"%4.1f",i/10.0);
      Write(buffer);
      }
    lastYaw = i;
    }
  if (lm->RcsRotThrottle() != lastRotationThrottle) {
    GotoXY(x+18,y+0);
    lastRotationThrottle = lm->RcsRotThrottle();
    if (lastRotationThrottle == 10) Write("vv");
    if (lastRotationThrottle == 50) Write("--");
    if (lastRotationThrottle == 100) Write("^^");
    }
  if (lm->RcsThrottle() != lastTranslationThrottle) {
    GotoXY(x+18,y+1);
    lastTranslationThrottle = lm->RcsThrottle();
    if (lastTranslationThrottle == 1) Write("vv");
    if (lastTranslationThrottle == 10) Write("--");
    if (lastTranslationThrottle == 100) Write("^^");
    }
  i = (int)(lm->RcsFuel() / lm->MaxRcsFuel() * 100);
  if (i>99) i = 99;
  if (i != lastRcsFuel) {
    GotoXY(x+18,y+2); sprintf(buffer,"%2d",i); Write(buffer);
    lastRcsFuel = i;
    }
  }

