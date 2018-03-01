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
  hours = clock / 3600;
  clock -= (hours * 3600);
  minutes = clock / 60;
  seconds = clock - (minutes * 60);
  GotoXY(x, y);
  printf("%3d:%02d:%02d",hours,minutes,seconds);
  }

void G_Ins::Display() {
  GotoXY(x,y+0); printf("   altitude    east   north");
  GotoXY(x,y+1); printf("POS:       :       :       ");
  GotoXY(x,y+2); printf("VEL:       :       :       ");
  GotoXY(x,y+3); printf("ACC:       :       :       ");
  GotoXY(x,y+4); printf("MOM:       :       :       ");
  GotoXY(x,y+5); printf("PER:                       ");
  GotoXY(x,y+6); printf("APO:           OR:         ");
  }

void G_Ins::Update() {
  if (ins->Mode() < 4) {
    GotoXY(x+4,y+1); printf("%7s",ins->DisplayPosAltitude());
    GotoXY(x+12,y+1); printf("%7s",ins->DisplayPosEast());
    GotoXY(x+20,y+1); printf("%7s",ins->DisplayPosNorth());
    GotoXY(x+4,y+2); printf("%7s",ins->DisplayVelAltitude());
    GotoXY(x+12,y+2); printf("%7s",ins->DisplayVelEast());
    GotoXY(x+20,y+2); printf("%7s",ins->DisplayVelNorth());
    GotoXY(x+4,y+3); printf("%7s",ins->DisplayAccAltitude());
    GotoXY(x+12,y+3); printf("%7s",ins->DisplayAccEast());
    GotoXY(x+20,y+3); printf("%7s",ins->DisplayAccNorth());
    }
  else {
    GotoXY(x+12,y+4); printf("%7s",ins->DisplayMomEast());
    GotoXY(x+20,y+4); printf("%7s",ins->DisplayMomNorth());
    GotoXY(x+4,y+5); printf("%7s",ins->DisplayPerilune());
    GotoXY(x+4,y+6); printf("%7s",ins->DisplayApolune());
    }
  if (insMode != lastInsMode) {
    GotoXY(x+4, y+4);
    switch (insMode) {
      case INS_MODE_POS_ABS: printf("POS^ABS"); break;
      case INS_MODE_POS_TAR: printf("POS^TAR"); break;
      case INS_MODE_POS_REL: printf("POS^REL"); break;
      case INS_MODE_ORB_ABS: printf("ORBvABS"); break;
      case INS_MODE_ORB_TAR: printf("ORBvTAR"); break;
      }
    lastInsMode = insMode;
    }
  GotoXY(x+4,y+5); printf("%7.1f",(ins->Perilune()-GROUND)/1000);
  GotoXY(x+4,y+6); printf("%7.1f",(ins->Apolune()-GROUND)/1000);
  GotoXY(x+12,y+4); printf("%7.2f",ins->MomEast());
  GotoXY(x+20,y+4); printf("%7.2f",ins->MomNorth());
  displayClock(x+18,y+6,clockOr);
  }

