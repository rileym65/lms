#include "types.h"
#include "gauge.h"
#include "g_accel.h"
#include "terminal.h"
#include "vehicle.h"

G_Accel::G_Accel(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Accel::~G_Accel() {
  }

void G_Accel::Reset() {
  lastVelocity = 0;
  }

void G_Accel::Display() {
  GotoXY(x,y); Write("Acc:-9999999");
  }

void G_Accel::Update() {
  Vector vel;
  Double v;
  Double acc;
  char   buffer[16];
  vel = vehicle->Velocity() - vehicle->Orbiting()->Velocity();
  v = vel.Length();
  acc = v - lastVelocity;
  sprintf(buffer,"%8.1f",acc);
  GotoXY(x+4,y); Write(buffer);
  lastVelocity = v;
  }

