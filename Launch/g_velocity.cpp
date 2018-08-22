#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_velocity.h"
#include "terminal.h"

G_Velocity::G_Velocity(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Velocity::~G_Velocity() {
  }

void G_Velocity::Reset() {
  }

void G_Velocity::Display() {
  GotoXY(x,y); Write("Vel:-9999999");
  }

void G_Velocity::Update() {
  Vector vel;
  char   buffer[16];
  vel = vehicle->Velocity() - vehicle->Orbiting()->Velocity();
  sprintf(buffer,"%8.1f",vel.Length());
  GotoXY(x+4,y); Write(buffer);
  }

