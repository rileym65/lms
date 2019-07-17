#include "header.h"

Double NumericDialog(char* msg, Double max) {
  int key;
  char buffer[20];
  Double v;
  Double t;
  UInt32 x,y;
  x = 40 - ((strlen(msg)+2) / 2);
  y = 10;
  v = 0;
  Box(x, y, strlen(msg)+4,4);
  GotoXY(x+2,y+1); Write(msg);
  strcpy(buffer,"");
  ShowCursor();
  GotoXY(38,y+2); Flush();
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if ((key == 8 || key == 127) && strlen(buffer) > 0) {
      buffer[strlen(buffer)-1] = 0;
      GotoXY(38, y+2); Write(buffer); Write(" ");
      GotoXY(38+strlen(buffer),y+2);
      Flush();
      }
    if (key >= '0' && key <= '9') {
      buffer[strlen(buffer)+1] = 0;
      buffer[strlen(buffer)] = key;
      t = atof(buffer);
      if (t > max) {
        buffer[strlen(buffer)-1] = 0;
        }
      GotoXY(38, y+2); Write(buffer); Write(" ");
      GotoXY(38+strlen(buffer),y+2);
      Flush();
      }
    }
  v = atof(buffer);
  HideCursor();
  if (key == 27) return -1;
  return v;
  }

