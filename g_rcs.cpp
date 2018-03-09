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
  GotoXY(x,y+0); printf(" F/B  PT:     RTH:  ");
  GotoXY(x,y+1); printf(" L/R  RL:     TTH:  ");
  GotoXY(x,y+2); printf(" U/D  YW:     PRP:  ");
  }

void G_Rcs::Update() {
  Int32 i;
  if (lm->RcsFbMode() != lastRcsFbMode) {
    lastRcsFbMode = lm->RcsFbMode();
    GotoXY(x+0,y+0); printf(" ");
    GotoXY(x+4,y+0); printf(" ");
    if (lastRcsFbMode == 'F') { GotoXY(x+0,y+0); printf("^"); }
    if (lastRcsFbMode == 'B') { GotoXY(x+4,y+0); printf("^"); }
    }
  if (lm->RcsLrMode() != lastRcsLrMode) {
    lastRcsLrMode = lm->RcsLrMode();
    GotoXY(x+0,y+1); printf(" ");
    GotoXY(x+4,y+1); printf(" ");
    if (lastRcsLrMode == 'L') { GotoXY(x+0,y+1); printf("^"); }
    if (lastRcsLrMode == 'R') { GotoXY(x+4,y+1); printf("^"); }
    }
  if (lm->RcsUdMode() != lastRcsUdMode) {
    lastRcsUdMode = lm->RcsUdMode();
    GotoXY(x+0,y+2); printf(" ");
    GotoXY(x+4,y+2); printf(" ");
    if (lastRcsUdMode == 'U') { GotoXY(x+0,y+2); printf("^"); }
    if (lastRcsUdMode == 'D') { GotoXY(x+4,y+2); printf("^"); }
    }
  i = (int)(lm->PitchRate() * 10);
  if (i != lastPitch) {
    GotoXY(x+9,y+0);
    if (i >= 100) printf(">10 ");
    else if (i <= -100) printf("<-10");
    else printf("%4.1f",i/10.0);
    lastPitch = i;
    }
  i = (int)(lm->RollRate() * 10);
  if (i != lastRoll) {
    GotoXY(x+9,y+1);
    if (i >= 100) printf(">10 ");
    else if (i <= -100) printf("<-10");
    else printf("%4.1f",i/10.0);
    lastRoll = i;
    }
  i = (int)(lm->YawRate() * 10);
  if (i != lastYaw) {
    GotoXY(x+9,y+2);
    if (i >= 100) printf(">10 ");
    else if (i <= -100) printf("<-10");
    else printf("%4.1f",i/10.0);
    lastYaw = i;
    }
  if (lm->RcsRotThrottle() != lastRotationThrottle) {
    GotoXY(x+18,y+0);
    lastRotationThrottle = lm->RcsRotThrottle();
    if (lastRotationThrottle == 10) printf("vv");
    if (lastRotationThrottle == 50) printf("--");
    if (lastRotationThrottle == 100) printf("^^");
    }
  if (lm->RcsThrottle() != lastTranslationThrottle) {
    GotoXY(x+18,y+1);
    lastTranslationThrottle = lm->RcsThrottle();
    if (lastTranslationThrottle == 1) printf("vv");
    if (lastTranslationThrottle == 10) printf("--");
    if (lastTranslationThrottle == 100) printf("^^");
    }
  i = (int)(lm->RcsFuel() / FUEL_RCS * 100);
  if (i>99) i = 99;
  if (i != lastRcsFuel) {
    GotoXY(x+18,y+2); printf("%2d",i);
    lastRcsFuel = i;
    }
  }

