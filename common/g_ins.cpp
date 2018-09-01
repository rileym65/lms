#include <stdlib.h>
#include "types.h"
#include "gauge.h"
#include "g_ins.h"
#include "terminal.h"
#include "common.h"
#include "helpers.h"
#include "vehicle.h"
#include "spacecraft.h"

G_Ins::G_Ins(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 27;
  height = 7;
  mode = 1;
  Reset();
  }

G_Ins::~G_Ins() {
  }

void G_Ins::Reset() {
  lastInsMode = -9999;
  }

void G_Ins::displayClock(Int32 x, Int32 y, Int32 clock) {
  Int32 hours, minutes, seconds;
  char buffer[32];
  hours = clock / 3600;
  clock -= (hours * 3600);
  minutes = clock / 60;
  seconds = clock - (minutes * 60);
  GotoXY(x, y);
  sprintf(buffer,"%3d:%02d:%02d",hours,minutes,seconds);
  Write(buffer);
  }

void G_Ins::ProcessKey(Int32 key) {
  if (key == '1') mode = 1;
  if (key == '2') mode = 2;
  if (key == '3') mode = 3;
  }

void G_Ins::Display() {
  GotoXY(x,y+0); Write("   altitude    east   north");
  GotoXY(x,y+1); Write("POS:       :       :       ");
  GotoXY(x,y+2); Write("VEL:       :       :       ");
  GotoXY(x,y+3); Write("ACC:       :       :       ");
  GotoXY(x,y+4); Write("MOM:       :       :       ");
  GotoXY(x,y+5); Write("PER:                       ");
  GotoXY(x,y+6); Write("APO:           OR:         ");
  }

void G_Ins::Update() {
  char buffer[32];
  Spacecraft* sc;
  if ((vehicle->Type() & VT_SPACECRAFT) == 0) return;
  sc = (Spacecraft*)vehicle;
  if (mode == 1) {
    GotoXY(x+5, y+4); Write("ABS");
    sprintf(buffer,"%7.0f",sc->Altitude());
    GotoXY(x+4, y+1); Write(buffer);
    sprintf(buffer,"%7.2f",sc->Longitude());
    GotoXY(x+12, y+1); Write(buffer);
    sprintf(buffer,"%7.2f",sc->Latitude());
    GotoXY(x+20, y+1); Write(buffer);
    sprintf(buffer,"%7.2f",sc->VelocityAltitude());
    GotoXY(x+4, y+2); Write(buffer);
    sprintf(buffer,"%7.2f",sc->VelocityEast());
    GotoXY(x+12, y+2); Write(buffer);
    sprintf(buffer,"%7.2f",sc->VelocityNorth());
    GotoXY(x+20, y+2); Write(buffer);
    sprintf(buffer,"%7.2f",sc->AccelAltitude());
    GotoXY(x+4, y+3); Write(buffer);
    sprintf(buffer,"%7.2f",sc->AccelEast());
    GotoXY(x+12, y+3); Write(buffer);
    sprintf(buffer,"%7.2f",sc->AccelNorth());
    GotoXY(x+20, y+3); Write(buffer);
    sprintf(buffer,"%7.2f",sc->AscendingNode());
    GotoXY(x+12, y+4); Write(buffer);
    sprintf(buffer,"%7.2f",sc->Inclination());
    GotoXY(x+20, y+4); Write(buffer);
    sprintf(buffer,"%7.2f",(sc->Periapsis()-sc->Orbiting()->Radius())/1000);
    GotoXY(x+4, y+5); Write(buffer);
    sprintf(buffer,"%7.2f",(sc->Apoapsis()-sc->Orbiting()->Radius())/1000);
    GotoXY(x+4, y+6); Write(buffer);
    sprintf(buffer,"%7.0f",sc->OrbitTime());
    GotoXY(x+18,y+6); Write(buffer);
    }
  if (mode == 2) {
    GotoXY(x+5, y+4); Write("TAR");
    sprintf(buffer,"%7.0f",sc->Altitude());
    GotoXY(x+4, y+1); Write(buffer);
    sprintf(buffer,"%7.2f",sc->TargetLongitude());
    GotoXY(x+12, y+1); Write(buffer);
    sprintf(buffer,"%7.2f",sc->TargetLatitude());
    GotoXY(x+20, y+1); Write(buffer);
    sprintf(buffer,"%7.2f",sc->VelocityAltitude());
    GotoXY(x+4, y+2); Write(buffer);
    sprintf(buffer,"%7.2f",sc->VelocityEast());
    GotoXY(x+12, y+2); Write(buffer);
    sprintf(buffer,"%7.2f",sc->VelocityNorth());
    GotoXY(x+20, y+2); Write(buffer);
    sprintf(buffer,"%7.2f",sc->AccelAltitude());
    GotoXY(x+4, y+3); Write(buffer);
    sprintf(buffer,"%7.2f",sc->AccelEast());
    GotoXY(x+12, y+3); Write(buffer);
    sprintf(buffer,"%7.2f",sc->AccelNorth());
    GotoXY(x+20, y+3); Write(buffer);
    sprintf(buffer,"%7.2f",sc->TargetMomEast());
    GotoXY(x+12, y+4); Write(buffer);
    sprintf(buffer,"%7.2f",sc->TargetMomNorth());
    GotoXY(x+20, y+4); Write(buffer);

    sprintf(buffer,"%7.2f",(sc->Periapsis()-sc->Orbiting()->Radius())/1000);
    GotoXY(x+4, y+5); Write(buffer);
    sprintf(buffer,"%7.2f",(sc->Apoapsis()-sc->Orbiting()->Radius())/1000);
    GotoXY(x+4, y+6); Write(buffer);
    sprintf(buffer,"%7.0f",sc->OrbitTime());
    GotoXY(x+18,y+6); Write(buffer);
    }
  }

void G_Ins::Load(FILE* file,char* firstLine) {
  char* pline;
  if (!startsWith(firstLine,"ins ")) return;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    else if (startsWith(pline,"mode ")) mode = atoi(nw(pline));
    else {
      Write("Unknown line found in save file: ");
      WriteLn(pline);
      exit(1);
      }
    }
  }

void G_Ins::Save(FILE* file) {
  fprintf(file,"    Ins {%s",LE);
  fprintf(file,"      Mode %d%s",mode,LE);
  fprintf(file,"      }%s",LE);
  }

