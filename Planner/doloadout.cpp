#include "header.h"

void DoLoadout() {
  int key;
  int i;
  Double v;
  char buffer[80];
  HideCursor();
  LoadoutMenu();
  ShowLoadout();
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if (key == 'a' || key == 'A') {
      sprintf(buffer,"Enter Ascent Fuel (max: %.0f):",mission->Model()->AscentFuel());
      v = NumericDialog(buffer,mission->Model()->AscentFuel());
      if (v > 0) mission->AscentFuel(v);
      LoadoutMenu();
      ShowLoadout();
      }
    if (key == 'b' || key == 'B') {
      sprintf(buffer,"Enter RCS Fuel (max: %.0f):",mission->Model()->RcsFuel());
      v = NumericDialog(buffer,mission->Model()->RcsFuel());
      if (v > 0) mission->RcsFuel(v);
      LoadoutMenu();
      ShowLoadout();
      }
    if (key == 'c' || key == 'C') {
      sprintf(buffer,"Enter Descent Fuel (max: %.0f):",mission->Model()->DescentFuel());
      v = NumericDialog(buffer,mission->Model()->DescentFuel());
      if (v > 0) mission->DescentFuel(v);
      LoadoutMenu();
      ShowLoadout();
      }
    if (key == 'd' || key == 'D') {
      sprintf(buffer,"Enter Consumables (max: %d):",mission->Model()->Consumables() / 3600);
      v = NumericDialog(buffer,mission->Model()->Consumables() / 3600);
      if (v > 0) mission->Consumables(v * 3600);
      LoadoutMenu();
      ShowLoadout();
      }
    if (key == 'g' || key == 'G') {
      mission->Laser((mission->Laser() == 0) ? 1 : 0);
      ShowLoadout();
      }
    if (key == 'f' || key == 'F') {
      i = mission->Lsep() + 1;
      if (i > 2) i = 0;
      mission->Lsep(i);
      ShowLoadout();
      }
    if (key == 'e' || key == 'E') {
      i = mission->Rover() + 1;
      if (i >= mission->Vehicle()) i = 0;
      mission->Rover(i);
      ShowLoadout();
      }
    }
  ShowCursor();
  }

