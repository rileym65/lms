#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_seq.h"
#include "terminal.h"

G_Seq::G_Seq(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 20;
  height = 3;
  Reset();
  }

G_Seq::~G_Seq() {
  }

void G_Seq::Reset() {
  lastArm = 5;
  lastAbo = 5;
  lastJet = 5;
  lastKil = 5;
  lastLif = 5;
  }

void G_Seq::Display() {
  GotoXY(x,y+0); printf("ARM  ABO  JET  KIL  LIF");
  }

void G_Seq::Update() {
  if (mode_arm != lastArm) {
    GotoXY(x+0,y+0);
    if (mode_arm) printf("ARM"); else printf("   ");
    lastArm = mode_arm;
    }
  if (mode_abo != lastAbo) {
    GotoXY(x+5,y+0);
    if (mode_abo) printf("ABO"); else printf("   ");
    lastAbo = mode_abo;
    }
  if (mode_jet != lastJet) {
    GotoXY(x+10,y+0);
    if (mode_jet) printf("JET"); else printf("   ");
    lastJet = mode_jet;
    }
  if (mode_kil != lastKil) {
    GotoXY(x+15,y+0);
    if (mode_kil) printf("KIL"); else printf("   ");
    lastKil = mode_kil;
    }
  if (mode_lif != lastLif) {
    GotoXY(x+20,y+0);
    if (mode_lif) printf("LIF"); else printf("   ");
    lastLif = mode_lif;
    }
  }

