#include "header.h"

void WriteCentered(Int32 x, Int32 y, const char* message) {
  char buffer[128];
  x -= (strlen(message) / 2);
  GotoXY(x,y);
  sprintf(buffer,"%s",message);
  Write(buffer);
  fflush(stdout);
  }

