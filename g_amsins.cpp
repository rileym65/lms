#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsins.h"
#include "terminal.h"

G_AmsIns::G_AmsIns(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
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
  GotoXY(x,y+0); printf("   altitude    east   north");
  GotoXY(x,y+1); printf("POS:       :       :       ");
  GotoXY(x,y+2); printf("VEL:       :       :       ");
  GotoXY(x,y+3); printf("ACC:       :       :       ");
  GotoXY(x,y+4); printf("MOM:       :       :       ");
  GotoXY(x,y+5); printf("PER:       ");
  GotoXY(x,y+6); printf("APO:       ");
  }

void G_AmsIns::Update() {
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
  }

