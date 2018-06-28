#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "terminal.h"
#include "types.h"
#include "mission.h"
#include "map.h"

#define CELL 0.000329608

Mission* mission;

char** categories;
UInt32 numCategories;
FEATURE *features;
UInt32    numFeatures;
Map*     map;
UInt16   selections[10000];
UInt16   numSelections;
char     cells[21][61];

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

void Flush() {
  fflush(stdout);
  }

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

void ClearScreen() {
  ClrScr();
  GotoXY(1,1);
  Box(1,1,80,24);
  }

void WriteCentered(Int32 x, Int32 y, const char* message) {
  char buffer[128];
  x -= (strlen(message) / 2);
  GotoXY(x,y);
  sprintf(buffer,"%s",message);
  Write(buffer);
  fflush(stdout);
  }

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

void ShowSelections(UInt32 top, UInt32 count) {
  UInt32 i;
  UInt32 f;
  char lat[20];
  char lng[20];
  char buffer[80];
  Box(3,2,76,20);
  for (i=0; i<count; i++) {
    f = selections[top+i];
    if (features[f].latitude < 0)
      sprintf(lat,"%6.2fS",-features[f].latitude);
    else
      sprintf(lat,"%6.2fN",features[f].latitude);
    if (features[f].longitude < 0)
      sprintf(lng,"%7.2fW",-features[f].longitude);
    else
      sprintf(lng,"%7.2fE",features[f].longitude);
    sprintf(buffer,"%-50s %-8s %-8s",features[f].name,lat,lng);
    GotoXY(9,3+i); Write(buffer);
    }
  Flush();
  }

void GetRegion() {
  int key;
  int top;
  int line;
  int count;
  int len;
  UInt32 i;
  HideCursor();
  Box(20,2,40,20);
  top = 0;
  i = 0;
  count = 0;
  while (i < numCategories && count < 17) {
    GotoXY(26, 4+i); Write(categories[top+i]);
    i++;
    count++;
    }
  key = 0;
  line = 0;
  GotoXY(36,3); Write("Category:"); Flush();
  GotoXY(21,4+line); Write("--->"); Flush();
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if (key == KEY_UP_ARROW) {
      GotoXY(21,4+line); Write("    "); Flush();
      line--;
      if (line < 0) line = count-1;
      GotoXY(21,4+line); Write("--->"); Flush();
      }
    if (key == KEY_DOWN_ARROW) {
      GotoXY(21,4+line); Write("    "); Flush();
      line++;
      if (line >= count) line = 0;
      GotoXY(21,4+line); Write("--->"); Flush();
      }
    }
  if (key == 27) return;
  numSelections = 0;
  for (i=0; i<numFeatures; i++) {
    len = strlen(categories[top+line]);
    if (strncasecmp(features[i].name,categories[top+line],len) == 0)
      selections[numSelections++] = i;
    }
  top = 0;
  key = 0;
  line = 0;
  count = (numSelections < 18) ? numSelections : 18;
  ShowSelections(top, count);
  GotoXY(4,3+line); Write("--->"); Flush();
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if (key == KEY_UP_ARROW) {
      GotoXY(4,3+line); Write("    "); Flush();
      line--;
      if (line < 0) {
        top--;
        line = 0;
        if (top < 0) top = 0;
        count = numSelections - top;
        if (count > 18) count = 18;
        ShowSelections(top, count);
        }
      GotoXY(4,3+line); Write("--->"); Flush();
      }
    if (key == KEY_DOWN_ARROW) {
      GotoXY(4,3+line); Write("    "); Flush();
      line++;
      if (line >= count) {
        line--;
        top++;
        count = 18;
        if (top + count >= numSelections) {
          top--;
          count = numSelections - top;
          if (count > 18) count = 18;
          }
        ShowSelections(top, count);
        }
      GotoXY(4,3+line); Write("--->"); Flush();
      }
    if (key == KEY_PGDN) {
      GotoXY(4,3+line); Write("    "); Flush();
      top += 18;
      line = 0;
      count = 18;
      if (top + count >= numSelections) {
        top = numSelections - 18;
        if (top < 0) top = 0;
        }
      ShowSelections(top, count);
      GotoXY(4,3+line); Write("--->"); Flush();
      }
    if (key == KEY_PGUP) {
      GotoXY(4,3+line); Write("    "); Flush();
      top -= 18;
      if (top < 0) top = 0;
      count = 18;
      if (count >= numSelections) count = numSelections;
      ShowSelections(top, count);
      GotoXY(4,3+line); Write("--->"); Flush();
      }
    }
  if (key == 13) {
    mission->Region(features[selections[line+top]].name);
    mission->TargetLongitude(features[selections[line+top]].longitude);
    mission->TargetLatitude(features[selections[line+top]].latitude);
    }

  ShowCursor();
  }

