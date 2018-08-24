#include "types.h"
#include "gauge.h"
#include "g_incl.h"
#include "terminal.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "common.h"

G_Incl::G_Incl(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Incl::~G_Incl() {
  }

void G_Incl::Reset() {
  }

void G_Incl::Display() {
  GotoXY(x,y); Write("Inc: -999.99");
  }

void G_Incl::Update() {
  char   buffer[16];
  if ((vehicle->Type() & VT_SPACECRAFT) == 0) return;
  sprintf(buffer,"%7.2f",90+((Spacecraft*)vehicle)->Inclination());
  GotoXY(x+5,y); Write(buffer);
  }

