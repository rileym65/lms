#include <string.h>
#include <math.h>
#include "types.h"
#include "gauge.h"
#include "g_orbit.h"
#include "terminal.h"
#include "vehicle.h"
#include "common.h"

G_Orbit::G_Orbit(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 10;
  height = 3;
  }

G_Orbit::~G_Orbit() {
  }

void G_Orbit::Reset() {
  }

void G_Orbit::Display() {
  GotoXY(x,y+0); Write("u/o:-999.9");
  GotoXY(x,y+1); Write("f/o:-999.9");
  GotoXY(x,y+2); Write("l/o:-999.9");
  }

void G_Orbit::Update() {
  Vector v1;
  Vector v2;
  Double d;
  char   buffer[16];
  v1 = vehicle->Velocity();
  v1 = v1 - vehicle->Orbiting()->Velocity();
  v1 = v1.Norm();
  v2 = vehicle->FaceUp().Norm();
  d = acos(v1.Dot(v2)) * 180 / PI;
  if (isnan(d)) strcpy(buffer," ---.-");
    else sprintf(buffer,"%6.1f",d);
  GotoXY(x+4,y+0); Write(buffer);
  v2 = vehicle->FaceFront().Norm();
  d = acos(v1.Dot(v2)) * 180 / PI;
  if (isnan(d)) strcpy(buffer," ---.-");
    else sprintf(buffer,"%6.1f",d);
  GotoXY(x+4,y+1); Write(buffer);
  v2 = vehicle->FaceLeft().Norm();
  d = acos(v1.Dot(v2)) * 180 / PI;
  if (isnan(d)) strcpy(buffer," ---.-");
    else sprintf(buffer,"%6.1f",d);
  GotoXY(x+4,y+2); Write(buffer);
  }

