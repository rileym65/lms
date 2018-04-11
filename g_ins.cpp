#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_ins.h"
#include "terminal.h"

G_Ins::G_Ins(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 27;
  height = 7;
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
  if (ins->Mode() < 4) {
    GotoXY(x+4,y+1); sprintf(buffer,"%7s",ins->DisplayPosAltitude()); Write(buffer);
    GotoXY(x+12,y+1); sprintf(buffer,"%7s",ins->DisplayPosEast()); Write(buffer);
    GotoXY(x+20,y+1); sprintf(buffer,"%7s",ins->DisplayPosNorth()); Write(buffer);
    GotoXY(x+4,y+2); sprintf(buffer,"%7s",ins->DisplayVelAltitude()); Write(buffer);
    GotoXY(x+12,y+2); sprintf(buffer,"%7s",ins->DisplayVelEast()); Write(buffer);
    GotoXY(x+20,y+2); sprintf(buffer,"%7s",ins->DisplayVelNorth()); Write(buffer);
    GotoXY(x+4,y+3); sprintf(buffer,"%7s",ins->DisplayAccAltitude()); Write(buffer);
    GotoXY(x+12,y+3); sprintf(buffer,"%7s",ins->DisplayAccEast()); Write(buffer);
    GotoXY(x+20,y+3); sprintf(buffer,"%7s",ins->DisplayAccNorth()); Write(buffer);
    }
  else {
    GotoXY(x+12,y+4); sprintf(buffer,"%7s",ins->DisplayMomEast()); Write(buffer);
    GotoXY(x+20,y+4); sprintf(buffer,"%7s",ins->DisplayMomNorth()); Write(buffer);
    GotoXY(x+4,y+5); sprintf(buffer,"%7s",ins->DisplayPerilune()); Write(buffer);
    GotoXY(x+4,y+6); sprintf(buffer,"%7s",ins->DisplayApolune()); Write(buffer);
    }
  if (insMode != lastInsMode) {
    GotoXY(x+4, y+4);
    switch (insMode) {
      case INS_MODE_POS_ABS: Write("POS^ABS"); break;
      case INS_MODE_POS_TAR: Write("POS^TAR"); break;
      case INS_MODE_POS_REL: Write("POS^REL"); break;
      case INS_MODE_ORB_ABS: Write("ORBvABS"); break;
      case INS_MODE_ORB_TAR: Write("ORBvTAR"); break;
      }
    lastInsMode = insMode;
    }
  GotoXY(x+4,y+5); sprintf(buffer,"%7.1f",(ins->Perilune()-GROUND)/1000); Write(buffer);
  GotoXY(x+4,y+6); sprintf(buffer,"%7.1f",(ins->Apolune()-GROUND)/1000); Write(buffer);
  GotoXY(x+12,y+4); sprintf(buffer,"%7.2f",ins->MomEast()); Write(buffer);
  GotoXY(x+20,y+4); sprintf(buffer,"%7.2f",ins->MomNorth()); Write(buffer);
  displayClock(x+18,y+6,clockOr);
  }

