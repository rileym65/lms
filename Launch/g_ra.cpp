#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_ra.h"
#include "terminal.h"

G_RightAscension::G_RightAscension(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_RightAscension::~G_RightAscension() {
  }

void G_RightAscension::Reset() {
  }

void G_RightAscension::Display() {
  GotoXY(x,y); Write("RtA: -999.99");
  }

void G_RightAscension::Update() {
  char   buffer[16];
  sprintf(buffer,"%8.2f",vehicle->Longitude());
  GotoXY(x+4,y); Write(buffer);
  }

