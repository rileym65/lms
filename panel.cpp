#include <stdio.h>
#include <string.h>
#include "header.h"
#include "panel.h"
#include "terminal.h"
#include "gauge.h"
#include "g_amsatt.h"
#include "g_amsclocks.h"
#include "g_amscons.h"
#include "g_amsdock.h"
#include "g_amsdown.h"
#include "g_amsins.h"
#include "g_amsland.h"
#include "g_amslm.h"
#include "g_amslrv.h"
#include "g_amsmsg.h"
#include "g_amspilot.h"
#include "g_amsplss.h"
#include "g_amsseq.h"
#include "g_amsspin.h"
#include "g_amsstat.h"
#include "g_amswest.h"
#include "g_attitude.h"
#include "g_clocks.h"
#include "g_clockev.h"
#include "g_clockmi.h"
#include "g_clockte.h"
#include "g_clockut.h"
#include "g_evaprep.h"
#include "g_docked.h"
#include "g_groundins.h"
#include "g_ins.h"
#include "g_lamps.h"
#include "g_landed.h"
#include "g_lmfuel.h"
#include "g_lmrock.h"
#include "g_maplarge.h"
#include "g_mapmed.h"
#include "g_multiaxis.h"
#include "g_orbitlarge.h"
#include "g_oxybat.h"
#include "g_pilot.h"
#include "g_pilotloc.h"
#include "g_plss.h"
#include "g_precaxis.h"
#include "g_radars.h"
#include "g_rcs.h"
#include "g_seq.h"
#include "g_throttle.h"

