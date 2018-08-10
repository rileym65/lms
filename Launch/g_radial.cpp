#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_radial.h"
#include "terminal.h"

G_Radial::G_Radial(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 10;
  height = 3;
  }

G_Radial::~G_Radial() {
  }

void G_Radial::Reset() {
  }

void G_Radial::Display() {
  GotoXY(x,y+0); Write("u/r:-999.9");
  GotoXY(x,y+1); Write("f/r:-999.9");
  GotoXY(x,y+2); Write("l/r:-999.9");
  }

void G_Radial::Update() {
  Vector v1;
  Vector v2;
  Double d;
  char   buffer[16];
  v1 = vehicle->Position().Norm();
  v2 = vehicle->FaceUp().Norm();
  d = acos(v1.Dot(v2)) * 180 / M_PI;
  sprintf(buffer,"%6.1f",d);
  GotoXY(x+4,y+0); Write(buffer);
  v2 = vehicle->FaceFront().Norm();
  d = acos(v1.Dot(v2)) * 180 / M_PI;
  sprintf(buffer,"%6.1f",d);
  GotoXY(x+4,y+1); Write(buffer);
  v2 = vehicle->FaceLeft().Norm();
  d = acos(v1.Dot(v2)) * 180 / M_PI;
  sprintf(buffer,"%6.1f",d);
  GotoXY(x+4,y+2); Write(buffer);
  }

