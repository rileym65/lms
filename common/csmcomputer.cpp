#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "csmcomputer.h"
#include "common.h"
#include "helpers.h"

CsmComputer::CsmComputer(CommandModule* c) {
  prog = 0;
  csm = c;
  altitude = 0;
  velocity = 0;
  noun = 0;
  verb = 0;
  _reg1(0);
  _reg2(0);
  _reg3(0);
  running = 0;
  entryMode = '-';
  sprintf(dprog,"%02d",prog);
  sprintf(dverb,"%02d",verb);
  sprintf(dnoun,"%02d",noun);
  }

CsmComputer::~CsmComputer() {
  }

void CsmComputer::_reg1(Int32 i) {
  reg1 = i;
  if (reg1 < -99999) strcpy(dreg1,"-99999");
  else if (reg1 > 99999) strcpy(dreg1,"+99999");
  else {
    sprintf(dreg1,"%06d",abs(reg1));
    dreg1[0] = (reg1 >= 0) ? '+' : '-';
    }
  }

void CsmComputer::_reg2(Int32 i) {
  reg2 = i;
  if (reg2 < -99999) strcpy(dreg2,"-99999");
  else if (reg2 > 99999) strcpy(dreg2,"+99999");
  else {
    sprintf(dreg2,"%06d",abs(reg2));
    dreg2[0] = (reg2 >= 0) ? '+' : '-';
    }
  }

void CsmComputer::_reg3(Int32 i) {
  reg3 = i;
  if (reg3 < -99999) strcpy(dreg3,"-99999");
  else if (reg3 > 99999) strcpy(dreg3,"+99999");
  else {
    sprintf(dreg3,"%06d",abs(reg3));
    dreg3[0] = (reg3 >= 0) ? '+' : '-';
    }
  }

void CsmComputer::_doShow() {
  switch (noun) {
    case 1:
         _reg1((csm->Apoapsis()-csm->Orbiting()->Radius()) / 1000.0);
         _reg2((csm->Periapsis()-csm->Orbiting()->Radius()) / 1000.0);
         _reg3(csm->OrbitTime());
         break;
    case 2:
         _reg1(csm->Longitude() * 100);
         _reg2(csm->Latitude() * 100);
         break;
    }
  }

void CsmComputer::Cycle() {
  Double a;
  Double E;
  Double e;
  Double g;
  Double s;
  Vector L;
  Double v1,v2;
  Vector pos;
  Vector vel;
  if (verb == 1) _doShow();
  if (running == 0) return;
  if (prog == 1) {
    if (velocity == 0) {
      if (csm->Periapsis() >= csm->Orbiting()->Radius()) {
        velocity = sqrt(csm->Orbiting()->Gravitation() / csm->Apoapsis());
        _reg1((Int32)velocity);
        }
      }
    else {
      if (csm->Velocity().Length() >= velocity) {
        csm->Cutoff();
        running = 0;
        }
      }
    }
  else if (prog == 2) {
    pos = csm->Position() - csm->Orbiting()->Position();
    vel = csm->Velocity() - csm->Orbiting()->Velocity();
    g = csm->Orbiting()->Gravitation();
    L = vel.Cross(pos);
    v1 = vel.Length();
    v2 = pos.Length();
    E = ((v1 * v1) / 2) - (g/ v2);
    s = -g/ (2 * E);
    v1 = L.Length();
    v2 = g* g;
    e = sqrt(1+2*E*(v1 * v1)/(v2));
    a = (s * (1 + e)) - csm->Orbiting()->Radius();
    _reg2(a / 1000000);
    if (reg2 >= reg1) {
      csm->Cutoff();
      running = 0;
      }
    }
  else if (prog == 3) {
    vel = csm->Velocity() - csm->Orbiting()->Velocity();
    a = vel.Length();
    _reg3(reg2 - a);
    if (reg3 <= 0) {
      csm->Cutoff();
      running = 0;
      }
    }
  else if (prog == 10) {
    a = sqrt(csm->Orbiting()->Gravitation() / (reg1*1000 + csm->Orbiting()->Radius()));
    _reg2(a*10);
    running = 0;
    }
  }

char* CsmComputer::Noun() {
  return dnoun;
  }

char* CsmComputer::Prog() {
  return dprog;
  }

char* CsmComputer::Reg1() {
  return dreg1;
  }

char* CsmComputer::Reg2() {
  return dreg2;
  }

char* CsmComputer::Reg3() {
  return dreg3;
  }

Byte CsmComputer::Running() {
  return running;
  }

char* CsmComputer::Verb() {
  return dverb;
  }

void CsmComputer::_processNoun() {
  entryMode = '-';
  if (verb == 2 && noun == 1) {
    entryMode = '1';
    strcpy(dreg1,"+_____");
    }
  if (verb == 2 && noun == 2) {
    entryMode = '2';
    strcpy(dreg2,"+_____");
    }
  if (verb == 2 && noun == 3) {
    entryMode = '3';
    strcpy(dreg3,"+_____");
    }
  }

