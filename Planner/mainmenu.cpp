#include "header.h"

void MainMenu() {
  ClearScreen();
  WriteCentered(40,5,"Lunar Mission Simulator");
  WriteCentered(40,7,"Mission Planner");
  WriteCentered(40,10,"1. Create new mission profile   ");
  WriteCentered(40,11,"2. Load existing mission profile");
  WriteCentered(40,12,"3. Exit                         ");
  GotoXY(30, 14); Write("Option ? "); fflush(stdout);
  }

