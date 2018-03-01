#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsdock.h"
#include "terminal.h"

G_AmsDock::G_AmsDock(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 13;
  height = 8;
  Reset();
  }

G_AmsDock::~G_AmsDock() {
  }

void G_AmsDock::Reset() {
  lastDockingRadarPosX = 0;
  lastDockingRadarPosY = 0;
  lastDockingRadarAngX = 0;
  lastDockingRadarAngY = 0;
  lastDockingRadarRolX = 0;
  }

void G_AmsDock::Display() {
  GotoXY(x,y+0); printf("    dock     ");
  GotoXY(x,y+1); printf(" +---f|----+ ");
  GotoXY(x,y+2); printf(" |         | ");
  GotoXY(x,y+3); printf(" |         |l");
  GotoXY(x,y+4); printf("--         --");
  GotoXY(x,y+5); printf("r|         | ");
  GotoXY(x,y+6); printf(" |         | ");
  GotoXY(x,y+7); printf(" +----|b---+ ");
  }

void G_AmsDock::Update() {
  Int8 ax,ay;
  Int8 px,py;
  Int8 rx;
  char nsVel;
  char lVel;
  char rVel;
  char fVel;
  char bVel;
  Vector relPos;
  Vector relVel;
  relPos = ins->RelPos();
  if (pilotLocation != PILOT_LM || !dockingRadarOn ||
      dsnOn || landingRadarOn || relPos.Length() > 200) {
    px = 5; py = 3;
    ax = 5; ay = 3;
    rx = 5;
    nsVel = '|';
    fVel = '-';
    bVel = '-';
    lVel = '|';
    rVel = '|';
    }
  else {
    relVel = ins->RelVel();
    py = 3 - relPos.X()+.5;
    if (py > 5) py = 5;
    if (py < 1) py = 1;
    px = 5 + relPos.Y()+.5;
    if (px < 1) px = 1;
    if (px > 9) px = 9;
    ax = 5 + asin(lm->FaceUp().Y()) * 180 / M_PI + 0.5;
    ay = 3 - asin(lm->FaceUp().X()) * 180 / M_PI + 0.5;
    if (ax < 1) ax = 1;
    if (ax > 9) ax = 9;
    if (ay < 1) ay = 1;
    if (ay > 5) ay = 5;
    rx = 5 + asin(lm->FaceLeft().X()) * 180 / M_PI + 0.5;
    if (rx < 1) rx = 1;
    if (rx > 9) rx = 9;
    if (relVel.Z() < -0.4) nsVel = '+';
    else if (relVel.Z() < 0 && relVel.Z() > -0.2) nsVel = '-';
    else nsVel = '|';
    rVel = (relVel.Y() > 0.02) ? '<' : '|';
    lVel = (relVel.Y() < -0.02) ? '>' : '|';
    bVel = (relVel.X() > 0.02) ? 'v' : '-';
    fVel = (relVel.X() < -0.02) ? '^' : '-';
    }
  GotoXY(x+1+lastDockingRadarPosX,y+1+lastDockingRadarPosY);
  printf(" ");
  GotoXY(x+1+lastDockingRadarAngX,y+1+lastDockingRadarAngY);
  printf(" ");
  GotoXY(x+lastDockingRadarRolX+1,y+1+1); printf(" ");
  GotoXY(x+lastDockingRadarRolX+1,y+5+1); printf(" ");
  GotoXY(x+rx+1,y+1+1); printf("v");
  GotoXY(x+rx+1,y+5+1); printf("^");
  if (ax == px && ay == py) {
    GotoXY(x+px+1,y+py+1); printf("*");
    }
  else {
    GotoXY(x+px+1,y+py+1); printf("+");
    GotoXY(x+ax+1,y+ay+1); printf("X");
    }
  GotoXY(x+1,y+1+1); printf("%c",nsVel);
  GotoXY(x+1+10,y+1+1); printf("%c",nsVel);
  GotoXY(x+1+9,y+1); printf("%c",fVel);
  GotoXY(x+1+9,y+1+6); printf("%c",bVel);
  GotoXY(x+1,y+1+5); printf("%c",rVel);
  GotoXY(x+1+10,y+1+5); printf("%c",lVel);
  lastDockingRadarPosX = px;
  lastDockingRadarPosY = py;
  lastDockingRadarAngX = ax;
  lastDockingRadarAngY = ay;
  lastDockingRadarRolX = rx;
  }

