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
  lastDockingRadarPosX = -99;
  lastDockingRadarPosY = -99;
  lastDockingRadarAngX = -99;
  lastDockingRadarAngY = -99;
  lastDockingRadarRolX = -99;
  }

void G_AmsDock::Display() {
  GotoXY(x,y+0); Write("    dock     ");
  GotoXY(x,y+1); Write(" +---f|----+ ");
  GotoXY(x,y+2); Write(" |         | ");
  GotoXY(x,y+3); Write(" |         |l");
  GotoXY(x,y+4); Write("--         --");
  GotoXY(x,y+5); Write("r|         | ");
  GotoXY(x,y+6); Write(" |         | ");
  GotoXY(x,y+7); Write(" +----|b---+ ");
  }

void G_AmsDock::Update() {
  char buffer[32];
  Int8 ax,ay;
  Int8 px,py;
  Int8 rx;
  char nsVel;
  char lVel;
  char rVel;
  char fVel;
  char bVel;
  Double dot;
  Vector v;
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
    py = 3 + relPos.X()+.5;
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
    v = Vector(0,-1,0);
    dot = v.Dot(lm->FaceLeft());
    rx = 5 + acos(dot) * 180 / M_PI + 0.5;
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
  if (lastDockingRadarPosX > -99) {
    GotoXY(x+1+lastDockingRadarPosX,y+1+lastDockingRadarPosY);
    Write(" ");
    GotoXY(x+1+lastDockingRadarAngX,y+1+lastDockingRadarAngY);
    Write(" ");
    GotoXY(x+lastDockingRadarRolX+1,y+1+1); Write(" ");
    GotoXY(x+lastDockingRadarRolX+1,y+5+1); Write(" ");
    GotoXY(x+rx+1,y+1+1); Write("v");
    GotoXY(x+rx+1,y+5+1); Write("^");
    }
  if (ax == px && ay == py) {
    GotoXY(x+px+1,y+py+1); Write("*");
    }
  else {
    GotoXY(x+px+1,y+py+1); Write("+");
    GotoXY(x+ax+1,y+ay+1); Write("X");
    }
  GotoXY(x+1,y+1+1); sprintf(buffer,"%c",nsVel); Write(buffer);
  GotoXY(x+1+10,y+1+1); sprintf(buffer,"%c",nsVel); Write(buffer);
  GotoXY(x+1+9,y+1); sprintf(buffer,"%c",fVel); Write(buffer);
  GotoXY(x+1+9,y+1+6); sprintf(buffer,"%c",bVel); Write(buffer);
  GotoXY(x+1,y+1+5); sprintf(buffer,"%c",rVel); Write(buffer);
  GotoXY(x+1+10,y+1+5); sprintf(buffer,"%c",lVel); Write(buffer);
  lastDockingRadarPosX = px;
  lastDockingRadarPosY = py;
  lastDockingRadarAngX = ax;
  lastDockingRadarAngY = ay;
  lastDockingRadarRolX = rx;
  }

