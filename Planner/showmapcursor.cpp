#include "header.h"

void ShowMapCursor(Int32 x, Int32 y) {
  GotoXY(33+x,10+y); Write("|");
  GotoXY(33+x,11+y); Write("|");
  GotoXY(33+x,13+y); Write("|");
  GotoXY(33+x,14+y); Write("|");
  GotoXY(31+x,12+y); Write("--");
  GotoXY(34+x,12+y); Write("--");
  Flush();
  }

