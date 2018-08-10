#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_lan.h"
#include "terminal.h"

G_Lan::G_Lan(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 12;
  height = 1;
  }

G_Lan::~G_Lan() {
  }

void G_Lan::Reset() {
  }

void G_Lan::Display() {
  GotoXY(x,y); Write("Lan: -999.99");
  }

void G_Lan::Update() {
  char   buffer[16];
  sprintf(buffer,"%7.2f",vehicle->Lan());
  GotoXY(x+5,y); Write(buffer);
  }

