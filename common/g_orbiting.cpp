#include "types.h"
#include "gauge.h"
#include "g_orbiting.h"
#include "terminal.h"
#include "vehicle.h"

G_Orbiting::G_Orbiting(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 6;
  height = 1;
  }

G_Orbiting::~G_Orbiting() {
  }

void G_Orbiting::Reset() {
  }

void G_Orbiting::Display() {
  GotoXY(x,y); Write("      ");
  }

void G_Orbiting::Update() {
  char buffer[20];
  sprintf(buffer,"%-6s",vehicle->Orbiting()->Name());
  GotoXY(x,y); Write(buffer);
  }

