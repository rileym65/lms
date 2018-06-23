#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "terminal.h"
#include "types.h"
#include "mission.h"
#include "map.h"

Mission* mission;

char** categories;
UInt32 numCategories;
FEATURE *features;
UInt32    numFeatures;
Map*     map;

Boolean CategoryExists(char* name) {
  UInt32 i;
  for (i=0; i<numCategories; i++)
    if (strcasecmp(categories[i],name) == 0) return true;
  return false;
  }

void LoadCategories() {
  UInt32 i;
  UInt32 len;
  Boolean flag;
  char   cat[128];
  char*  pos;
  for (i=0; i<numFeatures; i++) {
    pos = strchr(features[i].name,' ');
    if (pos != NULL) {
      len = pos - features[i].name;
      strncpy(cat,features[i].name,len);
      cat[len] = 0;
      if (!CategoryExists(cat)) {
        if (++numCategories == 1)
          categories = (char**)malloc(sizeof(char*));
        else
          categories = (char**)realloc(categories, sizeof(char*) * numCategories);
        categories[numCategories-1] = (char*)malloc(strlen(cat) + 1);
        strcpy(categories[numCategories-1], cat);
        }
      }
    }
  flag = true;
  while (flag) {
    flag = false;
    for (i=0; i<numCategories-1; i++)
      if (strcmp(categories[i],categories[i+1]) > 0) {
        pos = categories[i];
        categories[i] = categories[i+1];
        categories[i+1] = pos;
        flag = true;
        }
    }
for (i=0; i<numCategories; i++)
printf("%s\n",categories[i]);

  }

void ClearScreen() {
  Int32 i,j;
  ClrScr();
  GotoXY(1,1);
  Write("+"); for (i=0; i<78; i++) Write("-"); WriteLn("+");
  for (j=2; j<24; j++) {
    GotoXY(1,j);
    Write("|"); for (i=0; i<78; i++) Write(" "); WriteLn("|");
    }
  GotoXY(1,24);
  Write("+"); for (i=0; i<78; i++) Write("-"); WriteLn("+");
  }

void WriteCentered(Int32 x, Int32 y, const char* message) {
  char buffer[128];
  x -= (strlen(message) / 2);
  GotoXY(x,y);
  sprintf(buffer,"%s",message);
  Write(buffer);
  fflush(stdout);
  }

void Menu() {
  char buffer[128];
  ClearScreen();
  GotoXY(5,3); Write("A. Mission Name   :");
  if (mission->Name() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Name());
      WriteLn(buffer);
      }
  GotoXY(5,4); Write("B. Landing Region :");
  if (mission->Region() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Region());
      WriteLn(buffer);
      }
  GotoXY(5,5); Write("C. Landing Site   :");
  if (mission->TargetLatitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Longitude: %7.2f, Latitude: %7.2f",
         mission->TargetLongitude(), mission->TargetLatitude());
      WriteLn(buffer);
      }

  GotoXY(5,18); WriteLn("S. Save and exit");
  GotoXY(5,19); WriteLn("Q. Quit without saving");
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
  UInt32 i;
  int key;
  map = new Map();
  features = map->Features();
  numFeatures = map->NumFeatures();
  LoadCategories();
  OpenTerminal();
  ClearScreen();
  WriteCentered(40,5,"Lunar Mission Simulator");
  WriteCentered(40,7,"Mission Planner");
  WriteCentered(40,10,"1. Create new mission profile   ");
  WriteCentered(40,11,"2. Load existing mission profile");
  WriteCentered(40,12,"3. Exit                         ");
  GotoXY(30, 14); Write("Option ? "); fflush(stdout);
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
  for (i=0; i<numCategories; i++)
    free(categories[i]);
  free(categories);
  }

