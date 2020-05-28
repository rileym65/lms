#include "header.h"

void SelectOrbit() {
  int key;
  Double d;
  char buffer[128];
  ClearScreen();
  GotoXY(36, 3); Write("CSM Orbit");
  GotoXY(23, 6); Write("1. Longitude of Ascending Node : ");
  GotoXY(23, 8); Write("2. Inclination                 : ");
  sprintf(buffer,"%6.2f",mission->StartLAN());
  GotoXY(56,6); Write(buffer);
  sprintf(buffer,"%6.2f",mission->StartInc());
  GotoXY(56,8); Write(buffer);
  GotoXY(26, 10); Write("Option (Q to quit) ? ");
  Flush();
  while (key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if (key == 'q') key = 27;
    if (key == 'Q') key = 27;
    if (key == '1') {
      GotoXY(56, 6); Write("              ");
      if (Input(56, 6, buffer, false)) {
        d = atof(buffer);
        if (d >= 0 && d < 360) mission->StartLAN(d);
        GotoXY(56, 6); Write("              ");
        sprintf(buffer,"%6.2f",mission->StartLAN());
        GotoXY(56,6); Write(buffer);
        }
      GotoXY(26, 10); Write("Option (Q to quit) ? ");
      Flush();
      }
    if (key == '2') {
      GotoXY(56, 8); Write("              ");
      if (Input(56, 8, buffer, false)) {
        d = atof(buffer);
        if (d >= 0 && d < 45) mission->StartInc(d);
        GotoXY(56, 8); Write("              ");
        sprintf(buffer,"%6.2f",mission->StartInc());
        GotoXY(56,8); Write(buffer);
        }
      GotoXY(26, 10); Write("Option (Q to quit) ? ");
      Flush();
      }
    }
  }

