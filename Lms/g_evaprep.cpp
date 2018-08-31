#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_evaprep.h"
#include "terminal.h"
#include "common.h"

G_EvaPrep::G_EvaPrep(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 20;
  height = 1;
  Reset();
  }

G_EvaPrep::~G_EvaPrep() {
  }

void G_EvaPrep::Reset() {
  lastSpaceSuitOn = -9999;
  lastPlssOn = -9999;
  lastCabinPressurized = -9999;
  lastPacks = -9999;
  }

void G_EvaPrep::Display() {
  GotoXY(x,y+0); Write("PAK:     SS  PL  CB ");
  }

void G_EvaPrep::Update() {
  char buffer[5];
  if (spaceSuitOn != lastSpaceSuitOn) {
    GotoXY(x+8,y+0);
    if (spaceSuitOn) Write("@"); else Write(" ");
    lastSpaceSuitOn = spaceSuitOn;
    }
  if (plssOn != lastPlssOn) {
    GotoXY(x+12,y+0);
    if (plssOn) Write("@"); else Write(" ");
    lastPlssOn = plssOn;
    }
  if (cabinPressurized != lastCabinPressurized) {
    GotoXY(x+16,y+0);
    if (cabinPressurized) Write("@"); else Write(" ");
    lastCabinPressurized = cabinPressurized;
    }
  if (plssPacks != lastPacks) {
    GotoXY(x+4,y+0);
    sprintf(buffer,"%2d",plssPacks);
    Write(buffer);
    lastPacks = plssPacks;
    }
  }

