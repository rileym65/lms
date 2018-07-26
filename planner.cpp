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

Double NumericDialog(char* msg, Double max) {
  int key;
  char buffer[20];
  Double v;
  Double t;
  UInt32 x,y;
  x = 40 - ((strlen(msg)+2) / 2);
  y = 10;
  v = 0;
  Box(x, y, strlen(msg)+4,4);
  GotoXY(x+2,y+1); Write(msg);
  strcpy(buffer,"");
  ShowCursor();
  GotoXY(38,y+2); Flush();
  while (key != 13 && key != 27) {
    key = Inkey();
    if (key == 10) key = 13;
    if ((key == 8 || key == 127) && strlen(buffer) > 0) {
      buffer[strlen(buffer)-1] = 0;
      GotoXY(38, y+2); Write(buffer); Write(" ");
      GotoXY(38+strlen(buffer),y+2);
      Flush();
      }
    if (key >= '0' && key <= '9') {
      buffer[strlen(buffer)+1] = 0;
      buffer[strlen(buffer)] = key;
      t = atof(buffer);
      if (t > max) {
        buffer[strlen(buffer)-1] = 0;
        }
      GotoXY(38, y+2); Write(buffer); Write(" ");
      GotoXY(38+strlen(buffer),y+2);
      Flush();
      }
    }
  v = atof(buffer);
  HideCursor();
  if (key == 27) return -1;
  return v;
  }

#define M1 19
#define M2 21
#define C1 41
#define C2 54

