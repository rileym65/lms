#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsins.h"
#include "terminal.h"
#include "common.h"

G_AmsIns::G_AmsIns(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 27;
  height = 7;
  mode = 1;
  Reset();
  }

G_AmsIns::~G_AmsIns() {
  }

void G_AmsIns::Reset() {
  lastInsMode = -9999;
  }

void G_AmsIns::Display() {
  GotoXY(x,y+0); Write("   altitude    east   north");
  GotoXY(x,y+1); Write("PXS:       :       :       ");
  GotoXY(x,y+2); Write("VEL:       :       :       ");
  GotoXY(x,y+3); Write("ACC:       :       :       ");
  GotoXY(x,y+4); Write("MOM:       :       :       ");
  GotoXY(x,y+5); Write("PER:       ");
  GotoXY(x,y+6); Write("APO:       ");
  }

void G_AmsIns::Update() {
  char buffer[64];
  Spacecraft* sc;
  if ((vehicle->Type() & VT_SPACECRAFT) == 0) return;
  sc = (Spacecraft*)vehicle;
  if (mode == 1) {
    GotoXY(x+5, y+4); Write("POS^ABS");
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
    }
  if (mode == 2) {
    GotoXY(x+5, y+4); Write("POS^TAR");
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
    }
  if (mode == 3) {
    GotoXY(x+5, y+4); Write("POS^REL");
    }
  if (mode == 4) {
    GotoXY(x+5, y+4); Write("ORB^ABS");
    sprintf(buffer,"%7.2f",sc->AscendingNode());
    GotoXY(x+12, y+4); Write(buffer);
    sprintf(buffer,"%7.2f",sc->Inclination());
    GotoXY(x+20, y+4); Write(buffer);
    sprintf(buffer,"%7.2f",(sc->Periapsis()-sc->Orbiting()->Radius())/1000);
    GotoXY(x+4, y+5); Write(buffer);
    sprintf(buffer,"%7.2f",(sc->Apoapsis()-sc->Orbiting()->Radius())/1000);
    GotoXY(x+4, y+6); Write(buffer);
    }
  if (mode == 5) {
    GotoXY(x+5, y+4); Write("ORB^TAR");
    sprintf(buffer,"%7.2f",sc->TargetMomEast());
    GotoXY(x+12, y+4); Write(buffer);
    sprintf(buffer,"%7.2f",sc->TargetMomNorth());
    GotoXY(x+20, y+4); Write(buffer);
    sprintf(buffer,"%7.2f",(sc->Periapsis()-sc->Orbiting()->Radius())/1000);
    GotoXY(x+4, y+5); Write(buffer);
    sprintf(buffer,"%7.2f",(sc->Apoapsis()-sc->Orbiting()->Radius())/1000);
    GotoXY(x+4, y+6); Write(buffer);
    }
  if (mode == 6) {
    GotoXY(x+5, y+4); Write("ORB^REL");
    }
  }

void G_AmsIns::ProcessKey(Int32 key) {
  if (key == '1') mode = 1;
  if (key == '2') mode = 2;
  if (key == '3') mode = 3;
  if (key == '4') mode = 4;
  if (key == '5') mode = 5;
  if (key == '6') mode = 6;
  }

void G_AmsIns::Load(FILE* file,char* firstLine) {
  char* pline;
  if (!startsWith(firstLine,"amsins ")) return;
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

void G_AmsIns::Save(FILE* file) {
  fprintf(file,"    AmsIns {%s",LE);
  fprintf(file,"      Mode %d%s",mode,LE);
  fprintf(file,"      }%s",LE);
  }

