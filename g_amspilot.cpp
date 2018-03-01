#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amspilot.h"
#include "terminal.h"

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
  GotoXY(x,y+0); printf(" CSM| LM | LRV| EVA");
  }

void G_AmsPilot::Update() {
  if (pilotLocation != lastPilotLocation) {
    GotoXY(x+0,y); printf(" ");
    GotoXY(x+5,y); printf(" ");
    GotoXY(x+10,y); printf(" ");
    GotoXY(x+15,y); printf(" ");
    switch (pilotLocation) {
      case PILOT_CSM:
           GotoXY(x+0,y); printf("*");
           break;
      case PILOT_LM:
           GotoXY(x+5,y); printf("*");
           break;
      case PILOT_LRV:
           GotoXY(x+10,y); printf("*");
           break;
      case PILOT_EVA:
           GotoXY(x+15,y); printf("*");
           break;
      }
    lastPilotLocation = pilotLocation;
    }
  }

