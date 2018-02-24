#include <stdio.h>
#include <string.h>
#include "header.h"
#include "panel.h"
#include "terminal.h"
#include "gauge.h"
#include "g_amsatt.h"
#include "g_amsclocks.h"
#include "g_amscons.h"
#include "g_amsdock.h"
#include "g_amsdown.h"
#include "g_amsins.h"
#include "g_amsland.h"
#include "g_amslm.h"
#include "g_amslrv.h"
#include "g_amsmsg.h"
#include "g_amspilot.h"
#include "g_amsplss.h"
#include "g_amsseq.h"
#include "g_amsspin.h"
#include "g_amsstat.h"
#include "g_amswest.h"

Panel::Panel(const char* filename) {
  Int8 x,y;
  for (y=0; y<24; y++)
    for (x=0; x<80; x++)
      screen[y][x] = ' ';
  for (y=0; y<24; y++)
    screen[y][80] = 0;
  for (x=0; x<100; x++)
    gauges[x] = NULL;
  numGauges = 0;
  useDefault();
  }

Panel::~Panel() {
  }

void Panel::addGauge(Gauge* g) {
  if (numGauges < 100) {
    gauges[numGauges++] = g;
    }
  else delete(g);
  }

void Panel::useDefault() {
  Box(1,1,80,16);
  Box(1,16,80,24);
  VLine(27,1,16);
  VLine(54,1,16);
  HLine(27,3,54);
  VLine(31,2,2);
  VLine(51,2,2);
  VLine(35,12,15);
  VLine(43,12,15);
  VLine(47,12,15);
  Label(45,12,"--");
  Label(45,13,"--");
  Label(45,14,"--");
  Label(45,15,"--");
  VLine(9,17,20);
  VLine(16,17,23);
  VLine(24,17,23);
  VLine(52,17,23);
  VLine(67,17,23);
  HLine(2,21,15);
  HLine(36,22,51);
  VLine(36,22,23);
  Label(47,23,":");
  addGauge(new G_AmsAtt(2, 17, false));
  addGauge(new G_AmsClocks(68, 17, false));
  addGauge(new G_AmsCons(17, 17, false));
  addGauge(new G_AmsDock(41,  4, false));
  addGauge(new G_AmsDown(55,  2, false));
  addGauge(new G_AmsIns(25, 17, false));
  addGauge(new G_AmsLand(28,  4, false));
  addGauge(new G_AmsLm(48, 12, false));
  addGauge(new G_AmsLrv(37, 12, false));
  addGauge(new G_AmsMessage(37, 23, false));
  addGauge(new G_AmsPilot(32,  2, false));
  addGauge(new G_AmsPlss(29, 12, false));
  addGauge(new G_AmsSeq( 2, 22, false));
  addGauge(new G_AmsSpin(10, 17, false));
  addGauge(new G_AmsStatus(53, 17, false));
  addGauge(new G_AmsWest( 2,  2, false));
  }

void Panel::Box(Int8 x1,Int8 y1,Int8 x2,Int8 y2) {
  HLine(x1,y1,x2);
  HLine(x1,y2,x2);
  VLine(x1,y1,y2);
  VLine(x2,y1,y2);
  }

void Panel::HLine(Int8 x1,Int8 y1,Int8 x2) {
  Int8 i;
  y1--;
  for (i=x1-1; i<x2; i++) {
    if (screen[y1][i] == '|') screen[y1][i] = '+';
    else if (screen[y1][i] == '+') screen[y1][i] = '+';
    else screen[y1][i] = '-';
    }
  }

void Panel::VLine(Int8 x1,Int8 y1,Int8 y2) {
  Int8 i;
  x1--;
  for (i=y1-1; i<y2; i++) {
    if (screen[i][x1] == '-') screen[i][x1] = '+';
    else if (screen[i][x1] == '+') screen[i][x1] = '+';
    else screen[i][x1] = '|';
    }
  }

void Panel::Label(Int8 x,Int8 y,const char* label) {
  UInt8 i;
  for (i=0; i<strlen(label); i++)
    screen[y-1][x-1+i] = label[i];
  }

void Panel::Display() {
  Int8 i;
  ClrScr();
  for (i=0; i<24; i++) {
    GotoXY(1,i+1);
    printf("%s",screen[i]);
    }
  for (i=0; i<numGauges; i++)
    gauges[i]->Display();
  fflush(stdout);
  }

void Panel::Update() {
  Int8 i;
  for (i=0; i<numGauges; i++)
    gauges[i]->Update();
  fflush(stdout);
  }

void Panel::Reset() {
  Int8 i;
  for (i=0; i<numGauges; i++)
    gauges[i]->Reset();
  fflush(stdout);
  }

