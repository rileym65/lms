#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsatt.h"
#include "terminal.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "common.h"

G_AmsAtt::G_AmsAtt(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 7;
  height = 4;
  Reset();
  }

G_AmsAtt::~G_AmsAtt() {
  }

void G_AmsAtt::Reset() {
  lastUr = -9999;
  lastFr = -9999;
  lastLs = -9999;
  }

void G_AmsAtt::Display() {
  GotoXY(x,y+0); Write("    att");
  GotoXY(x,y+1); Write("u/r:   ");
  GotoXY(x,y+2); Write("f/r:   ");
  GotoXY(x,y+3); Write("l/s:   ");
  }

void G_AmsAtt::Update() {
  Int32 i;
  char buffer[32];
  Spacecraft* sc;
  if ((vehicle->Type() & VT_SPACECRAFT) == 0) return;
  sc = (Spacecraft*)vehicle;
  i = (int)(acos(sc->Position().Norm().Dot(sc->FaceUp())) * 180 / M_PI + .4);
  if (lastUr != i) {
    GotoXY(x+4, y+1); sprintf(buffer,"%3d",i); Write(buffer);
    lastUr = i;
    }
  i = (int)(acos(sc->Position().Norm().Dot(sc->FaceFront())) * 180 / M_PI+.4);
  if (lastFr != i) {
    GotoXY(x+4, y+2); sprintf(buffer,"%3d",i); Write(buffer);
    lastFr = i;
    }
  i = (int)(acos(sc->FaceLeft().Dot(Vector(0,0,-1))) * 180 / M_PI +.4);
  if (lastLs != i) {
    GotoXY(x+4, y+3); sprintf(buffer,"%3d",i); Write(buffer);
    lastLs = i;
    }
  }

