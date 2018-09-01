#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "gauge.h"
#include "g_computer.h"
#include "terminal.h"
#include "vector.h"
#include "computer.h"
#include "vehicle.h"

G_Computer::G_Computer(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 29;
  height = 7;
  }

G_Computer::~G_Computer() {
  }

void G_Computer::Reset() {
  strcpy(lastProg,"  ");
  strcpy(lastVerb,"  ");
  strcpy(lastNoun,"  ");
  strcpy(lastReg1,"  ");
  strcpy(lastReg2,"  ");
  strcpy(lastReg3,"  ");
  strcpy(lastReg4,"  ");
  strcpy(lastReg5,"  ");
  strcpy(lastReg6,"  ");
  strcpy(lastReg7,"  ");
  strcpy(lastReg8,"  ");
  strcpy(lastReg9,"  ");
  strcpy(lastReg10,"  ");
  strcpy(lastReg11,"  ");
  strcpy(lastReg12,"  ");
  strcpy(lastReg13,"  ");
  strcpy(lastReg14,"  ");
  strcpy(lastReg15,"  ");
  lastRunning = true;
  lastInput = true;
  lastErr = true;
  lastInputMode = 0;
  startup = true;
  }

void G_Computer::Display() {
  GotoXY(x,y+0); Write("   P         V         N     ");
  GotoXY(x,y+1); Write(" -0000000  -0000000  -0000000");
  GotoXY(x,y+2); Write(" -0000000  -0000000  -0000000");
  GotoXY(x,y+3); Write(" -0000000  -0000000  -0000000");
  GotoXY(x,y+4); Write("     RUN  IDL  INP  ERR      ");
  GotoXY(x,y+5); Write(" -0000000  -0000000  -0000000");
  GotoXY(x,y+6); Write(" -0000000  -0000000  -0000000");
  }

void G_Computer::Update() {
  char buffer[64];
  Computer* c;
  c = vehicle->Comp();
  if (c == NULL) return;
  if (strcmp(c->Prog(),lastProg) != 0) {
    GotoXY(x+5, y+0); 
    sprintf(buffer,"%s",c->Prog());
    Write(buffer);
    strcpy(lastProg,c->Prog());
    }
  if (strcmp(c->Verb(),lastVerb) != 0) {
    GotoXY(x+15, y+0); 
    sprintf(buffer,"%s",c->Verb());
    Write(buffer);
    strcpy(lastVerb,c->Verb());
    }
  if (strcmp(c->Noun(),lastNoun) != 0) {
    GotoXY(x+25, y+0); 
    sprintf(buffer,"%s",c->Noun());
    Write(buffer);
    strcpy(lastNoun,c->Noun());
    }
  if (startup) lastRunning = !c->Running();
  if (c->Running() != lastRunning) {
    GotoXY(x+5,y+4);
    if (c->Running()) Write("RUN     ");
      else Write("     IDL");
    lastRunning = c->Running();
    }
  if (c->Input() != lastInput) {
    GotoXY(x+15,y+4);
    if (c->Input()) Write("INP"); else Write("   ");
    lastInput = c->Input();
    }
  if (c->Err() != lastErr) {
    GotoXY(x+20,y+4);
    if (c->Err()) Write("ERR"); else Write("   ");
    lastErr = c->Err();
    }
  if (strcmp(c->Reg(1),lastReg1) != 0) {
    GotoXY(x+1, y+1); 
    sprintf(buffer,"%s",c->Reg(1));
    Write(buffer);
    strcpy(lastReg1,c->Reg(1));
    }
  if (strcmp(c->Reg(2),lastReg2) != 0) {
    GotoXY(x+11, y+1); 
    sprintf(buffer,"%s",c->Reg(2));
    Write(buffer);
    strcpy(lastReg2,c->Reg(2));
    }
  if (strcmp(c->Reg(3),lastReg3) != 0) {
    GotoXY(x+21, y+1); 
    sprintf(buffer,"%s",c->Reg(3));
    Write(buffer);
    strcpy(lastReg3,c->Reg(3));
    }
  if (strcmp(c->Reg(4),lastReg4) != 0) {
    GotoXY(x+1, y+2); 
    sprintf(buffer,"%s",c->Reg(4));
    Write(buffer);
    strcpy(lastReg4,c->Reg(4));
    }
  if (strcmp(c->Reg(5),lastReg5) != 0) {
    GotoXY(x+11, y+2); 
    sprintf(buffer,"%s",c->Reg(5));
    Write(buffer);
    strcpy(lastReg5,c->Reg(5));
    }
  if (strcmp(c->Reg(6),lastReg6) != 0) {
    GotoXY(x+21, y+2); 
    sprintf(buffer,"%s",c->Reg(6));
    Write(buffer);
    strcpy(lastReg6,c->Reg(6));
    }
  if (strcmp(c->Reg(7),lastReg7) != 0) {
    GotoXY(x+1, y+3); 
    sprintf(buffer,"%s",c->Reg(7));
    Write(buffer);
    strcpy(lastReg7,c->Reg(7));
    }
  if (strcmp(c->Reg(8),lastReg8) != 0) {
    GotoXY(x+11, y+3); 
    sprintf(buffer,"%s",c->Reg(8));
    Write(buffer);
    strcpy(lastReg8,c->Reg(8));
    }
  if (strcmp(c->Reg(9),lastReg9) != 0) {
    GotoXY(x+21, y+3); 
    sprintf(buffer,"%s",c->Reg(9));
    Write(buffer);
    strcpy(lastReg9,c->Reg(9));
    }
  if (strcmp(c->Reg(10),lastReg10) != 0) {
    GotoXY(x+1, y+5); 
    sprintf(buffer,"%s",c->Reg(10));
    Write(buffer);
    strcpy(lastReg10,c->Reg(10));
    }
  if (strcmp(c->Reg(11),lastReg11) != 0) {
    GotoXY(x+11, y+5); 
    sprintf(buffer,"%s",c->Reg(11));
    Write(buffer);
    strcpy(lastReg11,c->Reg(11));
    }
  if (strcmp(c->Reg(12),lastReg12) != 0) {
    GotoXY(x+21, y+5); 
    sprintf(buffer,"%s",c->Reg(12));
    Write(buffer);
    strcpy(lastReg12,c->Reg(12));
    }
  if (strcmp(c->Reg(13),lastReg13) != 0) {
    GotoXY(x+1, y+6); 
    sprintf(buffer,"%s",c->Reg(13));
    Write(buffer);
    strcpy(lastReg13,c->Reg(13));
    }
  if (strcmp(c->Reg(14),lastReg14) != 0) {
    GotoXY(x+11, y+6); 
    sprintf(buffer,"%s",c->Reg(14));
    Write(buffer);
    strcpy(lastReg14,c->Reg(14));
    }
  if (strcmp(c->Reg(15),lastReg15) != 0) {
    GotoXY(x+21, y+6); 
    sprintf(buffer,"%s",c->Reg(15));
    Write(buffer);
    strcpy(lastReg15,c->Reg(15));
    }
  startup = false;
  }


