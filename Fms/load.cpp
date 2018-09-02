#include <stdio.h>
#include <string.h>
#include "header.h"
#include "helpers.h"
#include "terminal.h"
#include "g_clockbu.h"
#include "g_clockmi.h"
#include "g_clocktb.h"
#include "g_clockut.h"
#include "g_days.h"
#include "g_moon.h"
#include "g_position.h"

void loadSimulation(FILE* file) {
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    else if (startsWith(pline,"clockbu ")) clockBu = atoi(nw(pline));
    else if (startsWith(pline,"clockge ")) clockGe = atoi(nw(pline));
    else if (startsWith(pline,"clockmi ")) clockMi = atoi(nw(pline));
    else if (startsWith(pline,"clockut ")) clockUt = atoi(nw(pline));
    else if (startsWith(pline,"clocktb ")) clockTb = atoi(nw(pline));
    else if (startsWith(pline,"days ")) days = atoi(nw(pline));
    else if (startsWith(pline,"kscangle ")) kscAngle = atof(nw(pline));
    else if (startsWith(pline,"distance ")) distance = atof(nw(pline));
    else if (startsWith(pline,"launched true")) launched = true;
    else if (startsWith(pline,"launched false")) launched = false;
    else {
      Write("Unknown line found in save file: ");
      WriteLn(pline);
      exit(1);
      }
    }
  }

Int8 load(const char* filename) {
  FILE* file;
  char* pline;
  file = fopen(filename,"r");
  if (file == NULL) return 0;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"simulation {")) loadSimulation(file);
    else if (startsWith(pline,"booster {")) booster->Load(file);
    else if (startsWith(pline,"commandmodule {")) csm->Load(file);
    else if (startsWith(pline,"earth {")) Earth->Load(file);
    else if (startsWith(pline,"moon {")) Moon->Load(file);
    else {
      Write("Unknown line found in save file: ");
      WriteLn(pline);
      exit(1);
      }
    }

  fclose(file);
  return -1;
  }

