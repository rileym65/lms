#include "header.h"

void ShowMap() {
  UInt32 y;
  for (y=0; y<19; y++) {
    GotoXY(4,3+y);
    Write(cells[y]);
    }
  }