void Menu() {
  char buffer[256];
  ClearScreen();
  GotoXY(5,3); Write("1. Mission Name   :");
  if (mission->Name() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Name());
      WriteLn(buffer);
      }
  GotoXY(5,4); Write("2. Description    :");
  if (mission->Description() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Description());
      WriteLn(buffer);
      }
  GotoXY(5,5); Write("3. Landing Region :");
  if (mission->Region() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Region());
      WriteLn(buffer);
      }
  GotoXY(5,6); Write("4. Landing Site   :");
  if (mission->TargetLatitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %7.2f, Longitude: %7.2f",
         mission->TargetLatitude(), mission->TargetLongitude());
      WriteLn(buffer);
      }

  GotoXY(5,18); WriteLn("S. Save and exit");
  GotoXY(5,19); WriteLn("Q. Quit without saving");
  GotoXY(8,21); Write("Option ? ");
  fflush(stdout);
  }

void LoadMap(Double latitude, Double longitude, UInt32 level) {
  UInt32 x,y;
  for (y=0; y<19; y++) {
    for (x=0; x<59; x++)
      cells[y][x] = map->Lurrain(longitude+((Double)y-9.0)*0.000329608,
                                 latitude+((Double)x-29.0)*0.000329608);
    cells[y][59] = 0;
    }
  }

void ShowMap() {
  UInt32 y;
  for (y=0; y<19; y++) {
    GotoXY(4,3+y);
    Write(cells[y]);
    }
  }

void ShowMapCursor(Int32 x, Int32 y) {
  GotoXY(33+x,10+y); Write("|");
  GotoXY(33+x,11+y); Write("|");
  GotoXY(33+x,13+y); Write("|");
  GotoXY(33+x,14+y); Write("|");
  GotoXY(31+x,12+y); Write("--");
  GotoXY(34+x,12+y); Write("--");
  Flush();
  }

void HideMapCursor(Int32 x, Int32 y) {
  GotoXY(33+x,10+y); WriteCh(cells[y+7][x+29]);
  GotoXY(33+x,11+y); WriteCh(cells[y+8][x+29]);
  GotoXY(33+x,13+y); WriteCh(cells[y+10][x+29]);
  GotoXY(33+x,14+y); WriteCh(cells[y+11][x+29]);
  GotoXY(31+x,12+y); WriteCh(cells[y+9][x+27]);
  GotoXY(32+x,12+y); WriteCh(cells[y+9][x+28]);
  GotoXY(34+x,12+y); WriteCh(cells[y+9][x+30]);
  GotoXY(35+x,12+y); WriteCh(cells[y+9][x+31]);
  Flush();
  }

Boolean SelectFromMap(Double* latitude, Double* longitude) {
  int key;
  int cursorX;
  int cursorY;
  Double centerLat;
  Double centerLng;
  char buffer[128];
  centerLat = *latitude;
  centerLng = *longitude;
  LoadMap(*latitude,*longitude,0);
  ClearScreen();
  Box(3,2,61,21);
  GotoXY(66,3); Write("Latitude:");
  sprintf(buffer,"%9.4f",*latitude);
  GotoXY(66,4); Write(buffer);
  GotoXY(66,6); Write("Longitude:");
  sprintf(buffer,"%9.4f",*longitude);
  GotoXY(66,7); Write(buffer);
  GotoXY(2,10); Write("S");
  GotoXY(2,11); Write("O");
  GotoXY(2,12); Write("U");
  GotoXY(2,13); Write("T");
  GotoXY(2,14); Write("H");
  GotoXY(64,10); Write("N");
  GotoXY(64,11); Write("O");
  GotoXY(64,12); Write("R");
  GotoXY(64,13); Write("T");
  GotoXY(64,14); Write("H");
  GotoXY(31,23); Write("EAST");
  ShowMap();
  Flush();
  key = 0;
  cursorX = 0;
  cursorY = 0;
  ShowMapCursor(cursorX,cursorY);
  HideCursor(); Flush();
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if (key == KEY_UP_ARROW) {
      HideMapCursor(cursorX,cursorY);
      cursorY--;
      *longitude -= CELL;
      sprintf(buffer,"%9.4f",*latitude);
      GotoXY(66,4); Write(buffer);
      sprintf(buffer,"%9.4f",*longitude);
      GotoXY(66,7); Write(buffer);
      if (cursorY == -8) {
        cursorY++;
        centerLng -= CELL;
        LoadMap(centerLat,centerLng,0);
        ShowMap();
        }
      ShowMapCursor(cursorX,cursorY);
      }
    if (key == KEY_DOWN_ARROW) {
      HideMapCursor(cursorX,cursorY);
      cursorY++;
      *longitude += CELL;
      sprintf(buffer,"%9.4f",*latitude);
      GotoXY(66,4); Write(buffer);
      sprintf(buffer,"%9.4f",*longitude);
      GotoXY(66,7); Write(buffer);
      if (cursorY == 8) {
        cursorY--;
        centerLng += CELL;
        LoadMap(centerLat,centerLng,0);
        ShowMap();
        }
      ShowMapCursor(cursorX,cursorY);
      }
    if (key == KEY_RIGHT_ARROW) {
      HideMapCursor(cursorX,cursorY);
      cursorX++;
      *latitude += CELL;
      sprintf(buffer,"%9.4f",*latitude);
      GotoXY(66,4); Write(buffer);
      sprintf(buffer,"%9.4f",*longitude);
      GotoXY(66,7); Write(buffer);
      if (cursorX == 28) {
        cursorX--;
        centerLat += CELL;
        LoadMap(centerLat,centerLng,0);
        ShowMap();
        }
      ShowMapCursor(cursorX,cursorY);
      }
    if (key == KEY_LEFT_ARROW) {
      HideMapCursor(cursorX,cursorY);
      cursorX--;
      *latitude -= CELL;
      sprintf(buffer,"%9.4f",*latitude);
      GotoXY(66,4); Write(buffer);
      sprintf(buffer,"%9.4f",*longitude);
      GotoXY(66,7); Write(buffer);
      if (cursorX == -28) {
        cursorX++;
        centerLat -= CELL;
        LoadMap(centerLat,centerLng,0);
        ShowMap();
        }
      ShowMapCursor(cursorX,cursorY);
      }
GotoXY(1,27); printf("X:%3d, Y:%3d",cursorX,cursorY); fflush(stdout);
    }
  ShowCursor(); Flush();
  if (key == 13) return true;
  return false;
  }

