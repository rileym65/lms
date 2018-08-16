#include <stdio.h>
#include <string.h>
#include "header.h"
#include "panel.h"
#include "terminal.h"
#include "gauge.h"
#include "g_accel.h"
#include "g_altitude.h"
#include "g_amsdown.h"
#include "g_apoapsis.h"
#include "g_battery.h"
#include "g_clockbu.h"
#include "g_clockmi.h"
#include "g_clockot.h"
#include "g_clocktb.h"
#include "g_clockut.h"
#include "g_csmlamps.h"
#include "g_engines.h"
#include "g_fuel.h"
#include "g_incl.h"
#include "g_lan.h"
#include "g_orbit.h"
#include "g_oxygen.h"
#include "g_periapsis.h"
#include "g_pitchrate.h"
#include "g_position.h"
#include "g_prograde.h"
#include "g_propellant.h"
#include "g_radial.h"
#include "g_rcs.h"
#include "g_roc.h"
#include "g_rollrate.h"
#include "g_velocity.h"
#include "g_yawrate.h"

Panel::Panel(const char* filename,Vehicle* v) {
  UInt8 x,y;
  vehicle = v;
  for (y=0; y<24; y++)
    for (x=0; x<80; x++)
      screen[y][x] = ' ';
  for (y=0; y<24; y++)
    screen[y][80] = 0;
  for (x=0; x<100; x++)
    gauges[x] = NULL;
  numGauges = 0;
  if (loadFile(filename) == 0) useDefault(filename);
  }

Panel::~Panel() {
  }

