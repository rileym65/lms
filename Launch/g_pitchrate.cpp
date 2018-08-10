#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_pitchrate.h"
#include "terminal.h"

G_PitchRate::G_PitchRate(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 8;
  height = 1;
  }

G_PitchRate::~G_PitchRate() {
  }

void G_PitchRate::Reset() {
  }

void G_PitchRate::Display() {
  GotoXY(x,y); Write("PT:-99.9");
  }

void G_PitchRate::Update() {
  char   buffer[16];
  sprintf(buffer,"%+5.1f",vehicle->PitchRate());
  GotoXY(x+3,y); Write(buffer);
  }