void MissionEditor() {
  Double longitude;
  Double latitude;
  FILE* file;
  char buffer[256];
  int key;
  key = 0;
  Menu();
  while (key != 'q') {
    key = Inkey();
    if (key == 27) key ='q';
    if (key =='Q') key = 'q';
    if (key =='S') key = 's';
    if (key == '1') {
      GotoXY(24,3); Write("                                                ");
      if (Input(24,3,buffer,false)) {
        if (strlen(buffer) > 0) mission->Name(buffer);
        }
      Menu();
      }
    if (key == '2') {
      GotoXY(24,4); Write("                                                ");
      if (Input(24,4,buffer,false)) {
        if (strlen(buffer) > 0) mission->Description(buffer);
        }
      Menu();
      }
    if (key == '3') {
      GetRegion();
      Menu();
      }
    if (key == '4' && mission->TargetLongitude() >-180) {
      longitude = mission->TargetLongitude();
      latitude = mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->TargetLongitude(longitude);
        mission->TargetLatitude(latitude);
        }
      Menu();
      }
    if (key == 's') {
      Box(20,10,40,7);
      GotoXY(32,12); Write("Save Mission As:");
      if (Input(30,14,buffer,false)) {
        strcat(buffer,".msn");
        file = fopen(buffer,"w");
        mission->Save(file);
        fclose(file);
        key = 'q';
        }
      }
    }
  }

void MainMenu() {
  ClearScreen();
  WriteCentered(40,5,"Lunar Mission Simulator");
  WriteCentered(40,7,"Mission Planner");
  WriteCentered(40,10,"1. Create new mission profile   ");
  WriteCentered(40,11,"2. Load existing mission profile");
  WriteCentered(40,12,"3. Exit                         ");
  GotoXY(30, 14); Write("Option ? "); fflush(stdout);
  }

int main(int argc, char** argv) {
  char buffer[256];
  FILE* file;
  UInt32 i;
  int key;
  map = new Map();
  features = map->Features();
  numFeatures = map->NumFeatures();
  LoadCategories();
  OpenTerminal();
  key = 0;
  while (key != '3') {
    MainMenu();
    key = 0;
    while (key != '1' && key != '2' && key != '3') {
      key = Inkey();
      if (key == 27) key = '3';
      }
    if (key == '1') {
      mission = new Mission();
      MissionEditor();
      }
    if (key == '2') {
      Box(20,10,40,7);
      GotoXY(31,12); Write("Load Mission From:");
      if (Input(30,14,buffer,false)) {
        strcat(buffer,".msn");
        file = fopen(buffer,"r");
        if (file == NULL) {
          Box(30,11,20,5);
          GotoXY(33, 13); Write("File not found"); Flush();
          key = 0;
          HideCursor(); Flush();
          while (key == 0) key = Inkey();
          ShowCursor(); Flush();
          }
        else {
          mission = new Mission();
          mission->Load(file);
          fclose(file);
          MissionEditor();
          }
        }
      }
    }

  GotoXY(1,25);
  CloseTerminal();
  for (i=0; i<numCategories; i++)
    free(categories[i]);
  free(categories);
  }

