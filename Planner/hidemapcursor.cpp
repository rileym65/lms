#include "header.h"

void HideMapCursor(Int32 x, Int32 y) {
  GotoXY(33+x,10+y); WriteCh(cells[y+7][x+29]);
  GotoXY(33+x,11+y); WriteCh(cells[y+8][x+29]);
  GotoXY(33+x,13+y); WriteCh(cells[y+10][x+29]);
  GotoXY(33+x,14+y); WriteCh(cells[y+11][x+29]);
  GotoXY(31+x,12+y); WriteCh(cells[y+9][x+27]);
  GotoXY(32+x,12+y); WriteCh(cells[y+9][x+28]);
  GotoXY(34+x,12+y); WriteCh(cells[y+9][x+30]);
  GotoXY(35+x,12+y); WriteCh(cells[y+9][x+31]);
  Flush();
  }

