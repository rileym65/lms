#include "types.h"
#include "common.h"
#include "gauge.h"
#include "g_fuel.h"
#include "terminal.h"
#include "vehicle.h"
#include "booster.h"
#include "command.h"

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
  Byte i;
  UInt32 f;
  char buffer[10];
  Booster* lv;
  if ((vehicle->Type() & VT_COMMAND) == 0) return;
  lv = ((CommandModule*)vehicle)->LaunchVehicle();
  if (((CommandModule*)vehicle)->LaunchVehicleJettisoned()) {
    for (i=0; i<lv->NumStages(); i++) {
      GotoXY(x+5,y+i);
      sprintf(buffer,"--");
      Write(buffer);
      }
    }
  else {
    for (i=0; i<lv->NumStages(); i++) {
      f = (lv->Fuel(i+1) / lv->MaxFuel(i+1)) * 100.0;
      if (f > 99) f = 99;
      GotoXY(x+5,y+i);
      sprintf(buffer,"%2d",f);
      Write(buffer);
      }
    }
  }