void ShowLoadout() {
  char buffer[64];
  Double pay;
  Double dry;
  Double full;
  Double deltaV;
  Double cons;
  sprintf(buffer,"%6.0f kg",mission->Model()->AscentEmptyWeight());
  GotoXY(C2,5); Write(buffer);
  sprintf(buffer,"%6.0f kg",mission->AscentFuel());
  GotoXY(C1,6); Write(buffer);
  GotoXY(C2,6); Write(buffer);
  sprintf(buffer,"%6.0f kg",mission->RcsFuel());
  GotoXY(C1,7); Write(buffer);
  GotoXY(C2,7); Write(buffer);
  dry = mission->Model()->AscentEmptyWeight() + mission->RcsFuel();
  full = dry + mission->AscentFuel();
  pay = full;
  sprintf(buffer,"%6.0f kg",full);
  GotoXY(C2,8); Write(buffer);
  deltaV = (mission->Model()->AscentIsp() * 9.80655) * log(full/dry);
  sprintf(buffer,"%6.0f m/s",deltaV);
  GotoXY(C2,9); Write(buffer);

  dry = mission->Model()->DescentEmptyWeight();
  sprintf(buffer,"%6.0f kg",dry);
  GotoXY(C2,12); Write(buffer);
  sprintf(buffer,"%6.0f kg",mission->DescentFuel());
  GotoXY(C1,13); Write(buffer);
  GotoXY(C2,13); Write(buffer);
  cons = mission->Consumables() / 3600;
  cons = (cons * 0.060666) + (cons * 0.308333) + (cons * 0.205833);
  sprintf(buffer,"%6d hrs",mission->Consumables() / 3600);
  GotoXY(C1,14); Write(buffer);
  sprintf(buffer,"%6.0f kg",cons);
  GotoXY(C2,14); Write(buffer);
  dry += cons;
  switch (mission->Rover()) {
    case 0:
         GotoXY(C1,15); Write("  None");
         sprintf(buffer,"%6.0f kg",(Double)0);
         GotoXY(C2,15); Write(buffer);
         break;
    case 1:
         GotoXY(C1,15); Write("  Mk I");
         dry += ROVER_MKI_WEIGHT;
         sprintf(buffer,"%6.0f kg",(Double)ROVER_MKI_WEIGHT);
         GotoXY(C2,15); Write(buffer);
         break;
    case 2:
         GotoXY(C1,15); Write(" Mk II");
         dry += ROVER_MKII_WEIGHT;
         sprintf(buffer,"%6.0f kg",(Double)ROVER_MKII_WEIGHT);
         GotoXY(C2,15); Write(buffer);
         break;
    case 3:
         GotoXY(C1,15); Write("Mk III");
         dry += ROVER_MKIII_WEIGHT;
         sprintf(buffer,"%6.0f kg",(Double)ROVER_MKIII_WEIGHT);
         GotoXY(C2,15); Write(buffer);
         break;
    }
  switch (mission->Lsep()) {
    case 0:
         GotoXY(C1,16); Write("  None");
         sprintf(buffer,"%6.0f kg",(Double)0);
         GotoXY(C2,16); Write(buffer);
         break;
    case 1:
         GotoXY(C1,16); Write(" ELSEP");
         sprintf(buffer,"%6.0f kg",(Double)ELSEP_WEIGHT);
         GotoXY(C2,16); Write(buffer);
         dry += ELSEP_WEIGHT;
         break;
    case 2:
         GotoXY(C1,16); Write(" ALSEP");
         sprintf(buffer,"%6.0f kg",(Double)ALSEP_WEIGHT);
         GotoXY(C2,16); Write(buffer);
         dry += ALSEP_WEIGHT;
         break;
    }
  switch (mission->Laser()) {
    case 0:
         GotoXY(C1,17); Write("    No");
         sprintf(buffer,"%6.0f kg",(Double)0);
         GotoXY(C2,17); Write(buffer);
         break;
    case 1:
         GotoXY(C1,17); Write("   Yes");
         sprintf(buffer,"%6.0f kg",(Double)LASER_WEIGHT);
         GotoXY(C2,17); Write(buffer);
         dry += LASER_WEIGHT;
         break;
    }
  sprintf(buffer,"%6.0f kg",dry + mission->DescentFuel());
  GotoXY(C2,18); Write(buffer);
  dry += pay;
  full = dry + mission->DescentFuel();
  deltaV = (mission->Model()->DescentIsp() * 9.80655) * log(full/dry);
  sprintf(buffer,"%6.0f m/s",deltaV);
  GotoXY(C2,19); Write(buffer);
  sprintf(buffer,"%6.0f kg",full);
  GotoXY(C2,21); Write(buffer);
  Flush();
  }

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
  char temp[64];
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
      if (line < 0) {
        line = 0;
        if (top > 0) top--;
        i = 0;
        count = 0;
        while (i < numCategories && count < 17) {
          strcpy(temp, categories[top+i]);
          while (strlen(temp) < 20) strcat(temp, " ");
          GotoXY(26, 4+i); Write(temp);
          i++;
          count++;
          }
        }
      GotoXY(21,4+line); Write("--->"); Flush();
      }
    if (key == KEY_DOWN_ARROW) {
      GotoXY(21,4+line); Write("    "); Flush();
      line++;
      if (line >= count) {
        if ((UInt32)(line + top) < numCategories) {
          line--;
          top++;
          i = 0;
          count = 0;
          while (i < numCategories && count < 17) {
            strcpy(temp, categories[top+i]);
            while (strlen(temp) < 20) strcat(temp, " ");
            GotoXY(26, 4+i); Write(temp);
            i++;
            count++;
            }
          }
        else
          line--;
        }
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
  GotoXY(5,3); Write("A. Mission Name   :");
  if (mission->Name() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Name());
      WriteLn(buffer);
      }
  GotoXY(5,4); Write("B. Description    :");
  if (mission->Description() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Description());
      WriteLn(buffer);
      }
  GotoXY(5,5); Write("C. Landing Region :");
  if (mission->Region() == NULL) WriteLn("Not Defined");
    else {
      sprintf(buffer,"%s",mission->Region());
      WriteLn(buffer);
      }
  GotoXY(5,6); Write("D. Landing Site   :");
  if (mission->TargetLatitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->TargetLatitude(), mission->TargetLongitude());
      WriteLn(buffer);
      }
  GotoXY(5,7); Write("E. Primary Site   :");
  if (mission->PrimaryLatitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->PrimaryLatitude(), mission->PrimaryLongitude());
      WriteLn(buffer);
      }
  GotoXY(5,8); Write("F. Secondary Site :");
  if (mission->Secondary1Latitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->Secondary1Latitude(), mission->Secondary1Longitude());
      WriteLn(buffer);
      }
  GotoXY(5,9); Write("G. Secondary Site :");
  if (mission->Secondary2Latitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->Secondary2Latitude(), mission->Secondary2Longitude());
      WriteLn(buffer);
      }
  GotoXY(5,10); Write("H. Secondary Site :");
  if (mission->Secondary3Latitude() < -180) WriteLn("Not Defined");
    else {
      sprintf(buffer,"Latitude: %9.4f, Longitude: %9.4f",
         mission->Secondary3Latitude(), mission->Secondary3Longitude());
      WriteLn(buffer);
      }
  GotoXY(5,11); Write("I. Vehicle        :");
  if (mission->Vehicle() == 1) WriteLn("Apollo      ");
  if (mission->Vehicle() == 2) WriteLn("Apollo J    ");
  if (mission->Vehicle() == 3) WriteLn("Apollo Mk II");
  if (mission->Vehicle() == 4) WriteLn("Apollo Mk III");
  GotoXY(5,12); Write("J. Loadout");
  GotoXY(5,18); WriteLn("S. Save and exit");
  GotoXY(5,19); WriteLn("Q. Quit without saving");
  GotoXY(8,21); Write("Option ? ");
  Flush();
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
  char buffer[64];
  Lander* model;
  model = new Lander(vehicle);
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
  sprintf(buffer,"%.0lf kg   ", model->AscentEmptyWeight());
  GotoXY(20,10); Write(buffer);
  sprintf(buffer,"%.0lf kg   ", model->AscentFuel());
  GotoXY(20,11); Write(buffer);
  GotoXY(20,12); Write("10 hrs  ");     /* Ascent Oxygen */
  GotoXY(20,13); Write("10 hrs  ");     /* Ascent Battery */
  sprintf(buffer,"%.0lf n   ", model->AscentThrust());
  GotoXY(20,14); Write(buffer);
  sprintf(buffer,"%.0lf s   ", model->AscentIsp());
  GotoXY(20,15); Write(buffer);
  sprintf(buffer,"%.0lf m/s   ", model->AscentDeltaV());
  GotoXY(20,16); Write(buffer);
  sprintf(buffer,"%.0lf kg   ", model->AscentFullWeight());
  GotoXY(20,17); Write(buffer);
  sprintf(buffer,"%.0lf kg   ", model->RcsFuel());
  GotoXY(20,18); Write(buffer);
  sprintf(buffer,"%.0lf n   ", model->RcsThrust());
  GotoXY(20,19); Write(buffer);
  sprintf(buffer,"%.0lf s   ", model->RcsIsp());
  GotoXY(20,20); Write(buffer);
  sprintf(buffer,"%.0lf kg   ", model->DescentEmptyWeight());
  GotoXY(50,10); Write(buffer);
  sprintf(buffer,"%.0lf kg   ", model->DescentFuel());
  GotoXY(50,11); Write(buffer);
  sprintf(buffer,"%d hrs   ", model->Consumables() / 3600);
  GotoXY(50,12); Write(buffer);
  sprintf(buffer,"%d hrs   ", model->Consumables() / 3600);
  GotoXY(50,13); Write(buffer);
  sprintf(buffer,"%.0lf n   ", model->DescentThrust());
  GotoXY(50,14); Write(buffer);
  sprintf(buffer,"%.0lf s   ", model->DescentIsp());
  GotoXY(50,15); Write(buffer);
  sprintf(buffer,"%.0lf m/s   ", model->DescentDeltaV());
  GotoXY(50,16); Write(buffer);
  sprintf(buffer,"%.0lf kg  ", model->DescentFullWeight());
  GotoXY(50,17); Write(buffer);
  Flush();
  delete(model);
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
GotoXY(2,2);
    if (key == 27) key ='q';
    if (key =='Q') key = 'q';
    if (key =='S') key = 's';
    if (key =='a') key = 'A';
    if (key =='b') key = 'B';
    if (key =='c') key = 'C';
    if (key =='d') key = 'D';
    if (key =='e') key = 'E';
    if (key =='f') key = 'F';
    if (key =='g') key = 'G';
    if (key =='h') key = 'H';
    if (key =='i') key = 'I';
    if (key =='j') key = 'J';
    if (key == 'A') {
      GotoXY(24,3); Write("                                                ");
      if (Input(24,3,buffer,false)) {
        if (strlen(buffer) > 0) mission->Name(buffer);
        }
      Menu();
      }
    if (key == 'B') {
      GotoXY(24,4); Write("                                                ");
      if (Input(24,4,buffer,false)) {
        if (strlen(buffer) > 0) mission->Description(buffer);
        }
      Menu();
      }
    if (key == 'C') {
      GetRegion();
      Menu();
      }
    if (key == 'D' && mission->TargetLongitude() >=-180) {
      longitude = mission->TargetLongitude();
      latitude = mission->TargetLatitude();
      if (SelectFromMap(&latitude, &longitude)) {
        mission->TargetLongitude(longitude);
        mission->TargetLatitude(latitude);
        }
      Menu();
      }
    if (key == 'E' && mission->TargetLongitude() >=-180) {
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
    if (key == 'F' && mission->TargetLongitude() >=-180) {
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
    if (key == 'G' && mission->TargetLongitude() >=-180) {
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
    if (key == 'H' && mission->TargetLongitude() >=-180) {
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
    if (key == 'I') {
      SelectVehicle();
      Menu();
      }
    if (key == 'J') {
      DoLoadout();
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

