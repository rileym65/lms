#include <math.h>
#include "types.h"
#include "gauge.h"
#include "g_amsdock.h"
#include "terminal.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "common.h"

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
  lastDockingRadarYaw = 0;
  lastDockingRadarPitch = 0;
  lastDockingRadarRoll = 0;
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
  Vector pos;
  Vector tvUp;
  Vector tvFr;
  Vector tvLf;
  Vector vUp;
  Vector vFr;
  Vector vLf;
  char nsVel;
  char lVel;
  char rVel;
  char fVel;
  char bVel;
  Double d;
  Double px,py;
  Int8   aligned;
  char buffer[32];
  if (vehicle->TargetVehicle() == NULL) return;
  aligned = -1;
  pos = vehicle->Position() - (vehicle->TargetVehicle())->Position();
  tvUp = vehicle->TargetVehicle()->FaceUp().Norm();
  tvFr = vehicle->TargetVehicle()->FaceFront().Norm();
  tvLf = vehicle->TargetVehicle()->FaceLeft().Norm();
  if (vehicle->FaceUp().Dot(tvUp) >= 0 || dockingRadarOn == 0) {
    GotoXY(x+6+lastDockingRadarPosX, y+4+lastDockingRadarPosY); Write(" ");
    GotoXY(x+6+lastDockingRadarYaw, y+4+lastDockingRadarPitch); Write(" ");
    GotoXY(x+6+lastDockingRadarRoll, y+2); Write(" ");
    GotoXY(x+6+lastDockingRadarRoll, y+6); Write(" ");
    return;
    }
  vUp = vehicle->FaceUp().Norm();
  vFr = vehicle->FaceFront().Norm();
  vLf = vehicle->FaceLeft().Norm();

  GotoXY(x+6+lastDockingRadarPosX, y+4+lastDockingRadarPosY); Write(" ");
  GotoXY(x+6+lastDockingRadarYaw, y+4+lastDockingRadarPitch); Write(" ");
  GotoXY(x+6+lastDockingRadarRoll, y+2); Write(" ");
  GotoXY(x+6+lastDockingRadarRoll, y+6); Write(" ");

  /* ************************** */
  /* ***** Roll indicator ***** */
  /* ************************** */
  d = vFr.Dot(tvLf);
  if (d < -0.0650) lastDockingRadarRoll = -4;
  else if (d < -0.0500) lastDockingRadarRoll = -3;
  else if (d < -0.0325) lastDockingRadarRoll = -2;
  else if (d < -0.0150) lastDockingRadarRoll = -1;
  else if (d > 0.0650) lastDockingRadarRoll = 4;
  else if (d > 0.0500) lastDockingRadarRoll = 3;
  else if (d > 0.0325) lastDockingRadarRoll = 2;
  else if (d > 0.0150) lastDockingRadarRoll = 1;
  else lastDockingRadarRoll = 0;

  /* ***************** */
  /* ***** Pitch ***** */
  /* ***************** */
  d = vFr.Dot(tvUp);
  if (d < -0.0325) lastDockingRadarPitch = 2;
  else if (d < -0.0150) lastDockingRadarPitch = 1;
  else if (d > 0.0325) lastDockingRadarPitch = -2;
  else if (d > 0.0150) lastDockingRadarPitch = -1;
  else lastDockingRadarPitch = 0;

  d = vLf.Dot(tvUp);
  if (d < -0.0650) lastDockingRadarYaw = -4;
  else if (d < -0.0500) lastDockingRadarYaw = -3;
  else if (d < -0.0325) lastDockingRadarYaw = -2;
  else if (d < -0.0150) lastDockingRadarYaw = -1;
  else if (d > 0.0650) lastDockingRadarYaw = 4;
  else if (d > 0.0500) lastDockingRadarYaw = 3;
  else if (d > 0.0325) lastDockingRadarYaw = 2;
  else if (d > 0.0150) lastDockingRadarYaw = 1;
  else lastDockingRadarYaw = 0;



//  px = pos.Norm().Dot(tvLf);
//  py = pos.Norm().Dot(tvFr);

