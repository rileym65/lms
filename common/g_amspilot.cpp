#include "types.h"
#include "gauge.h"
#include "g_amspilot.h"
#include "terminal.h"
#include "common.h"

G_AmsPilot::G_AmsPilot(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 19;
  height = 1;
  Reset();
  }

G_AmsPilot::~G_AmsPilot() {
  }

void G_AmsPilot::Reset() {
  lastPilotLocation = ' ';
  }

void G_AmsPilot::Display() {
  GotoXY(x,y+0); Write(" CSM| LM | LRV| EVA");
  }

void G_AmsPilot::Update() {
  if (pilotLocation != lastPilotLocation) {
    GotoXY(x+0,y); Write(" ");
    GotoXY(x+5,y); Write(" ");
    GotoXY(x+10,y); Write(" ");
    GotoXY(x+15,y); Write(" ");
    switch (pilotLocation) {
      case PILOT_CSM:
           GotoXY(x+0,y); Write("*");
           break;
      case PILOT_LM:
           GotoXY(x+5,y); Write("*");
           break;
      case PILOT_LRV:
           GotoXY(x+10,y); Write("*");
           break;
      case PILOT_EVA:
           GotoXY(x+15,y); Write("*");
           break;
      }
    lastPilotLocation = pilotLocation;
    }
  }

