#include <stdio.h>
#include "header.h"
#include "computer.h"
#include "common.h"
#include "g_clockev.h"
#include "g_clockte.h"
#include "g_clockut.h"

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
  fprintf(file,"  ClockUD %d%s",clockUd,LE);
  fprintf(file,"  ClockDOI %d%s",clockDOI,LE);
  fprintf(file,"  ClockPDI %d%s",clockPDI,LE);
  fprintf(file,"  DockingVel %.18f%s",dockingVel,LE);
  fprintf(file,"  DockingLVel %.18f%s",dockingLVel,LE);
  fprintf(file,"  ModeAbo %d%s",mode_abo,LE);
  fprintf(file,"  ModeArm %d%s",mode_arm,LE);
  fprintf(file,"  ModeJet %d%s",mode_jet,LE);
  fprintf(file,"  ModeKil %d%s",mode_kil,LE);
  fprintf(file,"  ModeLif %d%s",mode_lif,LE);
  fprintf(file,"  EvaCount %d%s",evaCount,LE);
  fprintf(file,"  LandedMET %d%s",landedMet,LE);
  fprintf(file,"  LiftoffMET %d%s",liftoffMet,LE);
  fprintf(file,"  LandedLongitude %.18f%s",landedLongitude,LE);
  fprintf(file,"  LandedLatitude %.18f%s",landedLatitude,LE);
  fprintf(file,"  LandedHVel %.18f%s",landedHVel,LE);
  fprintf(file,"  LandedVVel %.18f%s",landedVVel,LE);
  fprintf(file,"  FarthestDistance %.18f%s",farthest,LE);
  fprintf(file,"  FlagPlanted %d%s",flagPlanted,LE);
  fprintf(file,"  FlagLongitude %.18f%s",flagLongitude,LE);
  fprintf(file,"  FlagLatitude %.18f%s",flagLatitude,LE);
  fprintf(file,"  LaserSetup %d%s",laserSetup,LE);
  fprintf(file,"  LaserLongitude %.18f%s",laserLongitude,LE);
  fprintf(file,"  LaserLatitude %.18f%s",laserLatitude,LE);
  fprintf(file,"  AlsepSetup %d%s",alsepSetup,LE);
  fprintf(file,"  AlsepLongitude %.18f%s",alsepLongitude,LE);
  fprintf(file,"  AlsepLatitude %.18f%s",alsepLatitude,LE);
  fprintf(file,"  LongestEVA %d%s",longestEVA,LE);
  fprintf(file,"  Docked %d%s",docked,LE);
  fprintf(file,"  DockingRadarOn %d%s",dockingRadarOn,LE);
  fprintf(file,"  DsnOn %d%s",dsnOn,LE);
  fprintf(file,"  Efficiency %f%s",efficiency,LE);
  fprintf(file,"  Injury %f%s",injury,LE);
  fprintf(file,"  SoftInjury %f%s",softInjury,LE);
  fprintf(file,"  HardInjury %f%s",hardInjury,LE);
  fprintf(file,"  LandingRadarOn %d%s",landingRadarOn,LE);
  fprintf(file,"  MetabolicRate %f%s",metabolicRate,LE);
  fprintf(file,"  PilotLocation %c%s",pilotLocation,LE);
  fprintf(file,"  PlssPacks %d%s",plssPacks,LE);
  fprintf(file,"  PlssOn %d%s",plssOn,LE);
  fprintf(file,"  SpaceSuitOn %d%s",spaceSuitOn,LE);
  fprintf(file,"  NumBurns %d%s",numBurns,LE);
  fprintf(file,"  IgnitionTime %d%s",ignitionTime,LE);
  fprintf(file,"  IgnitionAltitude %.18f%s",ignitionAltitude,LE);
  fprintf(file,"  SampleType %d%s",sampleType,LE);
  fprintf(file,"  SampleSmallRock %d%s",sampleSmallRock,LE);
  fprintf(file,"  SampleMediumRock %d%s",sampleMediumRock,LE);
  fprintf(file,"  SampleLargeRock %d%s",sampleLargeRock,LE);
  fprintf(file,"  SampleSmallCrater %d%s",sampleSmallCrater,LE);
  fprintf(file,"  SampleMediumCrater %d%s",sampleMediumCrater,LE);
  fprintf(file,"  SampleLargeCrater %d%s",sampleLargeCrater,LE);
  fprintf(file,"  SampleRise %d%s",sampleRise,LE);
  fprintf(file,"  SamplePlains %d%s",samplePlains,LE);
  fprintf(file,"  SampleSpecial %d%s",sampleSpecial,LE);
  fprintf(file,"  SampleDepression %d%s",sampleDepression,LE);
  fprintf(file,"  SampleCraterWall %d%s",sampleCraterWall,LE);
  fprintf(file,"  }%s",LE);
  for (i=0; i<evaCount; i++) {
    fprintf(file,"EVA %d {%s",i,LE);
    fprintf(file,"  Start %d%s",evas[i].start,LE);
    fprintf(file,"  End %d%s",evas[i].end,LE);
    fprintf(file,"  Walked %.18f%s",evas[i].walked,LE);
    fprintf(file,"  Driven %.18f%s",evas[i].driven,LE);
    fprintf(file,"  Farthest %.18f%s",evas[i].farthest,LE);
    fprintf(file,"  Samples %d%s",evas[i].samples,LE);
    fprintf(file,"  }%s",LE);
    }
  for (i=0; i<numBurns; i++) {
    fprintf(file,"Burn %d {%s",i,LE);
    fprintf(file,"  Start %d%s",burn[i].start,LE);
    fprintf(file,"  End %d%s",burn[i].end,LE);
    fprintf(file,"  FuelUsed %.18f%s",burn[i].fuelUsed,LE);
    fprintf(file,"  Engine %c%s",burn[i].engine,LE);
    fprintf(file,"  }%s",LE);
    }
  mission->Save(file);
  csm->Save(file);
  lm->Save(file);
  plss->Save(file);
  lrv->Save(file);
  if (lm->Comp() != NULL) lm->Comp()->Save(file);
  fclose(file);
  }

