#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsseq.h"
#include "terminal.h"

G_AmsSeq::G_AmsSeq(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
  width = 14;
  height = 2;
  Reset();
  }

G_AmsSeq::~G_AmsSeq() {
  }

void G_AmsSeq::Reset() {
  }

void G_AmsSeq::Display() {
  GotoXY(x,y+0); printf(" ABO| KIL| PIL");
  GotoXY(x,y+1); printf(" JET| LIF| ---");
  }

void G_AmsSeq::Update() {
  }

