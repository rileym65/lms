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
  GotoXY(x,y+0); Write("east:       ");
  GotoXY(x,y+1); Write("nrth:       ");
  GotoXY(x,y+2); Write("mode:       ");
  GotoXY(x,y+3); Write(" thr:       ");
  GotoXY(x,y+4); Write(" spd:       ");
  }

void G_GroundIns::Update() {
  Int32 i;
  char buffer[32];
  GotoXY(x+5,y+0); sprintf(buffer,"%7s",ins->DisplayPosEast()); Write(buffer);
  GotoXY(x+5,y+1); sprintf(buffer,"%7s",ins->DisplayPosNorth()); Write(buffer);
  i = vehicle->Throttle();
  if (i > 99) i = 99;
  GotoXY(x+6,y+3); sprintf(buffer,"%2d",i); Write(buffer);
  GotoXY(x+6,y+4); sprintf(buffer,"%4.1f",vehicle->Velocity().Length()); Write(buffer);
  if (insMode != lastGroundInsMode) {
    GotoXY(x+6, y+2);
    switch (insMode) {
      case INS_MODE_POS_ABS: Write("ABS"); break;
      case INS_MODE_POS_TAR: Write("TAR"); break;
      case INS_MODE_POS_REL: Write("REL"); break;
      case INS_MODE_ORB_ABS: Write("ABS"); break;
      case INS_MODE_ORB_TAR: Write("TAR"); break;
      case INS_MODE_ORB_REL: Write("REL"); break;
      }
    lastGroundInsMode = insMode;
    }
  }

