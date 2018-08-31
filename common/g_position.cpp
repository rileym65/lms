#include "types.h"
#include "gauge.h"
#include "common.h"
#include "g_position.h"
#include "terminal.h"
#include "vehicle.h"

G_Position::G_Position(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 13;
  height = 3;
  }

G_Position::~G_Position() {
  }

void G_Position::Reset() {
  }

void G_Position::Display() {
  GotoXY(x,y+0); Write("Lat:  +99.99");
  GotoXY(x,y+1); Write("Lng: +999.99");
  GotoXY(x,y+2); Write("Gnd: +999.99");
  }

void G_Position::Update() {
  char buffer[32];
  Double d;
  sprintf(buffer,"%+8.3f",vehicle->Latitude());
  GotoXY(x+5,y+0); Write(buffer);
  d = vehicle->Longitude();
  sprintf(buffer,"%+8.3f",vehicle->Longitude());
  GotoXY(x+5,y+1); Write(buffer);
  d = d - kscAngle - 80.6077;
  while (d >= 180) d -= 360;
  while (d <= -180) d += 360;
  sprintf(buffer,"%+8.2f",d);
  GotoXY(x+5,y+2); Write(buffer);
  }

