#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_periapsis.h"
#include "terminal.h"

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
  rad = ((Spacecraft*)vehicle)->Periapsis() - vehicle->Orbiting()->Radius();
  sprintf(buffer,"%8.1f",rad / 1000.0);
  GotoXY(x+4,y); Write(buffer);
  }

