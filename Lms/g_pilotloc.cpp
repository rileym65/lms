#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_pilotloc.h"
#include "terminal.h"

G_PilotLocation::G_PilotLocation(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 3;
  height = 1;
  Reset();
  }

G_PilotLocation::~G_PilotLocation() {
  }

void G_PilotLocation::Reset() {
  lastLocation = ' ';
  }

void G_PilotLocation::Display() {
  GotoXY(x,y+0); Write("   ");
  }

void G_PilotLocation::Update() {
  if (pilotLocation != lastLocation) {
    GotoXY(x,y);
    switch (pilotLocation) {
      case PILOT_CSM: Write("CSM"); break;
      case PILOT_LRV: Write("LRV"); break;
      case PILOT_EVA: Write("EVA"); break;
      case PILOT_LM: Write("LM "); break;
      }
    lastLocation = pilotLocation;
    }
  }

