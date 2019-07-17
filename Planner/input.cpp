#include "header.h"

Boolean Input(Int32 x, Int32 y, char* buffer, Boolean append) {
  int key;
  key = 0;
  if (!append) strcpy(buffer,"");
  GotoXY(x,y); fflush(stdout);
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if ((key == 8 || key == 127) && strlen(buffer) > 0) {
      buffer[strlen(buffer)-1] = 0;
      GotoXY(x,y); Write(buffer); Write(" "); fflush(stdout);
      }
    else if (key >= ' ' && key < 127) {
      buffer[strlen(buffer)+1] = 0;
      buffer[strlen(buffer)] = key;
      GotoXY(x,y); Write(buffer); fflush(stdout);
      }
    }
  if (key == 13) return true;
  return false;
  }

