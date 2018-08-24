#include "types.h"
#include "gauge.h"
#include "g_oxygen.h"
#include "terminal.h"
#include "vehicle.h"

G_Oxygen::G_Oxygen(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 7;
  height = 1;
  Reset();
  }

G_Oxygen::~G_Oxygen() {
  }

void G_Oxygen::Reset() {
  }

void G_Oxygen::Display() {
  GotoXY(x+0,y+0);
  Write("Oxy: 99");
  }

void G_Oxygen::Update() {
  UInt32 i;
  char buffer[10];
  GotoXY(x+5,y+0);
  i = (vehicle->Oxygen() / vehicle->MaxOxygen()) * 100.0;
  if (i > 99) i = 99;
  sprintf(buffer,"%2d",i);
  Write(buffer);
  }

