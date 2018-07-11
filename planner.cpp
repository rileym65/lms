#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "terminal.h"
#include "types.h"
#include "mission.h"
#include "map.h"

#define GROUND 1738300
#define METERS ((GROUND*2*M_PI) / 360.0)
#define CELL   (1.0/(METERS/10.0))

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
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->TargetLatitude(), mission->TargetLongitude());
      WriteLn(buffer);
      }
  GotoXY(5,7); Write("5. Primary Site   :");
  if (mission->PrimaryLatitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->PrimaryLatitude(), mission->PrimaryLongitude());
      WriteLn(buffer);
      }
  GotoXY(5,8); Write("6. Secondary Site :");
  if (mission->Secondary1Latitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->Secondary1Latitude(), mission->Secondary1Longitude());
      WriteLn(buffer);
      }
  GotoXY(5,9); Write("7. Secondary Site :");
  if (mission->Secondary2Latitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->Secondary2Latitude(), mission->Secondary2Longitude());
      WriteLn(buffer);
      }
  GotoXY(5,10); Write("8. Secondary Site :");
  if (mission->Secondary3Latitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->Secondary3Latitude(), mission->Secondary3Longitude());
      WriteLn(buffer);
      }
  GotoXY(5,11); Write("9. Vehicle        :");
  if (mission->Vehicle() == 1) WriteLn("Apollo      ");
  if (mission->Vehicle() == 2) WriteLn("Apollo J    ");
  if (mission->Vehicle() == 3) WriteLn("Apollo Mk II");
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

void ShowMapData(Double latitude, Double longitude) {
  char buffer[128];
  sprintf(buffer,"%9.4f",latitude);
  GotoXY(66,4); Write(buffer);
  sprintf(buffer,"%9.4f",longitude);
  GotoXY(66,7); Write(buffer);
  sprintf(buffer,"%9.2fm",(latitude - mission->TargetLatitude())*METERS);
  GotoXY(66,10); Write(buffer);
  sprintf(buffer,"%9.2fm",(longitude - mission->TargetLongitude())*METERS);
  GotoXY(66,13); Write(buffer);
  }

Boolean SelectFromMap(Double* latitude, Double* longitude) {
  int key;
  int cursorX;
  int cursorY;
  Double centerLat;
  Double centerLng;
  centerLat = *latitude;
  centerLng = *longitude;
  LoadMap(*latitude,*longitude,0);
  ClearScreen();
  Box(3,2,61,21);
  GotoXY(66,3); Write("Latitude:");
  GotoXY(66,6); Write("Longitude:");
  GotoXY(66,9); Write("Dist North:");
  GotoXY(66,12); Write("Dist East:");
  ShowMapData(*latitude,*longitude);
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
      ShowMapData(*latitude,*longitude);
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
      ShowMapData(*latitude,*longitude);
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
      ShowMapData(*latitude,*longitude);
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
      ShowMapData(*latitude,*longitude);
      if (cursorX == -28) {
        cursorX++;
        centerLat -= CELL;
        LoadMap(centerLat,centerLng,0);
        ShowMap();
        }
      ShowMapCursor(cursorX,cursorY);
      }
    }
  ShowCursor(); Flush();
  if (key == 13) return true;
  return false;
  }

