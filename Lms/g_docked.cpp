#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_docked.h"
#include "terminal.h"
#include "common.h"

G_Docked::G_Docked(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 3;
  height = 1;
  Reset();
  }

G_Docked::~G_Docked() {
  }

void G_Docked::Reset() {
  lastDocked = -999;
  }

void G_Docked::Display() {
  GotoXY(x,y+0); Write(" DK");
  }

void G_Docked::Update() {
  if (docked != lastDocked) {
    GotoXY(x+0,y+0);
    if (docked) Write("^"); else Write(" ");
    lastDocked = docked;
    }
  }

