#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsland.h"
#include "terminal.h"

G_AmsLand::G_AmsLand(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
  width = 13;
  height = 8;
  Reset();
  }

G_AmsLand::~G_AmsLand() {
  }

void G_AmsLand::Reset() {
  }

void G_AmsLand::Display() {
  GotoXY(x,y+0); printf("    land     ");
  GotoXY(x,y+1); printf(" +---w|----+ ");
  GotoXY(x,y+2); printf(" |         | ");
  GotoXY(x,y+3); printf(" |         |n");
  GotoXY(x,y+4); printf("--         --");
  GotoXY(x,y+5); printf("s|         | ");
  GotoXY(x,y+6); printf(" |         | ");
  GotoXY(x,y+7); printf(" +----|e---+ ");
  }

void G_AmsLand::Update() {
  }

