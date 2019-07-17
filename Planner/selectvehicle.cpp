#include "header.h"

void SelectVehicle() {
  int key;
  Int8 vehicle;
  vehicle = mission->Vehicle();
  ClearScreen();
  ShowVehicle(vehicle);
  HideCursor(); Flush();
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if (key == KEY_DOWN_ARROW) {
      if (++vehicle > 4) vehicle = 1;
      ShowVehicle(vehicle);
      }
    if (key == KEY_UP_ARROW) {
      if (--vehicle < 1) vehicle = 3;
      ShowVehicle(vehicle);
      }
    }
  ShowCursor(); Flush();
  if (key == 13) mission->Vehicle(vehicle);
  }

