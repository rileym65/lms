#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_attitude.h"
#include "terminal.h"

G_Attitude::G_Attitude(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 20;
  height = 3;
  Reset();
  }

G_Attitude::~G_Attitude() {
  }

void G_Attitude::Reset() {
  lastUr = -99999;
  lastFr = -99999;
  lastLs = -99999;
  lastUo = -99999;
  lastFo = -99999;
  lastLo = -99999;
  }

void G_Attitude::Display() {
  GotoXY(x,y+0); printf("u/r:      u/o:      ");
  GotoXY(x,y+1); printf("f/r:      f/o:      ");
  GotoXY(x,y+2); printf("l/s:      l/o:      ");
  }

void G_Attitude::Update() {
  Int32 i;
  Double d;
  Vector v1,v2;
  v1 = lm->Position().Norm();
  v2 = lm->FaceUp().Norm();
  d = acos(v1.Dot(v2)) * 180 / M_PI;
  i = d * 10.0;
  if (i != lastUr) {
    GotoXY(x+4,y+0); printf("%5.1f",d);
    lastUr = i;
    }
  v2 = vehicle->FaceFront().Norm();
  d = acos(v1.Dot(v2)) * 180 / M_PI;
  i = d * 10.0;
  if (i != lastFr) {
    GotoXY(x+4,y+1); printf("%5.1f",d);
    lastFr = i;
    }
  v1 = vehicle->FaceFront().Norm();
  v2 = Vector(0,0,-1);
  d = acos(v1.Dot(v2)) * 180 / M_PI;
  i = d * 10.0;
  if (i != lastLs) {
    GotoXY(x+4,y+2); printf("%5.1f",d);
    lastLs = i;
    }
  v1 = lm->Velocity().Norm();
  v2 = lm->FaceUp().Norm();
  d = acos(v1.Dot(v2)) * 180 / M_PI;
  i = d * 10.0;
  if (i != lastUo) {
    GotoXY(x+14,y+0); printf("%5.1f",d);
    lastUo = i;
    }
  v2 = lm->FaceFront().Norm();
  d = acos(v1.Dot(v2)) * 180 / M_PI;
  i = d * 10.0;
  if (i != lastFo) {
    GotoXY(x+14,y+1); printf("%5.1f",d);
    lastFo = i;
    }
  v2 = lm->FaceLeft().Norm();
  d = acos(v1.Dot(v2)) * 180 / M_PI;
  i = d * 10.0;
  if (i != lastLo) {
    GotoXY(x+14,y+2); printf("%5.1f",d);
    lastLo = i;
    }
  }

