#include <stdio.h>
#include <string.h>
#include "header.h"

void MissionReport() {
  char  buffer[128];
  FILE* file;
  file = stdout;
  fprintf(file,"Mission Time Line:%s",LE);
  fprintf(file,"  Undock MET   : %s%s",ClockToString(buffer,0),LE);
  fprintf(file,"  Landed MET   : %s%s",ClockToString(buffer,landedMet),LE);
  fprintf(file,"  Liftoff MET  : %s%s",ClockToString(buffer,liftoffMet),LE);
  fprintf(file,"  Docking MET  : %s%s",ClockToString(buffer,clockMi),LE);
  fprintf(file,"%s",LE);
  fprintf(file,"Landing:%s",LE);
  fprintf(file,"  Target Longitude      : %.2f%s",targetLongitude,LE);
  fprintf(file,"  Target Latitude       : %.2f%s",targetLatitude,LE);
  fprintf(file,"  Landed Longitude      : %.2f%s",landedLongitude,LE);
  fprintf(file,"  Landed Latitude       : %.2f%s",landedLatitude,LE);
  fprintf(file,"  Vertial Velocity      : %.2f%s",landedVVel,LE);
  fprintf(file,"  Horizontal Velocity   : %.2f%s",landedHVel,LE);
  fprintf(file,"  Descent Fuel Remaining: %.2f%s",lm->DescentFuel(),LE);
  fprintf(file,"%s",LE);
  fprintf(file,"EVA:%s",LE);
  fprintf(file,"  Number of EVAs     : %d%s",evaCount,LE);
  fprintf(file,"  Longest EVA        : %s%s",ClockToString(buffer,longestEVA),LE);
  fprintf(file,"  Total EVA Time     : %s%s",ClockToString(buffer,clockTe),LE);
  fprintf(file,"  Averaga EVA time   : %s%s",ClockToString(buffer,clockTe/evaCount),LE);
  fprintf(file,"  Farthest from LM   : %.2fkm%s",farthest/1000.0,LE);
  fprintf(file,"  Distance Walked    : %.2fkm%s",plss->Walked()/1000.0,LE);
  fprintf(file,"  Distance Driven    : %.2fkm%s",lrv->Driven()/1000.0,LE);
  fprintf(file,"%s",LE);
  fprintf(file,"Samples:%s",LE);
  fprintf(file,"  Total Samples collected: %d%s",lm->Rock(),LE);
  fprintf(file,"  Samples collected from:%s",LE);
  fprintf(file,"    Small Rock          : %d%s",sampleSmallRock,LE);
  fprintf(file,"    Medium Rock         : %d%s",sampleMediumRock,LE);
  fprintf(file,"    Large Rock          : %d%s",sampleLargeRock,LE);
  fprintf(file,"    Small Crater        : %d%s",sampleSmallCrater,LE);
  fprintf(file,"    Medium Crater       : %d%s",sampleMediumCrater,LE);
  fprintf(file,"    Large Crater        : %d%s",sampleLargeCrater,LE);
  fprintf(file,"    Plains              : %d%s",samplePlains,LE);
  fprintf(file,"    Rises               : %d%s",sampleRise,LE);
  }

