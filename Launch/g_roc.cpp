#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_roc.h"
#include "terminal.h"

G_Roc::G_Roc(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Roc::~G_Roc() {
  }

void G_Roc::Reset() {
  lastAltitude = 0;
  }

void G_Roc::Display() {
  GotoXY(x,y); Write("Roc:-9999999");
  }

void G_Roc::Update() {
  Vector pos;
  Double rad;
  char   buffer[16];
  pos = vehicle->Position();
  rad = vehicle->Position().Length() - GROUND;
  sprintf(buffer,"%8.0f",rad-lastAltitude);
  GotoXY(x+4,y); Write(buffer);
  lastAltitude = rad;
  }

