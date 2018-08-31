#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_radars.h"
#include "terminal.h"
#include "common.h"

G_Radars::G_Radars(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 4;
  height = 3;
  Reset();
  }

G_Radars::~G_Radars() {
  }

void G_Radars::Reset() {
  lastLandingRadarOn = -9999;
  lastDockingRadarOn = -9999;
  lastDsnOn = -9999;
  }

void G_Radars::Display() {
  GotoXY(x,y+0); Write(" LAN");
  GotoXY(x,y+1); Write(" DOK");
  GotoXY(x,y+2); Write(" DSN");
  }

void G_Radars::Update() {
  if (landingRadarOn != lastLandingRadarOn) {
    GotoXY(x+0, y+0);
    if (landingRadarOn) Write("@"); else Write(" ");
    lastLandingRadarOn = landingRadarOn;
    }
  if (dockingRadarOn != lastDockingRadarOn) {
    GotoXY(x+0, y+1);
    if (dockingRadarOn) Write("@"); else Write(" ");
    lastDockingRadarOn = dockingRadarOn;
    }
  if (dsnOn != lastDsnOn) {
    GotoXY(x+0, y+2);
    if (dsnOn) Write("@"); else Write(" ");
    lastDsnOn = dsnOn;
    }
  }

