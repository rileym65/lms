#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_altitude.h"
#include "terminal.h"

G_Altitude::G_Altitude(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Altitude::~G_Altitude() {
  }

void G_Altitude::Reset() {
  }

void G_Altitude::Display() {
  GotoXY(x,y); Write("Alt:-9999999");
  }

void G_Altitude::Update() {
  Vector pos;
  Double rad;
  char   buffer[16];
  pos = vehicle->Position() - vehicle->Orbiting()->Position();
  rad = pos.Length() - vehicle->Orbiting()->Radius();
  if (rad < 1000000) sprintf(buffer,"%8.0f",rad);
    else sprintf(buffer,"%8.1f",rad / 1000);
  GotoXY(x+4,y); Write(buffer);
  }

