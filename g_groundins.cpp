#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_groundins.h"
#include "terminal.h"

G_GroundIns::G_GroundIns(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 12;
  height = 5;
  Reset();
  }

G_GroundIns::~G_GroundIns() {
  }

void G_GroundIns::Reset() {
  lastGroundInsMode = -9999;
  }

void G_GroundIns::Display() {
  GotoXY(x,y+0); printf("east:       ");
  GotoXY(x,y+1); printf("nrth:       ");
  GotoXY(x,y+2); printf("mode:       ");
  GotoXY(x,y+3); printf(" thr:       ");
  GotoXY(x,y+4); printf(" spd:       ");
  }

void G_GroundIns::Update() {
  Int32 i;
  GotoXY(x+5,y+0); printf("%7s",ins->DisplayPosEast());
  GotoXY(x+5,y+1); printf("%7s",ins->DisplayPosNorth());
  i = vehicle->Throttle();
  if (i > 99) i = 99;
  GotoXY(x+6,y+3); printf("%2d",i);
  GotoXY(x+6,y+4); printf("%4.1f",vehicle->Velocity().Length());
  if (insMode != lastGroundInsMode) {
    GotoXY(x+6, y+2);
    switch (insMode) {
      case INS_MODE_POS_ABS: printf("ABS"); break;
      case INS_MODE_POS_TAR: printf("TAR"); break;
      case INS_MODE_POS_REL: printf("REL"); break;
      case INS_MODE_ORB_ABS: printf("ABS"); break;
      case INS_MODE_ORB_TAR: printf("TAR"); break;
      case INS_MODE_ORB_REL: printf("REL"); break;
      }
    lastGroundInsMode = insMode;
    }
  }

