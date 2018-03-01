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
  GotoXY(x,y+0); printf("   ");
  }

void G_PilotLocation::Update() {
  if (pilotLocation != lastLocation) {
    GotoXY(x,y);
    switch (pilotLocation) {
      case PILOT_CSM: printf("CSM"); break;
      case PILOT_LRV: printf("LRV"); break;
      case PILOT_EVA: printf("EVA"); break;
      case PILOT_LM: printf("LM "); break;
      }
    lastLocation = pilotLocation;
    }
  }

