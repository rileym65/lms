#include <stdio.h>
#include "header.h"

void save() {
  Int32 i;
  FILE *file;
  file = fopen("launch.sav","w");
  fprintf(file,"Simulation {%s",LE);
  fprintf(file,"  ClockBU %d%s",clockBu,LE);
  fprintf(file,"  ClockMI %d%s",clockMi,LE);
  fprintf(file,"  ClockUT %d%s",clockUt,LE);
  fprintf(file,"  ClockTB %d%s",clockTb,LE);
  fprintf(file,"  KscAngle %.18f%s",kscAngle,LE);
  if (launched) fprintf(file,"  Launched true%s",LE);
    else fprintf(file,"  Launched false%s",LE);
  fprintf(file,"  }%s",LE);
  booster->Save(file);
  fclose(file);
  }

