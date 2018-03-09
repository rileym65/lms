#include <stdio.h>
#include <string.h>
#include "terminal.h"
#include "types.h"
#include "mission.h"

Mission* mission;

void ClearScreen() {
  Int32 i,j;
  ClrScr();
  GotoXY(1,1);
  printf("+"); for (i=0; i<78; i++) printf("-"); printf("+\n");
  for (j=2; j<24; j++) {
    GotoXY(1,j);
    printf("|"); for (i=0; i<78; i++) printf(" "); printf("|\n");
    }
  GotoXY(1,24);
  printf("+"); for (i=0; i<78; i++) printf("-"); printf("+\n");
  }

void WriteCentered(Int32 x, Int32 y, const char* message) {
  x -= (strlen(message) / 2);
  GotoXY(x,y);
  printf("%s",message); fflush(stdout);
  }

void Menu() {
  ClearScreen();
  GotoXY(5,3); printf("A. Mission Name   :");
  if (mission->Name() == NULL) printf("Not Defined%s",LE);
    else printf("%s%s",mission->Name(),LE);
  GotoXY(5,4); printf("B. Landing Region :");
  if (mission->Region() == NULL) printf("Not Defined%s",LE);
    else printf("%s%s",mission->Region(),LE);
  GotoXY(5,5); printf("C. Landing Site   :");
  if (mission->TargetLatitude() < -180) printf("Not Defined%s",LE);
    else printf("Longitude: %7.2f, Latitude: %7.2f%s",
         mission->TargetLongitude(), mission->TargetLatitude(),LE);

  GotoXY(5,18); printf("S. Save and exit%s",LE);
  GotoXY(5,19); printf("Q. Quit without saving%s",LE);
  }

void MissionEditor() {
  int key;
  key = 0;
  Menu();
  while (key != 'q') {
    key = Inkey();
    }
  }

int main(int argc, char** argv) {
  int key;
  OpenTerminal();
  ClearScreen();
  WriteCentered(40,5,"Lunar Mission Simulator");
  WriteCentered(40,7,"Mission Planner");
  WriteCentered(40,10,"1. Create new mission profile   ");
  WriteCentered(40,11,"2. Load existing mission profile");
  WriteCentered(40,12,"3. Exit                         ");
  GotoXY(30, 14); printf("Option ? "); fflush(stdout);
  key = 0;
  while (key != '1' && key != '2' && key != '3') {
    key = Inkey();
    }
  if (key == '1') {
    mission = new Mission();
    MissionEditor();
    }

  GotoXY(1,25);
  CloseTerminal();
  }