Panel::Panel(const char* filename,Vehicle* v) {
  Int8 x,y;
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
      if (strcasecmp(str,"ams_attitude") == 0)
        addGauge(new G_AmsAtt(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_clocks") == 0)
        addGauge(new G_AmsClocks(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_consumables") == 0)
        addGauge(new G_AmsCons(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_dockingradar") == 0)
        addGauge(new G_AmsDock(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_downaxis") == 0)
        addGauge(new G_AmsDown(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_ins") == 0)
        addGauge(new G_AmsIns(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_lm") == 0)
        addGauge(new G_AmsLm(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_lrv") == 0)
        addGauge(new G_AmsLrv(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_message") == 0)
        addGauge(new G_AmsMessage(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_pilot") == 0)
        addGauge(new G_AmsPilot(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_plss") == 0)
        addGauge(new G_AmsPlss(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_sequencer") == 0)
        addGauge(new G_AmsSeq(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_spin") == 0)
        addGauge(new G_AmsSpin(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_status") == 0)
        addGauge(new G_AmsStatus(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_westaxis") == 0)
        addGauge(new G_AmsWest(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_landingradar") == 0)
        addGauge(new G_AmsLand(x1, y1, false, vehicle));

      else if (strcasecmp(str,"attitude") == 0)
        addGauge(new G_Attitude(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clocks") == 0)
        addGauge(new G_Clocks(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockev") == 0)
        addGauge(new G_ClockEV(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockmi") == 0)
        addGauge(new G_ClockMI(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockte") == 0)
        addGauge(new G_ClockTE(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockut") == 0)
        addGauge(new G_ClockUT(x1, y1, false, vehicle));
      else if (strcasecmp(str,"docked") == 0)
        addGauge(new G_Docked(x1, y1, false, vehicle));
      else if (strcasecmp(str,"evaprep") == 0)
        addGauge(new G_EvaPrep(x1, y1, false, vehicle));
      else if (strcasecmp(str,"groundins") == 0)
        addGauge(new G_GroundIns(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ins") == 0)
        addGauge(new G_Ins(x1, y1, false, vehicle));
      else if (strcasecmp(str,"lamps") == 0)
        addGauge(new G_Lamps(x1, y1, false, vehicle));
      else if (strcasecmp(str,"landed") == 0)
        addGauge(new G_Landed(x1, y1, false, vehicle));
      else if (strcasecmp(str,"lmfuel") == 0)
        addGauge(new G_LmFuel(x1, y1, false, vehicle));
      else if (strcasecmp(str,"lmrock") == 0)
        addGauge(new G_LmRock(x1, y1, false, vehicle));
      else if (strcasecmp(str,"maplarge") == 0)
        addGauge(new G_MapLarge(x1, y1, false, vehicle));
      else if (strcasecmp(str,"mapmedium") == 0)
        addGauge(new G_MapMed(x1, y1, false, vehicle));
      else if (strcasecmp(str,"multiaxis") == 0)
        addGauge(new G_MultiAxis(x1, y1, false, vehicle));
      else if (strcasecmp(str,"orbitlarge") == 0)
        addGauge(new G_OrbitLarge(x1, y1, false, vehicle));
      else if (strcasecmp(str,"oxygenbattery") == 0)
        addGauge(new G_OxyBat(x1, y1, false, vehicle));
      else if (strcasecmp(str,"pilot") == 0)
        addGauge(new G_Pilot(x1, y1, false, vehicle));
      else if (strcasecmp(str,"pilotlocation") == 0)
        addGauge(new G_PilotLocation(x1, y1, false, vehicle));
      else if (strcasecmp(str,"plss") == 0)
        addGauge(new G_Plss(x1, y1, false, vehicle));
      else if (strcasecmp(str,"precisionaxis") == 0)
        addGauge(new G_PrecAxis(x1, y1, false, vehicle));
      else if (strcasecmp(str,"radars") == 0)
        addGauge(new G_Radars(x1, y1, false, vehicle));
      else if (strcasecmp(str,"rcs") == 0)
        addGauge(new G_Rcs(x1, y1, false, vehicle));
      else if (strcasecmp(str,"seq") == 0)
        addGauge(new G_Seq(x1, y1, false, vehicle));
      else if (strcasecmp(str,"throttle") == 0)
        addGauge(new G_Throttle(x1, y1, false, vehicle));
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
  Box(1,1,80,16);
  Box(1,16,80,24);
  VLine(27,1,16);
  VLine(54,1,16);
  HLine(27,3,54);
  VLine(31,2,2);
  VLine(51,2,2);
  VLine(35,12,15);
  VLine(43,12,15);
  VLine(47,12,15);
  Label(45,12,"--");
  Label(45,13,"--");
  Label(45,14,"--");
  Label(45,15,"--");
  VLine(9,17,20);
  VLine(16,17,23);
  VLine(24,17,23);
  VLine(52,17,23);
  VLine(67,17,23);
  HLine(2,21,15);
  HLine(36,22,51);
  VLine(36,22,23);
  Label(47,23,":");
  addGauge(new G_AmsAtt(2, 17, false, vehicle));
  addGauge(new G_AmsClocks(68, 17, false, vehicle));
  addGauge(new G_AmsCons(17, 17, false, vehicle));
  addGauge(new G_AmsDock(41,  4, false, vehicle));
  addGauge(new G_AmsDown(55,  2, false, vehicle));
  addGauge(new G_AmsIns(25, 17, false, vehicle));
  addGauge(new G_AmsLand(28,  4, false, vehicle));
  addGauge(new G_AmsLm(48, 12, false, vehicle));
  addGauge(new G_AmsLrv(37, 12, false, vehicle));
  addGauge(new G_AmsMessage(37, 23, false, vehicle));
  addGauge(new G_AmsPilot(32,  2, false, vehicle));
  addGauge(new G_AmsPlss(29, 12, false, vehicle));
  addGauge(new G_AmsSeq( 2, 22, false, vehicle));
  addGauge(new G_AmsSpin(10, 17, false, vehicle));
  addGauge(new G_AmsStatus(53, 17, false, vehicle));
  if (strcmp(filename,"lrv.pnl") == 0) addGauge(new G_MapMed( 2, 2, false, vehicle));
  else if (strcmp(filename,"plss.pnl") == 0) addGauge(new G_MapMed( 2, 2, false, vehicle));
  else addGauge(new G_AmsWest( 2,  2, false, vehicle));
  }

void Panel::Box(Int8 x1,Int8 y1,Int8 x2,Int8 y2) {
  HLine(x1,y1,x2);
  HLine(x1,y2,x2);
  VLine(x1,y1,y2);
  VLine(x2,y1,y2);
  }

void Panel::HLine(Int8 x1,Int8 y1,Int8 x2) {
  Int8 i;
  y1--;
  for (i=x1-1; i<x2; i++) {
    if (screen[y1][i] == '|') screen[y1][i] = '+';
    else if (screen[y1][i] == '+') screen[y1][i] = '+';
    else screen[y1][i] = '-';
    }
  }

void Panel::VLine(Int8 x1,Int8 y1,Int8 y2) {
  Int8 i;
  x1--;
  for (i=y1-1; i<y2; i++) {
    if (screen[i][x1] == '-') screen[i][x1] = '+';
    else if (screen[i][x1] == '+') screen[i][x1] = '+';
    else screen[i][x1] = '|';
    }
  }

void Panel::Label(Int8 x,Int8 y,const char* label) {
  UInt8 i;
  for (i=0; i<strlen(label); i++)
    screen[y-1][x-1+i] = label[i];
  }

void Panel::Display() {
  Int8 i;
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
  Int8 i;
  for (i=0; i<numGauges; i++)
    gauges[i]->Update();
  fflush(stdout);
  }

void Panel::Reset() {
  Int8 i;
  for (i=0; i<numGauges; i++)
    gauges[i]->Reset();
  fflush(stdout);
  }

void Panel::ProcessKey(Int32 key) {
  Int8 i;
  for (i=0; i<numGauges; i++)
    gauges[i]->ProcessKey(key);
  }

