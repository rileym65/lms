#include <stdio.h>
#include "header.h"
#include "g_clockbu.h"
#include "g_clockmi.h"
#include "g_clocktb.h"
#include "g_clockut.h"
#include "g_days.h"
#include "g_moon.h"
#include "g_position.h"

void save() {
  FILE *file;
  file = fopen("fms.sav","w");
  fprintf(file,"Simulation {%s",LE);
  fprintf(file,"  ClockBU %d%s",clockBu,LE);
  fprintf(file,"  ClockMI %d%s",clockMi,LE);
  fprintf(file,"  ClockUT %d%s",clockUt,LE);
  fprintf(file,"  ClockTB %d%s",clockTb,LE);
  fprintf(file,"  Days %d%s",days,LE);
  fprintf(file,"  KscAngle %.18f%s",kscAngle,LE);
  if (launched) fprintf(file,"  Launched true%s",LE);
    else fprintf(file,"  Launched false%s",LE);
  fprintf(file,"  }%s",LE);
  csm->Save(file);
  booster->Save(file);
  Earth->Save(file);
  Moon->Save(file);
  fclose(file);
  }

