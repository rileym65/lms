#include <math.h>
#include "types.h"
#include "gauge.h"
#include "g_csmdock.h"
#include "terminal.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "common.h"

G_CsmDock::G_CsmDock(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 25;
  height = 9;
  Reset();
  }

G_CsmDock::~G_CsmDock() {
  }

void G_CsmDock::Reset() {
  lastDockingRadarRoll = 0;
  lastDockingRadarPitch = 0;
  lastDockingRadarYaw = 0;
  lastPx = 0;
  lastPy = 0;
  }

void G_CsmDock::Display() {
  GotoXY(x,y+0); Write("      v      Align       ");
  GotoXY(x,y+1); Write(" +----|----+ pX: +99.9999");
  GotoXY(x,y+2); Write(" |         | dX: +99.9999");
  GotoXY(x,y+3); Write(" |         |             ");
  GotoXY(x,y+4); Write(">-    +    - pY: +99.9999");
  GotoXY(x,y+5); Write(" |         | dY: +99.9999");
  GotoXY(x,y+6); Write(" |         |             ");
  GotoXY(x,y+7); Write(" +----|----+ pZ: +99.9999");
  GotoXY(x,y+8); Write("      ^      dZ: +99.9999");
  }

void G_CsmDock::Update() {
  Vector pos;
  Vector tvUp;
  Vector tvFr;
  Vector tvLf;
  Vector vUp;
  Vector vFr;
  Vector vLf;
  Double d;
  Double px,py,pz;
  Int8   aligned;
  char buffer[32];
  if (csm->TargetVehicle() == NULL) return;
  aligned = -1;
  pos = csm->Position() - (csm->TargetVehicle())->Position();
  tvUp = csm->TargetVehicle()->FaceUp().Norm();
  tvFr = csm->TargetVehicle()->FaceFront().Norm();
  tvLf = csm->TargetVehicle()->FaceLeft().Norm();
  if (csm->FaceUp().Dot(tvUp) >= 0) {
    GotoXY(x+6+lastDockingRadarRoll, y+0); Write(" ");
    GotoXY(x+0, y+4+lastDockingRadarPitch); Write(" ");
    GotoXY(x+6+lastDockingRadarYaw, y+8); Write(" ");
    lastDockingRadarRoll = 0;
    lastDockingRadarPitch = 0;
    lastDockingRadarYaw = 0;
    GotoXY(x+6+lastDockingRadarRoll, y+0); Write("^");
    GotoXY(x+0, y+4+lastDockingRadarPitch); Write("<");
    GotoXY(x+6+lastDockingRadarYaw, y+8); Write("v");
    GotoXY(x+13, y+0); Write("      ");
    GotoXY(x+17, y+1); Write("---.----");
    GotoXY(x+17, y+2); Write("---.----");
    GotoXY(x+17, y+4); Write("---.----");
    GotoXY(x+17, y+5); Write("---.----");
    GotoXY(x+17, y+7); Write("---.----");
    GotoXY(x+17, y+8); Write("---.----");
    return;
    }
  vUp = csm->FaceUp().Norm();
  vFr = csm->FaceFront().Norm();
  vLf = csm->FaceLeft().Norm();
  GotoXY(x+6+lastDockingRadarRoll, y+0); Write(" ");
  GotoXY(x+0, y+4+lastDockingRadarPitch); Write(" ");
  GotoXY(x+6+lastDockingRadarYaw, y+8); Write(" ");
  d = vFr.Dot(tvUp);
  if (d < -0.0500) lastDockingRadarPitch = 3;
  else if (d < -0.0325) lastDockingRadarPitch = 2;
  else if (d < -0.0150) lastDockingRadarPitch = 1;
  else if (d > 0.0500) lastDockingRadarPitch = -3;
  else if (d > 0.0325) lastDockingRadarPitch = -2;
  else if (d > 0.0150) lastDockingRadarPitch = -1;
  else lastDockingRadarPitch = 0;
  d = vLf.Dot(tvUp);
  if (d < -0.0850) lastDockingRadarYaw = -5;
  else if (d < -0.0650) lastDockingRadarYaw = -4;
  else if (d < -0.0500) lastDockingRadarYaw = -3;
  else if (d < -0.0325) lastDockingRadarYaw = -2;
  else if (d < -0.0150) lastDockingRadarYaw = -1;
  else if (d > 0.0850) lastDockingRadarYaw = 5;
  else if (d > 0.0650) lastDockingRadarYaw = 4;
  else if (d > 0.0500) lastDockingRadarYaw = 3;
  else if (d > 0.0325) lastDockingRadarYaw = 2;
  else if (d > 0.0150) lastDockingRadarYaw = 1;
  else lastDockingRadarYaw = 0;
  d = vFr.Dot(tvLf);
  if (d < -0.0850) lastDockingRadarRoll = 5;
  else if (d < -0.0650) lastDockingRadarRoll = 4;
  else if (d < -0.0500) lastDockingRadarRoll = 3;
  else if (d < -0.0325) lastDockingRadarRoll = 2;
  else if (d < -0.0150) lastDockingRadarRoll = 1;
  else if (d > 0.0850) lastDockingRadarRoll = -5;
  else if (d > 0.0650) lastDockingRadarRoll = -4;
  else if (d > 0.0500) lastDockingRadarRoll = -3;
  else if (d > 0.0325) lastDockingRadarRoll = -2;
  else if (d > 0.0150) lastDockingRadarRoll = -1;
  else lastDockingRadarRoll = 0;
  if (lastDockingRadarPitch != 0) aligned = 0;
  if (lastDockingRadarYaw != 0) aligned = 0;
  if (lastDockingRadarRoll != 0) aligned = 0;
  GotoXY(x+6+lastDockingRadarRoll, y+0); Write("v");
  GotoXY(x+0, y+4+lastDockingRadarPitch); Write(">");
  GotoXY(x+6+lastDockingRadarYaw, y+8); Write("^");


  px = pos.Norm().Dot(tvLf);
  py = pos.Norm().Dot(tvFr);
  pz = pos.Length();

  px = px * pos.Length();
  py = py * pos.Length();
  d = px;
  if (d >=100) d = 99.9999;
  if (d <=-100) d = -99.9999;
  sprintf(buffer,"%+8.4f",d);
  GotoXY(x+17, y+1); Write(buffer);
  d = py;
  if (d >=100) d = 99.9999;
  if (d <=-100) d = -99.9999;
  sprintf(buffer,"%+8.4f",d);
  GotoXY(x+17, y+4); Write(buffer);
  d = pz;
  if (d >=100) d = 99.9999;
  if (d <=-100) d = -99.9999;
  sprintf(buffer,"%+8.4f",d);
  GotoXY(x+17, y+7); Write(buffer);
  
  d = px - lastPx;
  if (d >=100) d = 99.9999;
  if (d <=-100) d = -99.9999;
  sprintf(buffer,"%+8.4f",d);
  GotoXY(x+17, y+2); Write(buffer);
  d = py - lastPy;
  if (d >=100) d = 99.9999;
  if (d <=-100) d = -99.9999;
  sprintf(buffer,"%+8.4f",d);
  GotoXY(x+17, y+5); Write(buffer);
  d = pz - lastPz;
  if (d >=100) d = 99.9999;
  if (d <=-100) d = -99.9999;
  sprintf(buffer,"%+8.4f",d);
  GotoXY(x+17, y+8); Write(buffer);

  lastPx = px;
  lastPy = py;
  lastPz = pz;

  GotoXY(x+6+lastPosX,y+4+lastPosY); Write(" ");
  if (px < -2.5) lastPosX = 4;
  else if (px < -1.5) lastPosX = 3;
  else if (px < -0.5) lastPosX = 2;
  else if (px < -0.4) lastPosX = 1;
  else if (px > 2.5) lastPosX = -4;
  else if (px > 1.5) lastPosX = -3;
  else if (px > 0.5) lastPosX = -2;
  else if (px > 0.4) lastPosX = -1;
  else lastPosX = 0;
  if (py < -0.5) lastPosY = -2;
  else if (py < -0.4) lastPosY = -1;
  else if (py > 0.5) lastPosY = 2;
  else if (py > 0.4) lastPosY = 1;
  else lastPosY = 0;
  GotoXY(x+6+lastPosX,y+4+lastPosY); Write("+");
  if (lastPosX != 0 || lastPosY != 0) aligned = 0;
  GotoXY(x+13, y+0);
  if (aligned) Write("Align "); else Write("      ");
  }

