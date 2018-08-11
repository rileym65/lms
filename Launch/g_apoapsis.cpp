#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_apoapsis.h"
#include "terminal.h"

G_Apoapsis::G_Apoapsis(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Apoapsis::~G_Apoapsis() {
  }

void G_Apoapsis::Reset() {
  }

void G_Apoapsis::Display() {
  GotoXY(x,y); Write("Apo:-9999999");
  }

void G_Apoapsis::Update() {
  Vector pos;
  Double rad;
  char   buffer[16];
  rad = ((Spacecraft*)vehicle)->Apoapsis() - GROUND;
  sprintf(buffer,"%8.1f",rad / 1000.0);
  GotoXY(x+4,y); Write(buffer);
  }

