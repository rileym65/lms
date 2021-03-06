#include "types.h"
#include "gauge.h"
#include "g_periapsis.h"
#include "terminal.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "common.h"

G_Periapsis::G_Periapsis(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Periapsis::~G_Periapsis() {
  }

void G_Periapsis::Reset() {
  }

void G_Periapsis::Display() {
  GotoXY(x,y); Write("Per:-9999999");
  }

void G_Periapsis::Update() {
  Vector pos;
  Double rad;
  char   buffer[16];
  if ((vehicle->Type() & VT_SPACECRAFT) == 0) return;
  rad = ((Spacecraft*)vehicle)->Periapsis() - vehicle->Orbiting()->Radius();
  if (rad > 999999000) rad = 999999000;
  if (rad < -99999000) rad = -99999000;
  sprintf(buffer,"%8.1f",rad / 1000.0);
  GotoXY(x+4,y); Write(buffer);
  }

