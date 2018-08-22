#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_moon.h"
#include "terminal.h"

G_Moon::G_Moon(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 24;
  height = 3;
  }

G_Moon::~G_Moon() {
  }

void G_Moon::Reset() {
  }

void G_Moon::Display() {
  GotoXY(x,y+0); Write("Moon           G: -99.99");
  GotoXY(x,y+1); Write("Dst: 999999  Ang: -99.99");
  GotoXY(x,y+2); Write("Ra: -100.00  Dec: -99.99");
  }

void G_Moon::Update() {
  char buffer[20];
  Double d;
  sprintf(buffer,"%6.0f",Moon->Position().Length() / 1000.0);
  GotoXY(x+5, y+1); Write(buffer);
  sprintf(buffer,"%7.2f",Moon->Longitude());
  GotoXY(x+4,y+2); Write(buffer);
  sprintf(buffer,"%6.2f",Moon->Latitude());
  GotoXY(x+18,y+2); Write(buffer);
  d = (Moon->Longitude() + 360) - (vehicle->Longitude() + 360) - 360;
  if (d >= 180) d -= 260;
  if (d <= -180) d += 360;
  sprintf(buffer,"%6.2f",d);
  GotoXY(x+18,y+1); Write(buffer);
  sprintf(buffer,"%7.2f",((Spacecraft*)vehicle)->MoonG());
  GotoXY(x+17,y+0); Write(buffer);
  }

