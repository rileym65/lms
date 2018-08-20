#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_dec.h"
#include "terminal.h"

G_Declination::G_Declination(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Declination::~G_Declination() {
  }

void G_Declination::Reset() {
  }

void G_Declination::Display() {
  GotoXY(x,y); Write("Dec: -999.99");
  }

void G_Declination::Update() {
  char   buffer[16];
  sprintf(buffer,"%8.2f",vehicle->Latitude());
  GotoXY(x+4,y); Write(buffer);
  }

