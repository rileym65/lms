#include "types.h"
#include "gauge.h"
#include "common.h"
#include "g_ground.h"
#include "terminal.h"
#include "vehicle.h"

G_Ground::G_Ground(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 13;
  height = 1;
  }

G_Ground::~G_Ground() {
  }

void G_Ground::Reset() {
  }

void G_Ground::Display() {
  GotoXY(x,y+0); Write("Gnd: +999.99");
  }

void G_Ground::Update() {
  char buffer[32];
  Double d;
  d = vehicle->Longitude();
  d = d - kscAngle - 80.6077;
  while (d >= 180) d -= 360;
  while (d <= -180) d += 360;
  sprintf(buffer,"%+8.2f",d);
  GotoXY(x+5,y+0); Write(buffer);
  }

