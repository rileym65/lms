#include "header.h"

void Box(UInt32 x, UInt32 y, UInt32 width, UInt32 height) {
  UInt32 i;
  UInt32 j;
  GotoXY(x,y); Write("+");
  for (i=0; i<width-2; i++) Write("-");
  Write("+");
  for (j=0; j<height-2; j++) {
     GotoXY(x,y+j+1);
     Write("|");
     for (i=0; i<width-2; i++) Write(" ");
     Write("|");
    }
  GotoXY(x,y+height-1); Write("+");
  for (i=0; i<width-2; i++) Write("-");
  Write("+");
  Flush();
  }