void CsmComputer::ProcessKey(Int32 key) {
  UInt8 i;
  Int8 p;
  char *buffer;
  if (key == 'g') {
    running = running ^ 0xff;
    if (running != 0) {
      if (prog == 3) {
        _reg2(reg1 + (csm->Velocity() - csm->Orbiting()->Velocity()).Length());
        }
      }
    }
  if (key == 'p' && entryMode == '-') {
    entryMode = 'P';
    strcpy(dprog,"__");
    }
  if (key == 'v' && entryMode == '-') {
    entryMode = 'V';
    strcpy(dverb,"__");
    }
  if (key == 'n' && entryMode == '-') {
    entryMode = 'N';
    strcpy(dnoun,"__");
    }
  if (key >= '0' && key <= '9' && entryMode != '-') {
    p = -1;
    if (entryMode == 'P') buffer=dprog;
    if (entryMode == 'V') buffer=dverb;
    if (entryMode == 'N') buffer=dnoun;
    if (entryMode == '1') buffer=dreg1;
    if (entryMode == '2') buffer=dreg2;
    if (entryMode == '3') buffer=dreg3;
    for (i=0; i<strlen(buffer); i++)
      if (p == -1 && buffer[i] == '_') p = i;
    if (p >= 0) {
      buffer[p] = key;
      if ((UInt8)p == strlen(buffer) - 1) {
        if (entryMode == 'P') prog = atoi(dprog);
        if (entryMode == 'V') verb = atoi(dverb);
        if (entryMode == '1') reg1 = atoi(dreg1);
        if (entryMode == '2') reg2 = atoi(dreg2);
        if (entryMode == '3') reg3 = atoi(dreg3);
        if (entryMode == 'N') {
          noun = atoi(dnoun);
          _processNoun();
          }
        else entryMode = '-';
        }
      }
    }
  if (key == '-' && entryMode != '-') {
    if (entryMode == 'P') buffer=dprog;
    if (entryMode == 'V') buffer=dverb;
    if (entryMode == 'N') buffer=dnoun;
    if (entryMode == '1') buffer=dreg1;
    if (entryMode == '2') buffer=dreg2;
    if (entryMode == '3') buffer=dreg3;
    if (buffer[0] == '+') buffer[0] = '-';
    }
  if (key == '+' && entryMode != '-') {
    if (entryMode == 'P') buffer=dprog;
    if (entryMode == 'V') buffer=dverb;
    if (entryMode == 'N') buffer=dnoun;
    if (entryMode == '1') buffer=dreg1;
    if (entryMode == '2') buffer=dreg2;
    if (entryMode == '3') buffer=dreg3;
    if (buffer[0] == '-') buffer[0] = '+';
    }
  }

Int8 CsmComputer::Load(FILE* file) {
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) {
      sprintf(dprog,"%02d",prog);
      sprintf(dverb,"%02d",verb);
      sprintf(dnoun,"%02d",noun);
      return -1;
      }
    else if (startsWith(pline,"altitude ")) altitude = atof(nw(pline));
    else if (startsWith(pline,"velocity ")) velocity = atof(nw(pline));
    else if (startsWith(pline,"prog ")) prog = atoi(nw(pline));
    else if (startsWith(pline,"noun ")) noun = atoi(nw(pline));
    else if (startsWith(pline,"verb ")) verb = atoi(nw(pline));
    else if (startsWith(pline,"reg1 ")) _reg1(atoi(nw(pline)));
    else if (startsWith(pline,"reg2 ")) _reg2(atoi(nw(pline)));
    else if (startsWith(pline,"reg3 ")) _reg3(atoi(nw(pline)));
    else if (startsWith(pline,"running ")) running = atoi(nw(pline));
    else if (startsWith(pline,"entrymode ")) entryMode = (nw(pline))[0];
    else return 0;
    }
  sprintf(dprog,"%02d",prog);
  sprintf(dverb,"%02d",verb);
  sprintf(dnoun,"%02d",noun);
  return -1;
  }

void CsmComputer::Save(FILE* file) {
  fprintf(file,"  Computer {%s",LE);
  fprintf(file,"    Altitude %.18f%s",altitude,LE);
  fprintf(file,"    Velocity %.18f%s",velocity,LE);
  fprintf(file,"    Prog %d%s",prog,LE);
  fprintf(file,"    Verb %d%s",verb,LE);
  fprintf(file,"    Noun %d%s",noun,LE);
  fprintf(file,"    Reg1 %d%s",reg1,LE);
  fprintf(file,"    Reg2 %d%s",reg2,LE);
  fprintf(file,"    Reg3 %d%s",reg3,LE);
  fprintf(file,"    Running %d%s",running,LE);
  fprintf(file,"    EntryMode %c%s",entryMode,LE);
  fprintf(file,"    }%s",LE);
  }

