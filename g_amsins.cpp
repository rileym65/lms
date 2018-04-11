#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsins.h"
#include "terminal.h"

G_AmsIns::G_AmsIns(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 27;
  height = 7;
  Reset();
  }

G_AmsIns::~G_AmsIns() {
  }

void G_AmsIns::Reset() {
  lastInsMode = -9999;
  }

void G_AmsIns::Display() {
  GotoXY(x,y+0); Write("   altitude    east   north");
  GotoXY(x,y+1); Write("POS:       :       :       ");
  GotoXY(x,y+2); Write("VEL:       :       :       ");
  GotoXY(x,y+3); Write("ACC:       :       :       ");
  GotoXY(x,y+4); Write("MOM:       :       :       ");
  GotoXY(x,y+5); Write("PER:       ");
  GotoXY(x,y+6); Write("APO:       ");
  }

void G_AmsIns::Update() {
  char buffer[64];
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
  }

