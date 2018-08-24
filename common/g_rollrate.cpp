#include "types.h"
#include "gauge.h"
#include "g_rollrate.h"
#include "terminal.h"
#include "vehicle.h"

G_RollRate::G_RollRate(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 8;
  height = 1;
  }

G_RollRate::~G_RollRate() {
  }

void G_RollRate::Reset() {
  }

void G_RollRate::Display() {
  GotoXY(x,y); Write("RL:-99.9");
  }

void G_RollRate::Update() {
  char   buffer[16];
  sprintf(buffer,"%+5.1f",vehicle->RollRate());
  GotoXY(x+3,y); Write(buffer);
  }