Int8 Panel::loadFile(const char* filename) {
  Int32 x1,y1,x2,y2;
  FILE *file;
  char  line[1024];
  char  str[1024];
  if ((file = fopen(filename,"r")) == NULL) return 0;
  while (fgets(line,1024,file) != NULL) {
    if (line[0] == '#') {
      }
    else if (strncasecmp(line,"box ",4) == 0) {
      sscanf(nw(line),"%d,%d,%d,%d",&x1,&y1,&x2,&y2);
      Box(x1,y1,x2,y2);
      }
    else if (strncasecmp(line,"line ",5) == 0) {
      sscanf(nw(line),"%d,%d,%d,%d",&x1,&y1,&x2,&y2);
      if (x1 == x2) VLine(x1,y1,y2);
      else if (y1 == y2) HLine(x1,y1,x2);
      else {
        Write("Diagonal lines are not allowed: ");
        WriteLn(line);
        exit(1);
        }
      }
    else if (strncasecmp(line,"label ",6) == 0) {
      sscanf(nw(line),"%d,%d,\"%[^\"]",&x1,&y1,str);
      Label(x1,y1,str);
      }
    else if (strncasecmp(line,"gauge ",6) == 0) {
      sscanf(nw(line),"%s %d,%d",str,&x1,&y1);
      if (strcasecmp(str,"ams_downaxis") == 0)
        addGauge(new G_AmsDown(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockbu") == 0)
        addGauge(new G_ClockBU(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockmi") == 0)
        addGauge(new G_ClockMI(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockot") == 0)
        addGauge(new G_ClockOT(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clocktb") == 0)
        addGauge(new G_ClockTB(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockut") == 0)
        addGauge(new G_ClockUT(x1, y1, false, vehicle));
      else if (strcasecmp(str,"engines") == 0)
        addGauge(new G_Engines(x1, y1, false, vehicle));
      else if (strcasecmp(str,"altitude") == 0)
        addGauge(new G_Altitude(x1, y1, false, vehicle));
      else if (strcasecmp(str,"velocity") == 0)
        addGauge(new G_Velocity(x1, y1, false, vehicle));
      else if (strcasecmp(str,"accel") == 0)
        addGauge(new G_Accel(x1, y1, false, vehicle));
      else if (strcasecmp(str,"fuel") == 0)
        addGauge(new G_Fuel(x1, y1, false, vehicle));
      else if (strcasecmp(str,"apoapsis") == 0)
        addGauge(new G_Apoapsis(x1, y1, false, vehicle));
      else if (strcasecmp(str,"periapsis") == 0)
        addGauge(new G_Periapsis(x1, y1, false, vehicle));
      else if (strcasecmp(str,"rollrate") == 0)
        addGauge(new G_RollRate(x1, y1, false, vehicle));
      else if (strcasecmp(str,"pitchrate") == 0)
        addGauge(new G_PitchRate(x1, y1, false, vehicle));
      else if (strcasecmp(str,"yawrate") == 0)
        addGauge(new G_YawRate(x1, y1, false, vehicle));
      else if (strcasecmp(str,"radial") == 0)
        addGauge(new G_Radial(x1, y1, false, vehicle));
      else if (strcasecmp(str,"orbit") == 0)
        addGauge(new G_Orbit(x1, y1, false, vehicle));
      else if (strcasecmp(str,"prograde") == 0)
        addGauge(new G_Prograde(x1, y1, false, vehicle));
      else if (strcasecmp(str,"position") == 0)
        addGauge(new G_Position(x1, y1, false, vehicle));
      else if (strcasecmp(str,"lan") == 0)
        addGauge(new G_Lan(x1, y1, false, vehicle));
      else if (strcasecmp(str,"inclination") == 0)
        addGauge(new G_Incl(x1, y1, false, vehicle));
      else if (strcasecmp(str,"roc") == 0)
        addGauge(new G_Roc(x1, y1, false, vehicle));
      else if (strcasecmp(str,"csmlamps") == 0)
        addGauge(new G_CsmLamps(x1, y1, false, vehicle));
      else if (strcasecmp(str,"rcs") == 0)
        addGauge(new G_Rcs(x1, y1, false, vehicle));
      else if (strcasecmp(str,"propellant") == 0)
        addGauge(new G_Propellant(x1, y1, false, vehicle));
      else if (strcasecmp(str,"oxygen") == 0)
        addGauge(new G_Oxygen(x1, y1, false, vehicle));
      else if (strcasecmp(str,"battery") == 0)
        addGauge(new G_Battery(x1, y1, false, vehicle));
      else {
        Write("Unknown guage: ");
        WriteLn(str);
        exit(1);
        }
      }
    else {
      Write("Unknown command: ");
      WriteLn(line);
      exit(1);
      }
    }
 
  fclose(file);
  return -1;
  }

void Panel::addGauge(Gauge* g) {
  if (numGauges < 100) {
    gauges[numGauges++] = g;
    }
  else delete(g);
  }

void Panel::useDefault(const char* filename) {
  if (strcmp(filename,"csm.pnl") == 0) {
    Box(1,1,80,24);
    VLine(47,1,24);
    Box(56,4,71,6);
    Box(49,9,77,17);
    Box(56,20,72,22);
    Label(63,2,"CSM");
    addGauge(new G_ClockUT(58, 5, false, vehicle));
    return;
    }
  }

void Panel::Box(UInt8 x1,UInt8 y1,UInt8 x2,UInt8 y2) {
  HLine(x1,y1,x2);
  HLine(x1,y2,x2);
  VLine(x1,y1,y2);
  VLine(x2,y1,y2);
  }

void Panel::HLine(UInt8 x1,UInt8 y1,UInt8 x2) {
  UInt8 i;
  y1--;
  for (i=x1-1; i<x2; i++) {
    if (screen[y1][i] == '|') screen[y1][i] = '+';
    else if (screen[y1][i] == '+') screen[y1][i] = '+';
    else screen[y1][i] = '-';
    }
  }

void Panel::VLine(UInt8 x1,UInt8 y1,UInt8 y2) {
  UInt8 i;
  x1--;
  for (i=y1-1; i<y2; i++) {
    if (screen[i][x1] == '-') screen[i][x1] = '+';
    else if (screen[i][x1] == '+') screen[i][x1] = '+';
    else screen[i][x1] = '|';
    }
  }

void Panel::Label(UInt8 x,UInt8 y,const char* label) {
  UInt8 i;
  for (i=0; i<strlen(label); i++)
    screen[y-1][x-1+i] = label[i];
  }

void Panel::Display() {
  UInt8 i;
  ClrScr();
  for (i=0; i<24; i++) {
    GotoXY(1,i+1);
    Write(screen[i]);
    }
  for (i=0; i<numGauges; i++)
    gauges[i]->Display();
  fflush(stdout);
  }

void Panel::Update() {
  UInt8 i;
  for (i=0; i<numGauges; i++)
    gauges[i]->Update();
  fflush(stdout);
  }

void Panel::Reset() {
  UInt8 i;
  for (i=0; i<numGauges; i++)
    gauges[i]->Reset();
  fflush(stdout);
  }

void Panel::ProcessKey(Int32 key) {
  UInt8 i;
  for (i=0; i<numGauges; i++)
    gauges[i]->ProcessKey(key);
  }

void Panel::Save(FILE* file) {
  UInt32 i;
  fprintf(file,"  Panel {%s",LE);
  for (i=0; i<numGauges; i++)
    gauges[i]->Save(file);
  fprintf(file,"    }%s",LE);
  }

void Panel::Load(FILE* file) {
  UInt32 i;
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    for (i=0; i<numGauges; i++)
      gauges[i]->Load(file, pline);
    }
  }

