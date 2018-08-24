#include "types.h"
#include "gauge.h"
#include "g_battery.h"
#include "terminal.h"
#include "vehicle.h"

G_Battery::G_Battery(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 7;
  height = 1;
  Reset();
  }

G_Battery::~G_Battery() {
  }

void G_Battery::Reset() {
  }

void G_Battery::Display() {
  GotoXY(x+0,y+0);
  Write("Bat: 99");
  }

void G_Battery::Update() {
  UInt32 i;
  char buffer[10];
  GotoXY(x+5,y+0);
  i = (vehicle->Battery() / vehicle->MaxBattery()) * 100.0;
  if (i > 99) i = 99;
  sprintf(buffer,"%2d",i);
  Write(buffer);
  }

