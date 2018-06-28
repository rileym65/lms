#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_groundins.h"
#include "terminal.h"

G_GroundIns::G_GroundIns(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 12;
  height = 5;
  mode = 1;
  Reset();
  }

G_GroundIns::~G_GroundIns() {
  }

void G_GroundIns::Reset() {
  lastGroundInsMode = -9999;
  }

void G_GroundIns::Display() {
  GotoXY(x,y+0); Write("east:       ");
  GotoXY(x,y+1); Write("nrth:       ");
  GotoXY(x,y+2); Write("mode:       ");
  GotoXY(x,y+3); Write(" thr:       ");
  GotoXY(x,y+4); Write(" spd:       ");
  }

void G_GroundIns::Update() {
  Int32 i;
  Double targetLng;
  Double targetLat;
  Double dist;
  char buffer[32];
  if (mode ==1 ) {
    GotoXY(x+5,y+0); sprintf(buffer,"%7.2f",vehicle->Longitude()); Write(buffer);
    GotoXY(x+5,y+1); sprintf(buffer,"%7.2f",vehicle->Latitude()); Write(buffer);
    }
  else if (mode == 2) {
    targetLng = mission->TargetLongitude();
    targetLat = mission->TargetLatitude();
    }
  else if (mode == 3) {
    targetLng = lm->Longitude();
    targetLat = lm->Latitude();
    }
  else if (mode == 4) {
    targetLng = mission->PrimaryLongitude();
    targetLat = mission->PrimaryLatitude();
    }
  else if (mode == 5) {
    targetLng = mission->Secondary1Longitude();
    targetLat = mission->Secondary1Latitude();
    }
  else if (mode == 6) {
    targetLng = mission->Secondary2Longitude();
    targetLat = mission->Secondary2Latitude();
    }
  else if (mode == 7) {
    targetLng = mission->Secondary3Longitude();
    targetLat = mission->Secondary3Latitude();
    }
  else if (mode == 8) {
    targetLng = lrv->Longitude();
    targetLat = lrv->Latitude();
    }
  else {
    GotoXY(x+5,y+0); sprintf(buffer,"%7s",ins->DisplayPosEast()); Write(buffer);
    GotoXY(x+5,y+1); sprintf(buffer,"%7s",ins->DisplayPosNorth()); Write(buffer);
    }
  if (mode > 1) {
    if (targetLng < -180) targetLng = vehicle->Longitude();
    if (targetLat < -180) targetLat = vehicle->Latitude();
    dist = (vehicle->Longitude() - targetLng) * METERS;
    GotoXY(x+5,y+0); sprintf(buffer,"%7.0f",dist); Write(buffer);
    dist = (vehicle->Latitude() - targetLat) * METERS;
    GotoXY(x+5,y+1); sprintf(buffer,"%7.0f",dist); Write(buffer);
    }
  i = vehicle->Throttle();
  if (i > 99) i = 99;
  GotoXY(x+6,y+3); sprintf(buffer,"%2d",i); Write(buffer);
  GotoXY(x+6,y+4); sprintf(buffer,"%4.1f",vehicle->Velocity().Length()); Write(buffer);
  if (mode != lastGroundInsMode) {
    GotoXY(x+6, y+2);
    switch (mode) {
      case 1: Write("ABS "); break;
      case 2: Write("TAR "); break;
      case 3: Write("LM  "); break;
      case 4: Write("PRI "); break;
      case 5: Write("SEC1"); break;
      case 6: Write("SEC2"); break;
      case 7: Write("SEC3"); break;
      case 8: Write("LRV "); break;
      }
    lastGroundInsMode = mode;
    }
  }

void G_GroundIns::ProcessKey(Int32 key) {
  if (key == '1') mode = 1;
  if (key == '2') mode = 2;
  if (key == '3') mode = 3;
  if (key == '4') mode = 4;
  if (key == '5') mode = 5;
  if (key == '6') mode = 6;
  if (key == '7') mode = 7;
  if (key == '8') mode = 8;
  }

void G_GroundIns::Load(FILE* file,char* firstLine) {
  char* pline;
  if (!startsWith(firstLine,"groundins ")) return;
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

void G_GroundIns::Save(FILE* file) {
  fprintf(file,"    GroundIns {%s",LE);
  fprintf(file,"      Mode %d%s",mode,LE);
  fprintf(file,"      }%s",LE);
  }

