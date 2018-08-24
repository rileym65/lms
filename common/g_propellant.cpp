#include "types.h"
#include "gauge.h"
#include "g_propellant.h"
#include "terminal.h"
#include "vehicle.h"

G_Propellant::G_Propellant(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 7;
  height = 1;
  Reset();
  }

G_Propellant::~G_Propellant() {
  }

void G_Propellant::Reset() {
  }

void G_Propellant::Display() {
  GotoXY(x+0,y+0);
  Write("Prp: 99");
  }

void G_Propellant::Update() {
  UInt32 f;
  char buffer[10];
  GotoXY(x+5,y+0);
  if (vehicle->MaxFuel() > 0) {
    f = (vehicle->Fuel() / vehicle->MaxFuel()) * 100.0;
    if (f > 99) f = 99;
    sprintf(buffer,"%2d",f);
    Write(buffer);
    }
  else Write("--");
  }

