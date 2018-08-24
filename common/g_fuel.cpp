#include "types.h"
#include "gauge.h"
#include "g_fuel.h"
#include "terminal.h"
#include "vehicle.h"

G_Fuel::G_Fuel(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 3;
  height = 3;
  Reset();
  }

G_Fuel::~G_Fuel() {
  }

void G_Fuel::Reset() {
  }

void G_Fuel::Display() {
  Byte i;
  char buffer[10];
  for (i=0; i<vehicle->NumStages(); i++) {
    GotoXY(x+0,y+i);
    sprintf(buffer,"Fs%d: --",i+1);
    Write(buffer);
    }
  }

void G_Fuel::Update() {
  UInt32 f;
  char buffer[10];
  f = (vehicle->Fuel() / vehicle->MaxFuel()) * 100.0;
  if (f > 99) f = 99;
  GotoXY(x+5,y+vehicle->Stage()-1);
  sprintf(buffer,"%2d",f);
  Write(buffer);
  }