//  px = px * pos.Length();
//  py = py * pos.Length();

  px = vehicle->GetIns()->TarDockX();
  py = vehicle->GetIns()->TarDockY();
  if (px <= -2.5) lastDockingRadarPosX = 4;
  else if (px < -1.5) lastDockingRadarPosX = 3;
  else if (px < -0.5) lastDockingRadarPosX = 2;
  else if (px < -0.4) lastDockingRadarPosX = 1;
  else if (px > 2.5) lastDockingRadarPosX = -4;
  else if (px > 1.5) lastDockingRadarPosX = -3;
  else if (px > 0.5) lastDockingRadarPosX = -2;
  else if (px > 0.4) lastDockingRadarPosX = -1;
  else lastDockingRadarPosX = 0;
  if (py < -0.5) lastDockingRadarPosY = -2;
  else if (py < -0.4) lastDockingRadarPosY = -1;
  else if (py > 0.5) lastDockingRadarPosY = 2;
  else if (py > 0.4) lastDockingRadarPosY = 1;
  else lastDockingRadarPosY = 0;

  GotoXY(x+6+lastDockingRadarRoll, y+2); Write("v");
  GotoXY(x+6+lastDockingRadarRoll, y+6); Write("^");
  if (lastDockingRadarYaw == lastDockingRadarPosX &&
      lastDockingRadarPitch == lastDockingRadarPosY) {
    GotoXY(x+6+lastDockingRadarYaw, y+4+lastDockingRadarPitch); Write("*");
    }
  else {
    GotoXY(x+6+lastDockingRadarYaw, y+4+lastDockingRadarPitch); Write("X");
    GotoXY(x+6+lastDockingRadarPosX, y+4+lastDockingRadarPosY); Write("+");
    }

  if (vehicle->GetIns()->TarDockVelZ() < -0.4) nsVel = '+';
  else if (vehicle->GetIns()->TarDockVelZ() > 0) nsVel = '-';
  else if (vehicle->GetIns()->TarDockVelZ() > -0.2) nsVel = '-';
  else nsVel = '|';
  rVel = (vehicle->GetIns()->TarDockVelX() < -0.02) ? '<' : '|';
  lVel = (vehicle->GetIns()->TarDockVelX() > 0.02) ? '>' : '|';
  bVel = (vehicle->GetIns()->TarDockVelY() < -0.02) ? 'v' : '-';
  fVel = (vehicle->GetIns()->TarDockVelY() > 0.02) ? '^' : '-';
  GotoXY(x+1,y+1+1); sprintf(buffer,"%c",nsVel); Write(buffer);
  GotoXY(x+1+10,y+1+1); sprintf(buffer,"%c",nsVel); Write(buffer);
  GotoXY(x+1+9,y+1); sprintf(buffer,"%c",fVel); Write(buffer);
  GotoXY(x+1+9,y+1+6); sprintf(buffer,"%c",bVel); Write(buffer);
  GotoXY(x+1,y+1+5); sprintf(buffer,"%c",rVel); Write(buffer);
  GotoXY(x+1+10,y+1+5); sprintf(buffer,"%c",lVel); Write(buffer);
return;


  d = px;
  if (d >=100) d = 99.9999;
  if (d <=-100) d = -99.9999;
  sprintf(buffer,"%+8.4f",d);
  GotoXY(x+17, y+2); Write(buffer);
  d = py;
  if (d >=100) d = 99.9999;
  if (d <=-100) d = -99.9999;
  sprintf(buffer,"%+8.4f",d);
  GotoXY(x+17, y+5); Write(buffer);

  d = px - lastPx;
  if (d >=100) d = 99.9999;
  if (d <=-100) d = -99.9999;
  sprintf(buffer,"%+8.4f",d);
  GotoXY(x+17, y+3); Write(buffer);
  d = py - lastPy;
  if (d >=100) d = 99.9999;
  if (d <=-100) d = -99.9999;
  sprintf(buffer,"%+8.4f",d);
  GotoXY(x+17, y+6); Write(buffer);

  lastPx = px;
  lastPy = py;
  GotoXY(x+6+lastPosX,y+4+lastPosY); Write(" ");
  if (px < -3.5) lastPosX = 4;
  else if (px < -2.5) lastPosX = 3;
  else if (px < -1.5) lastPosX = 2;
  else if (px < -0.5) lastPosX = 1;
  else if (px > 3.5) lastPosX = -4;
  else if (px > 2.5) lastPosX = -3;
  else if (px > 1.5) lastPosX = -2;
  else if (px > 0.5) lastPosX = -1;
  else lastPosX = 0;
  if (py < -1.5) lastPosY = -2;
  else if (py < -0.5) lastPosY = -1;
  else if (py > 1.5) lastPosY = 2;
  else if (py > 0.5) lastPosY = 1;
  else lastPosY = 0;
  GotoXY(x+6+lastPosX,y+4+lastPosY); Write("+");
  if (lastPosX != 0 || lastPosY != 0) aligned = 0;
  GotoXY(x+13, y+0);
  if (aligned) Write("Align "); else Write("      ");
  }

/*
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
  Spacecraft *sc;
  if ((vehicle->Type() & VT_SPACECRAFT) == 0) return;
  sc = (Spacecraft*)vehicle;
  relPos = sc->RelPos();
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
    relVel = sc->RelVel();
    py = 3 + relPos.X()+.5;
    if (py > 5) py = 5;
    if (py < 1) py = 1;
    px = 5 + relPos.Y()+.5;
    if (px < 1) px = 1;
    if (px > 9) px = 9;
    ax = 5 + asin(sc->FaceUp().Y()) * 180 / PI + 0.5;
    ay = 3 - asin(sc->FaceUp().X()) * 180 / PI + 0.5;
    if (ax < 1) ax = 1;
    if (ax > 9) ax = 9;
    if (ay < 1) ay = 1;
    if (ay > 5) ay = 5;
    v = Vector(0,-1,0);
    dot = v.Dot(sc->FaceLeft());
    rx = 5 + acos(dot) * 180 / PI + 0.5;
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
*/