void ShowVehicle(Int8 vehicle) {
  GotoXY(23, 3); WriteLn("Vehicle:    1. Apollo");
  GotoXY(23, 4); WriteLn("            2. Apollo J");
  GotoXY(23, 5); WriteLn("            3. Apollo Mk II");
  GotoXY(23, 6); WriteLn("            4. Apollo Mk III");
  GotoXY(32, 2+vehicle); Write("-->"); Flush();
  GotoXY(20, 8); Write("Ascent Stage");
  GotoXY(50, 8); Write("Descent Stage");
  GotoXY(5, 10); Write(" Dry Weight:");
  GotoXY(5, 11); Write("       Fuel:");
  GotoXY(5, 12); Write("     Oxygen:");
  GotoXY(5, 13); Write("    Battery:");
  GotoXY(5, 14); Write("     Thrust:");
  GotoXY(5, 15); Write("        Isp:");
  GotoXY(5, 16); Write("    Delta-V:");
  GotoXY(5, 17); Write("Full Weight:");
  GotoXY(5, 18); Write("   Rcs Fuel:");
  GotoXY(5, 19); Write(" Rcs Thrust:");
  GotoXY(5, 20); Write("    Rcs Isp:");

  switch (vehicle) {
    case 1:
         GotoXY(20,10); Write("2179 kg ");     /* Ascent Dry Weight */
         GotoXY(20,11); Write("2375 kg ");     /* Ascent Fuel */
         GotoXY(20,12); Write("10 hrs  ");     /* Ascent Oxygen */
         GotoXY(20,13); Write("10 hrs  ");     /* Ascent Battery */
         GotoXY(20,14); Write("14314 n ");     /* Ascent Thrust */
         GotoXY(20,15); Write("311 s   ");     /* Ascent Isp */
         GotoXY(20,16); Write("2057 m/s");     /* Ascent Delta V */
         GotoXY(20,17); Write("4812 kg ");     /* Ascent Full Weight */
         GotoXY(50,10); Write("2033 kg ");     /* Descent Dry Weight */
         GotoXY(50,11); Write("8248 kg ");     /* Descent Fuel */
         GotoXY(50,12); Write("45 hrs ");      /* Descent Oxygen */
         GotoXY(50,13); Write("45 hrs ");      /* Descent Battery */
         GotoXY(50,14); Write("43903 n ");     /* Descent Thrust */
         GotoXY(50,15); Write("311 s   ");     /* Descent Isp */
         GotoXY(50,16); Write("2404 m/s");     /* Descent Delta V */
         GotoXY(50,17); Write("10281 kg");     /* Descent Full Weight */
         GotoXY(20,18); Write("287 kg  ");     /* Rcs Fuel */
         GotoXY(20,19); Write("1780 n  ");     /* Rcs Thurst */
         GotoXY(20,20); Write("290 s  ");      /* Rcs Isp */
         break;
    case 2:
         GotoXY(20,10); Write("2127 kg ");     /* Ascent Dry Weight */
         GotoXY(20,11); Write("2375 kg ");     /* Ascent Fuel */
         GotoXY(20,12); Write("10 hrs  ");     /* Ascent Oxygen */
         GotoXY(20,13); Write("10 hrs  ");     /* Ascent Battery */
         GotoXY(20,14); Write("14345 n ");     /* Ascent Thrust */
         GotoXY(20,15); Write("311 s   ");     /* Ascent Isp */
         GotoXY(20,16); Write("2089 m/s");     /* Ascent Delta V */
         GotoXY(20,17); Write("4789 kg ");     /* Ascent Full Weight */
         GotoXY(50,10); Write("2802 kg ");     /* Descent Dry Weight */
         GotoXY(50,11); Write("8872 kg ");     /* Descent Fuel */
         GotoXY(50,12); Write("75 hrs ");      /* Descent Oxygen */
         GotoXY(50,13); Write("75 hrs ");      /* Descent Battery */
         GotoXY(50,14); Write("43903 n ");     /* Descent Thrust */
         GotoXY(50,15); Write("311 s   ");     /* Descent Isp */
         GotoXY(50,16); Write("2361 m/s");     /* Descent Delta V */
         GotoXY(50,17); Write("11674 kg");     /* Descent Full Weight */
         GotoXY(20,18); Write("287 kg  ");     /* Rcs Fuel */
         GotoXY(20,19); Write("1780 n  ");     /* Rcs Thurst */
         GotoXY(20,20); Write("290 s  ");      /* Rcs Isp */
         break;
    case 3:
         GotoXY(20,10); Write("2234 kg ");     /* Ascent Dry Weight */
         GotoXY(20,11); Write("2615 kg ");     /* Ascent Fuel */
         GotoXY(20,12); Write("10 hrs  ");     /* Ascent Oxygen */
         GotoXY(20,13); Write("10 hrs  ");     /* Ascent Battery */
         GotoXY(20,14); Write("16890 n ");     /* Ascent Thrust */
         GotoXY(20,15); Write("344 s   ");     /* Ascent Isp */
         GotoXY(20,16); Write("2381 m/s");     /* Ascent Delta V */
         GotoXY(20,17); Write("5165 kg ");     /* Ascent Full Weight */
         GotoXY(50,10); Write("2346 kg ");     /* Descent Dry Weight */
         GotoXY(50,11); Write("9720 kg ");     /* Descent Fuel */
         GotoXY(50,12); Write("110 hrs ");     /* Descent Oxygen */
         GotoXY(50,13); Write("110 hrs ");     /* Descent Battery */
         GotoXY(50,14); Write("49215 n ");     /* Descent Thrust */
         GotoXY(50,15); Write("334 s   ");     /* Descent Isp */
         GotoXY(50,16); Write("2719 m/s");     /* Descent Delta V */
         GotoXY(50,17); Write("12066 kg");     /* Descent Full Weight */
         GotoXY(20,18); Write("316 kg  ");     /* Rcs Fuel */
         GotoXY(20,19); Write("1970 n  ");     /* Rcs Thurst */
         GotoXY(20,20); Write("401 s  ");      /* Rcs Isp */
         break;
    case 4:
         GotoXY(20,10); Write("2410 kg ");     /* Ascent Dry Weight */
         GotoXY(20,11); Write("3500 kg ");     /* Ascent Fuel */
         GotoXY(20,12); Write("10 hrs  ");     /* Ascent Oxygen */
         GotoXY(20,13); Write("10 hrs  ");     /* Ascent Battery */
         GotoXY(20,14); Write("18000 n ");     /* Ascent Thrust */
         GotoXY(20,15); Write("462 s   ");     /* Ascent Isp */
         GotoXY(20,16); Write("3733 m/s");     /* Ascent Delta V */
         GotoXY(20,17); Write("6235 kg ");     /* Ascent Full Weight */
         GotoXY(50,10); Write("2546 kg ");     /* Descent Dry Weight */
         GotoXY(50,11); Write("13000 kg ");    /* Descent Fuel */
         GotoXY(50,12); Write("120 hrs ");     /* Descent Oxygen */
         GotoXY(50,13); Write("120 hrs ");     /* Descent Battery */
         GotoXY(50,14); Write("53500 n ");     /* Descent Thrust */
         GotoXY(50,15); Write("462 s   ");     /* Descent Isp */
         GotoXY(50,16); Write("4115 m/s");     /* Descent Delta V */
         GotoXY(50,17); Write("15546 kg");     /* Descent Full Weight */
         GotoXY(20,18); Write("325 kg  ");     /* Rcs Fuel */
         GotoXY(20,19); Write("2150 n  ");     /* Rcs Thurst */
         GotoXY(20,20); Write("340 s  ");      /* Rcs Isp */
         break;
    }
  Flush();
  }

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
    if (key == '4' && mission->TargetLongitude() >=-180) {
      longitude = mission->TargetLongitude();
      latitude = mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->TargetLongitude(longitude);
        mission->TargetLatitude(latitude);
        }
      Menu();
      }
    if (key == '5' && mission->TargetLongitude() >=-180) {
      longitude = (mission->PrimaryLongitude() >= -180) ?
         mission->PrimaryLongitude() : mission->TargetLongitude();
      latitude = (mission->PrimaryLatitude() >= -180) ?
         mission->PrimaryLatitude() : mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->PrimaryLongitude(longitude);
        mission->PrimaryLatitude(latitude);
        }
      Menu();
      }
    if (key == '6' && mission->TargetLongitude() >=-180) {
      longitude = (mission->Secondary1Longitude() >= -180) ?
         mission->Secondary1Longitude() : mission->TargetLongitude();
      latitude = (mission->Secondary1Latitude() >= -180) ?
         mission->Secondary1Latitude() : mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->Secondary1Longitude(longitude);
        mission->Secondary1Latitude(latitude);
        }
      Menu();
      }
    if (key == '7' && mission->TargetLongitude() >=-180) {
      longitude = (mission->Secondary2Longitude() >= -180) ?
         mission->Secondary2Longitude() : mission->TargetLongitude();
      latitude = (mission->Secondary2Latitude() >= -180) ?
         mission->Secondary2Latitude() : mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->Secondary2Longitude(longitude);
        mission->Secondary2Latitude(latitude);
        }
      Menu();
      }
    if (key == '8' && mission->TargetLongitude() >=-180) {
      longitude = (mission->Secondary3Longitude() >= -180) ?
         mission->Secondary3Longitude() : mission->TargetLongitude();
      latitude = (mission->Secondary3Latitude() >= -180) ?
         mission->Secondary3Latitude() : mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->Secondary3Longitude(longitude);
        mission->Secondary3Latitude(latitude);
        }
      Menu();
      }
    if (key == '9') {
      SelectVehicle();
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

