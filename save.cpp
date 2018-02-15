#include <stdio.h>
#include "header.h"

void save() {
  FILE *file;
  file = fopen("lms.sav","w");
  fprintf(file,"Simulation {%s",LE);
  fprintf(file,"  CabinPressurized %d%s",cabinPressurized,LE);
  fprintf(file,"  ClockBU %d%s",clockBu,LE);
  fprintf(file,"  ClockDK %d%s",clockDk,LE);
  fprintf(file,"  ClockEV %d%s",clockEv,LE);
  fprintf(file,"  ClockOR %d%s",clockOr,LE);
  fprintf(file,"  ClockMI %d%s",clockMi,LE);
  fprintf(file,"  ClockUT %d%s",clockUt,LE);
  fprintf(file,"  Docked %d%s",docked,LE);
  fprintf(file,"  DockingRadarOn %d%s",dockingRadarOn,LE);
  fprintf(file,"  DsnOn %d%s",dsnOn,LE);
  fprintf(file,"  Efficiency %f%s",efficiency,LE);
  fprintf(file,"  Injury %f%s",injury,LE);
  fprintf(file,"  InsMode %d%s",insMode,LE);
  fprintf(file,"  LandingRadarOn %d%s",landingRadarOn,LE);
  fprintf(file,"  LmRock %d%s",lmRock,LE);
  fprintf(file,"  LrvBattery %f%s",lrvBattery,LE);
  fprintf(file,"  LrvRock %d%s",lrvRock,LE);
  fprintf(file,"  MetabolicRate %f%s",metabolicRate,LE);
  fprintf(file,"  PilotLocation %c%s",pilotLocation,LE);
  fprintf(file,"  PlssBattery %f%s",plssBattery,LE);
  fprintf(file,"  PlssOxygen %f%s",plssOxygen,LE);
  fprintf(file,"  PlssPacks %d%s",plssPacks,LE);
  fprintf(file,"  PlssOn %d%s",plssOn,LE);
  fprintf(file,"  SampleBoxes %d%s",sampleBoxes,LE);
  fprintf(file,"  SpaceSuitOn %d%s",spaceSuitOn,LE);
  fprintf(file,"  }%s",LE);
  csm->Save(file);
  lm->Save(file);
  fclose(file);
  }

