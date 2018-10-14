#include "types.h"
#include "gauge.h"
#include "g_yawrate.h"
#include "terminal.h"
#include "vehicle.h"

G_YawRate::G_YawRate(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 8;
  height = 1;
  }

G_YawRate::~G_YawRate() {
  }

void G_YawRate::Reset() {
  }

void G_YawRate::Display() {
  GotoXY(x,y); Write("YW:-99.9");
  }

void G_YawRate::Update() {
  char   buffer[16];
  sprintf(buffer,"%+5.1f",vehicle->YawRate());
  GotoXY(x+3,y); Write(buffer);
  }

