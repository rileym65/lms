#include <stdio.h>
#include "header.h"

void save() {
  Int32 i;
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
  fprintf(file,"  ClockTE %d%s",clockTe,LE);
  fprintf(file,"  LandedMET %d%s",landedMet,LE);
  fprintf(file,"  LiftoffMET %d%s",liftoffMet,LE);
  fprintf(file,"  LandedLongitude %.18f%s",landedLongitude,LE);
  fprintf(file,"  LandedLatitude %.18f%s",landedLatitude,LE);
  fprintf(file,"  FarthestDistance %.18f%s",farthest,LE);
  fprintf(file,"  FlagPlanted %d%s",flagPlanted,LE);
  fprintf(file,"  FlagLongitude %.18f%s",flagLongitude,LE);
  fprintf(file,"  FlagLatitude %.18f%s",flagLatitude,LE);
  fprintf(file,"  LongestEVA %d%s",longestEVA,LE);
  fprintf(file,"  Docked %d%s",docked,LE);
  fprintf(file,"  DockingRadarOn %d%s",dockingRadarOn,LE);
  fprintf(file,"  DsnOn %d%s",dsnOn,LE);
  fprintf(file,"  Efficiency %f%s",efficiency,LE);
  fprintf(file,"  Injury %f%s",injury,LE);
  fprintf(file,"  InsMode %d%s",insMode,LE);
  fprintf(file,"  LandingRadarOn %d%s",landingRadarOn,LE);
  fprintf(file,"  MetabolicRate %f%s",metabolicRate,LE);
  fprintf(file,"  PilotLocation %c%s",pilotLocation,LE);
  fprintf(file,"  PlssPacks %d%s",plssPacks,LE);
  fprintf(file,"  PlssOn %d%s",plssOn,LE);
  fprintf(file,"  SpaceSuitOn %d%s",spaceSuitOn,LE);
  fprintf(file,"  TargetLatitude %f%s",targetLatitude,LE);
  fprintf(file,"  TargetLongitude %f%s",targetLongitude,LE);
  fprintf(file,"  SampleType %d%s",sampleType,LE);
  fprintf(file,"  SampleSmallRock %d%s",sampleSmallRock,LE);
  fprintf(file,"  SampleMediumRock %d%s",sampleMediumRock,LE);
  fprintf(file,"  SampleLargeRock %d%s",sampleLargeRock,LE);
  fprintf(file,"  SampleSmallCrater %d%s",sampleSmallCrater,LE);
  fprintf(file,"  SampleMediumCrater %d%s",sampleMediumCrater,LE);
  fprintf(file,"  SampleLargeCrater %d%s",sampleLargeCrater,LE);
  fprintf(file,"  SampleRise %d%s",sampleRise,LE);
  fprintf(file,"  SamplePlains %d%s",samplePlains,LE);
  fprintf(file,"  LrvSampleSmallRock %d%s",lrvSampleSmallRock,LE);
  fprintf(file,"  LrvSampleMediumRock %d%s",lrvSampleMediumRock,LE);
  fprintf(file,"  LrvSampleLargeRock %d%s",lrvSampleLargeRock,LE);
  fprintf(file,"  LrvSampleSmallCrater %d%s",lrvSampleSmallCrater,LE);
  fprintf(file,"  LrvSampleMediumCrater %d%s",lrvSampleMediumCrater,LE);
  fprintf(file,"  LrvSampleLargeCrater %d%s",lrvSampleLargeCrater,LE);
  fprintf(file,"  LrvSampleRise %d%s",lrvSampleRise,LE);
  fprintf(file,"  LrvSamplePlains %d%s",lrvSamplePlains,LE);
  for (i=0; i<numSamples; i++)
    fprintf(file,"  Sample %d,%d%s",samples[i].cellX,samples[i].cellY,LE);
  fprintf(file,"  }%s",LE);
  csm->Save(file);
  lm->Save(file);
  plss->Save(file);
  lrv->Save(file);
  fclose(file);
  }

