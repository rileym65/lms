#include "types.h"
#include "gauge.h"
#include "g_csmcomputer.h"
#include "terminal.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "command.h"
#include "csmcomputer.h"
#include "common.h"

G_CsmComputer::G_CsmComputer(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 6;
  height = 7;
  }

G_CsmComputer::~G_CsmComputer() {
  }

void G_CsmComputer::Reset() {
  }

void G_CsmComputer::Display() {
  GotoXY(x,y+0); Write("R    P");
  GotoXY(x,y+1); Write("    99");
  GotoXY(x,y+2); Write("  V  N");
  GotoXY(x,y+3); Write(" 99 99");
  GotoXY(x,y+4); Write("+12345");
  GotoXY(x,y+5); Write("+12345");
  GotoXY(x,y+6); Write("+12345");
  }

void G_CsmComputer::Update() {
  CsmComputer* computer;
  if ((vehicle->Type() & VT_COMMAND) == 0) return;
  computer = ((CommandModule*)vehicle)->Computer();
  GotoXY(x+0, y+0); Write((computer->Running()) ? "R" : " ");
  GotoXY(x+0, y+1); Write((computer->EntryMode() == '-') ? " " : "I");
  GotoXY(x+4, y+1); Write(computer->Prog());
  GotoXY(x+1, y+3); Write(computer->Verb());
  GotoXY(x+4, y+3); Write(computer->Noun());
  GotoXY(x+0, y+4); Write(computer->Reg1());
  GotoXY(x+0, y+5); Write(computer->Reg2());
  GotoXY(x+0, y+6); Write(computer->Reg3());
  
  }

