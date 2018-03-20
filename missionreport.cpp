#include <stdio.h>
#include <string.h>
#include "header.h"

void MissionReport() {
  Int32 i;
  char  buffer[128];
  char  buffer2[128];
  char  buffer3[128];
  FILE* file;
  file = stdout;
  fprintf(file,"Mission Time Line:%s",LE);
  fprintf(file,"  Undock UTC    : %s%s",ClockToString(buffer,clockUd),LE);
  if (clockDOI != 0)
    fprintf(file,"  DOI Burn      : %s%s",ClockToString(buffer,clockDOI),LE);
  if (clockPDI != 0)
    fprintf(file,"  PDI Burn      : %s%s",ClockToString(buffer,clockPDI),LE);
  fprintf(file,"  Landed MET    : %s%s",ClockToString(buffer,landedMet),LE);
  for (i=0; i<evaCount; i++) {
    fprintf(file,"  EVA #%2d Start : %s%s",i+1,ClockToString(buffer,evas[i].start),LE);
    fprintf(file,"  EVA #%2d End   : %s%s",i+1,ClockToString(buffer,evas[i].end),LE);
    }
  fprintf(file,"  Liftoff MET   : %s%s",ClockToString(buffer,liftoffMet),LE);
  fprintf(file,"  Docking MET   : %s%s",ClockToString(buffer,clockMi),LE);
  fprintf(file,"%s",LE);
  fprintf(file,"Landing:%s",LE);
  fprintf(file,"  Target Longitude      : %.2f%s",mission->TargetLongitude(),LE);
  fprintf(file,"  Target Latitude       : %.2f%s",mission->TargetLatitude(),LE);
  fprintf(file,"  Landed Longitude      : %.2f%s",landedLongitude,LE);
  fprintf(file,"  Landed Latitude       : %.2f%s",landedLatitude,LE);
  fprintf(file,"  Distance From Target  : %.2f%s",
    distance(landedLongitude,landedLatitude,mission->TargetLongitude(),
             mission->TargetLatitude()),LE);
  fprintf(file,"  Vertial Velocity      : %.2f%s",landedVVel,LE);
  fprintf(file,"  Horizontal Velocity   : %.2f%s",landedHVel,LE);
  fprintf(file,"  Descent Fuel Remaining: %.2f%s",lm->DescentFuel(),LE);
  fprintf(file,"%s",LE);
  fprintf(file,"EVA:%s",LE);
  fprintf(file,"  Number of EVAs     : %d%s",evaCount,LE);
  fprintf(file,"  Longest EVA        : %s%s",ClockToString(buffer,longestEVA),LE);
  fprintf(file,"  Total EVA Time     : %s%s",ClockToString(buffer,clockTe),LE);
  fprintf(file,"  Average EVA time   : %s%s",ClockToString(buffer,clockTe/evaCount),LE);
  fprintf(file,"  Farthest from LM   : %.2fkm%s",farthest/1000.0,LE);
  fprintf(file,"  Distance Walked    : %.2fkm%s",plss->Walked()/1000.0,LE);
  fprintf(file,"  Distance Driven    : %.2fkm%s",lrv->Driven()/1000.0,LE);
  fprintf(file,"  EVA details:%s",LE);
  fprintf(file,"     #     start       end   duration   walked   driven  farthest  samples%s",LE);
  fprintf(file,"    ----------------------------------------------------------------------%s",LE);
  for (i=0; i<evaCount; i++)
    fprintf(file,"    %2d %8s %8s  %8s %6.2fkm %6.2fkm  %6.2fkm   %3d%s",
      i+1,ClockToString(buffer,evas[i].start),
      ClockToString(buffer2,evas[i].end),
      ClockToString(buffer3,evas[i].end-evas[i].start),
      evas[i].walked/1000.0,evas[i].driven/1000.0,evas[i].farthest/1000.0,
      evas[i].samples,LE);
  fprintf(file,"%s",LE);
  fprintf(file,"Samples:%s",LE);
  fprintf(file,"  Total Samples Collected: %d%s",lm->Rock(),LE);
  fprintf(file,"  Samples collected from:%s",LE);
  fprintf(file,"    Small Rock          : %d%s",sampleSmallRock,LE);
  fprintf(file,"    Medium Rock         : %d%s",sampleMediumRock,LE);
  fprintf(file,"    Large Rock          : %d%s",sampleLargeRock,LE);
  fprintf(file,"    Small Crater        : %d%s",sampleSmallCrater,LE);
  fprintf(file,"    Medium Crater       : %d%s",sampleMediumCrater,LE);
  fprintf(file,"    Large Crater        : %d%s",sampleLargeCrater,LE);
  fprintf(file,"    Plains              : %d%s",samplePlains,LE);
  fprintf(file,"    Rises               : %d%s",sampleRise,LE);
  fprintf(file,"    Depressions         : %d%s",sampleDepression,LE);
  fprintf(file,"    Special             : %d%s",sampleSpecial,LE);
  fprintf(file,"%s",LE);
  fprintf(file,"Main Engine Burns:%s",LE);
  fprintf(file,"    Start       End    Duration    Fuel   Engine%s",LE);
  fprintf(file,"     MET        MET                 kg          %s",LE);
  fprintf(file,"  -----------------------------------------------%s",LE);
  for (i=0; i<numBurns; i++) {
    fprintf(file,"  %8s %8s %8s %8.2f  ",
      ClockToString(buffer,burn[i].start),
      ClockToString(buffer2,burn[i].end),
      ClockToString(buffer3,burn[i].end-burn[i].start),
      burn[i].fuelUsed);
    if (burn[i].engine == 'D') printf("Descent%s",LE);
      else printf("Ascent%s",LE);
    }
  
  }

