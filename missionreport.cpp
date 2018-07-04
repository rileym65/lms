#include <stdio.h>
#include <string.h>
#include "header.h"
#include "records.h"

void MissionReport() {
  Int32 i;
  char  buffer[128];
  char  buffer2[128];
  char  buffer3[128];
  char  filename[128];
  FILE* file;
  Records* records;
  Double singleWalk;
  Double singleDrive;
  Double dist;
  records = new Records();
  i = 0;
  sprintf(filename,"report_%04d.txt",i);
  file = fopen(filename,"r");
  while (file != NULL) {
    fclose(file);
    i++;
    sprintf(filename,"report_%04d.txt",i);
    file = fopen(filename,"r");
    }
  file = fopen(filename,"w");
  fprintf(file,"Mission    : %s%s",mission->Name(),LE);
  fprintf(file,"Description: %s%s",mission->Description(),LE);
  fprintf(file,"Region     : %s%s%s",mission->Region(),LE,LE);
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
  dist = distance(landedLongitude,landedLatitude,mission->TargetLongitude(),
             mission->TargetLatitude());
  fprintf(file,"  Distance From Target  : %.2f%s",
    distance(landedLongitude,landedLatitude,mission->TargetLongitude(),
             mission->TargetLatitude()),LE);
  fprintf(file,"  Vertical Velocity     : %.2f%s",landedVVel,LE);
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
  singleWalk = 0;
  singleDrive = 0;
  for (i=0; i<evaCount; i++) {
    fprintf(file,"    %2d %8s %8s  %8s %6.2fkm %6.2fkm  %6.2fkm   %3d%s",
      i+1,ClockToString(buffer,evas[i].start),
      ClockToString(buffer2,evas[i].end),
      ClockToString(buffer3,evas[i].end-evas[i].start),
      evas[i].walked/1000.0,evas[i].driven/1000.0,evas[i].farthest/1000.0,
      evas[i].samples,LE);
    if (evas[i].walked > singleWalk) singleWalk = evas[i].walked;
    if (evas[i].driven > singleDrive) singleDrive = evas[i].driven;
    }
  fprintf(file,"%s",LE);
  fprintf(file,"Samples:%s",LE);
  fprintf(file,"  Total Samples Collected: %d%s",lm->Rock(),LE);
  fprintf(file,"  Samples collected from:%s",LE);
  fprintf(file,"    Small Rock       : %d%s",sampleSmallRock,LE);
  fprintf(file,"    Medium Rock      : %d%s",sampleMediumRock,LE);
  fprintf(file,"    Large Rock       : %d%s",sampleLargeRock,LE);
  fprintf(file,"    Small Crater     : %d%s",sampleSmallCrater,LE);
  fprintf(file,"    Medium Crater    : %d%s",sampleMediumCrater,LE);
  fprintf(file,"    Large Crater     : %d%s",sampleLargeCrater,LE);
  fprintf(file,"    Plains           : %d%s",samplePlains,LE);
  fprintf(file,"    Rises            : %d%s",sampleRise,LE);
  fprintf(file,"    Depressions      : %d%s",sampleDepression,LE);
  fprintf(file,"    Special          : %d%s",sampleSpecial,LE);
  fprintf(file,"    Primary site     : %d%s",primarySamples,LE);
  fprintf(file,"    Secondary site 1 : %d%s",secondary1Samples,LE);
  fprintf(file,"    Secondary site 2 : %d%s",secondary2Samples,LE);
  fprintf(file,"    Secondary site 3 : %d%s",secondary3Samples,LE);
  fprintf(file,"%s",LE);
  fprintf(file,"Rendevous/Docking:%s",LE);
  fprintf(file,"  Time to dock         : %s%s",ClockToString(buffer,clockDk),LE);
  fprintf(file,"  Docking velocity     : %.2fm/s%s",dockingVel,LE);
  fprintf(file,"  Lateral velocity     : %.2fm/s%s",dockingLVel,LE);
  fprintf(file,"  Docking X alignemnent: %.2fm%s",dockingXAlign,LE);
  fprintf(file,"  Docking Y alignemnent: %.2fm%s",dockingYAlign,LE);
  fprintf(file,"  Ascent Fuel Remaining: %.2f%s",lm->AscentFuel(),LE);
  fprintf(file,"  RCS Fuel Remaining   : %.2f%s",lm->RcsFuel(),LE);
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
    if (burn[i].engine == 'D') fprintf(file,"Descent%s",LE);
      else fprintf(file,"Ascent%s",LE);
    }
  fprintf(file,"%s",LE);
  fprintf(file,"Records Broken:%s",LE);
  if (clockMi > records->LongestMission) {
    records->LongestMission = clockMi;
    fprintf(file,"  Longest Mission         : %s%s",ClockToString(buffer,clockMi),LE);
    }
  if (longestEVA > records->LongestEva) {
    records->LongestEva = longestEVA;
    fprintf(file,"  Longest EVA             : %s%s",ClockToString(buffer,longestEVA),LE);
    }
  if (evaCount > 2 && clockTe/evaCount > records->LongestAverageEva) {
    records->LongestAverageEva = clockTe/evaCount;
    fprintf(file,"  Longest Average EVA     : %s%s",ClockToString(buffer,clockTe/evaCount),LE);
    }
  if (clockTe > records->LongestTotalEva) {
    records->LongestTotalEva = clockTe;
    fprintf(file,"  Longest Total EVA       : %s%s",ClockToString(buffer,clockTe),LE);
    }
  if (landedMet < records->ShortestLanding) {
    records->ShortestLanding = landedMet;
    fprintf(file,"  Shortest Time to Land   : %s%s",ClockToString(buffer,landedMet),LE);
    }
  if (clockDk < records->ShortestDocking) {
    records->ShortestDocking = clockDk;
    fprintf(file,"  Shortest Time to Dock   : %s%s",ClockToString(buffer,clockDk),LE);
    }
  if (dist < records->ClosestToTarget) {
    records->ClosestToTarget = dist;
    if (dist >= 10000)
      fprintf(file,"  Closest to Target       : %9.2fkm%s",dist/1000.0,LE);
    else 
      fprintf(file,"  Closest to Target       : %9.2fm%s",dist,LE);
    }
  if (landedLatitude > records->HighestLatitude) {
    records->HighestLatitude = landedLatitude;
    fprintf(file,"  Highest Latitude Landing: %9.2f%s",landedLatitude,LE);
    }
  if (landedLatitude < records->LowestLatitude) {
    records->LowestLatitude = landedLatitude;
    fprintf(file,"  Lowest Latitude Landing : %9.2f%s",landedLatitude,LE);
    }
  if (singleWalk > records->LongestSingleWalk) {
    records->LongestSingleWalk = singleWalk;
    fprintf(file,"  Longest Ind. EVA Walked : %9.2fkm%s",singleWalk/1000.0,LE);
    }
  if (plss->Walked() > records->LongestTotalWalk) {
    records->LongestTotalWalk = plss->Walked();
    fprintf(file,"  Longest Tot. EVA Walked : %9.2fkm%s",plss->Walked()/1000.0,LE);
    }
  if (singleDrive > records->LongestSingleDrive) {
    records->LongestSingleDrive = singleDrive;
    fprintf(file,"  Longest Ind. EVA Drivin : %9.2fkm%s",singleDrive/1000.0,LE);
    }
  if (lrv->Driven() > records->LongestTotalDrive) {
    records->LongestTotalDrive = lrv->Driven();
    fprintf(file,"  Longest Tot. EVA Driven : %9.2fkm%s",lrv->Driven()/1000.0,LE);
    }
  if (farthest > records->FarthestFromLM) {
    records->FarthestFromLM = farthest;
    fprintf(file,"  Farthest From LM        : %9.2fkm%s",farthest/1000.0,LE);
    }
  if (lm->Value() > records->GreatestSampleValue) {
    records->GreatestSampleValue = lm->Value();
    fprintf(file,"  Greatest Sample Value   : %9.2f%s",lm->Value(),LE);
    }
  if (lm->DescentFuel() > records->DescentFuel) {
    records->DescentFuel = lm->DescentFuel();
    fprintf(file,"  Descent Fuel Remaining  : %9.2fkg%s",lm->DescentFuel(),LE);
    }
  if (lm->AscentFuel() > records->AscentFuel) {
    records->AscentFuel = lm->AscentFuel();
    fprintf(file,"  Ascent Fuel Remaining   : %9.2fkg%s",lm->AscentFuel(),LE);
    }
  if (lm->RcsFuel() > records->RcsFuel) {
    records->RcsFuel = lm->RcsFuel();
    fprintf(file,"  RCS Fuel Remaining      : %9.2fkg%s",lm->RcsFuel(),LE);
    }
  fprintf(file,"%s%s",LE,LE);
  fprintf(file,"Landing Score:%s",LE);
  fprintf(file,"  Landing Time:         %d%s",ScoreLandedTime, LE);
  fprintf(file,"  Fuel Remaining:       %d%s",ScoreDescentFuel, LE);
  fprintf(file,"  Distance from target: %d%s",ScoreLandedDistance, LE);
  fprintf(file,"  Vertical Velocity:    %d%s",ScoreLandedVVel, LE);
  fprintf(file,"  Horizontal Velocity:  %d%s",ScoreLandedHVel, LE);
  if (ScoreLatitudeBonus > 0)
    fprintf(file,"  Latitude Bonus:       %d%s",ScoreLatitudeBonus, LE);
  fprintf(file,"                                --------%s",LE);
  fprintf(file,"    Landing Total:              %d%s",ScoreLanding,LE);
  fprintf(file,"%s",LE);
  fprintf(file,"Surface Operations Score:%s",LE);
  fprintf(file,"  EVAs completed:       %d%s",ScoreEvaCompleted,LE);
  fprintf(file,"  Time Spent on EVA:    %d%s",ScoreEvaTime,LE);
  fprintf(file,"  LRV Setup:            %d%s",ScoreEvaLrvSetup,LE);
  fprintf(file,"  Laser Refl. Setup:    %d%s",ScoreEvaLaserSetup,LE);
  fprintf(file,"  Flag Planted:         %d%s",ScoreEvaFlagSetup,LE);
  fprintf(file,"  ALSEP Setup:          %d%s",ScoreEvaAlsepSetup,LE);
  fprintf(file,"  Samples Collected:    %d%s",ScoreEvaSamples,LE);
  fprintf(file,"  Primary Samples:      %d%s",ScoreEvaPrimarySamples,LE);
  fprintf(file,"  Sec. Site 1 Samples:  %d%s",ScoreEvaSecondary1Samples,LE);
  fprintf(file,"  Sec. Site 2 Samples:  %d%s",ScoreEvaSecondary2Samples,LE);
  fprintf(file,"  Sec. Site 3 Samples:  %d%s",ScoreEvaSecondary3Samples,LE);
  fprintf(file,"  Sample Value:         %d%s",ScoreEvaValue,LE);
  fprintf(file,"  Distance from LM:     %d%s",ScoreEvaFarthest,LE);
  fprintf(file,"  Distance Driven:      %d%s",ScoreEvaDriven,LE);
  fprintf(file,"                                --------%s",LE);
  fprintf(file,"    Surface Operations Total:   %d%s",ScoreEvaTotal,LE);
  fprintf(file,"%s",LE);
  fprintf(file,"Rendevous/Docking Score:%s",LE);
  fprintf(file,"  Docking Time:         %d%s",ScoreDockTime,LE);
  fprintf(file,"  Docking Velocity:     %d%s",ScoreDockVel,LE);
  fprintf(file,"  Lateral Velocity:     %d%s",ScoreDockLVel,LE);
  fprintf(file,"  Asc Fuel Remaining:   %d%s",ScoreDockAscentFuel,LE);
  fprintf(file,"  RCS Fuel Remaining:   %d%s",ScoreDockRcsFuel,LE);
  fprintf(file,"                                --------%s",LE);
  fprintf(file,"    Rendevous/Docking Total:    %d%s",ScoreDockTotal,LE);
  fprintf(file,"%s",LE);
  fprintf(file,"                                --------%s",LE);
  fprintf(file,"    Total Score:                %d%s",ScoreTotal,LE);
  fprintf(file,"%s%s",LE,LE);

  if (file != stdout) fclose(file);
  records->Save();
  WriteLn("");
  Write("Mission report written to ");
  WriteLn(filename);
  }

