#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsseq.h"
#include "terminal.h"

G_AmsSeq::G_AmsSeq(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 14;
  height = 2;
  Reset();
  }

G_AmsSeq::~G_AmsSeq() {
  }

void G_AmsSeq::Reset() {
  lastAbo = 5;
  lastJet = 5;
  lastKil = 5;
  lastLif = 5;
  }

void G_AmsSeq::Display() {
  GotoXY(x,y+0); Write(" ABO| KIL| PIL");
  GotoXY(x,y+1); Write(" JET| LIF| ---");
  }

void G_AmsSeq::Update() {
  if (mode_abo != lastAbo) {
    GotoXY(x+0,y+0);
    if (mode_abo) Write("^"); else Write(" ");
    lastAbo = mode_abo;
    }
  if (mode_jet != lastJet) {
    GotoXY(x+0,y+1);
    if (mode_jet) Write("^"); else Write(" ");
    lastJet = mode_jet;
    }
  if (mode_kil != lastKil) {
    GotoXY(x+5,y+0);
    if (mode_kil) Write("^"); else Write(" ");
    lastKil = mode_kil;
    }
  if (mode_lif != lastLif) {
    GotoXY(x+5,y+1);
    if (mode_lif) Write("^"); else Write(" ");
    lastLif = mode_lif;
    }
  }

