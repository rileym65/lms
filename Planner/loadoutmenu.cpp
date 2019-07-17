#include "header.h"

void LoadoutMenu() {
  ClearScreen();
  WriteCentered(40,2,"Mission Loadout");
  GotoXY(M1, 4); Write("Ascent Stage");
  GotoXY(M2, 5); Write("   Empty Weight:");
  GotoXY(M2, 6); Write("A. Ascent Fuel :");
  GotoXY(M2, 7); Write("B. RCS Fuel    :");
  GotoXY(M2, 8); Write("   Full Weight :");
  GotoXY(M2, 9); Write("   Delta V     :");
  GotoXY(M1,11); Write("Descent Stage");
  GotoXY(M2,12); Write("   Empty Weight:");
  GotoXY(M2,13); Write("C. Descent Fuel:");
  GotoXY(M2,14); Write("D. Consumables :");
  GotoXY(M2,15); Write("E. Rover       :");
  GotoXY(M2,16); Write("F. Experiments :");
  GotoXY(M2,17); Write("G. LLRE        :");
  GotoXY(M2,18); Write("   Full Weight :");
  GotoXY(M2,19); Write("   Delta V     :");
  GotoXY(M2,21); Write("Mission Weight :");
  }

