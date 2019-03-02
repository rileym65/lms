#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "common.h"
#include "records.h"
#include "helpers.h"

Records::Records() {
  load();
  }

Records::~Records() {
  }

void Records::load() {
  char* pline;
  FILE* file;
  file = fopen("records.dat","r");
  if (file == NULL) {
    AscentFuel = 0;
    ClosestToTarget = 400000000;
    DescentFuel = 0;
    DistanceTravelled = 0;
    FarthestFromEarth = 0;
    FarthestFromLM = 0;
    GreatestSampleValue = 0;
    HighestLatitude = 0;
    HighestVelocity = 0;
    LongestAverageEva = 0;
    LongestEva = 0;
    LongestMission = 0;
    LongestLunarMission = 0;
    LongestSingleDrive = 0.0;
    LongestSingleWalk = 0.0;
    LongestTotalEva = 0;
    LongestTotalDrive = 0.0;
    LongestTotalWalk = 0.0;
    LowestLatitude = 0.0;
    RcsFuel = 0;
    ShortestDocking = 999999999;
    ShortestLanding = 999999999;
    Samples = 0;
    }
  else {
    while ((pline = nextLine(file)) != NULL) {
      if (startsWith(pline,"AscentFuel")) AscentFuel = atof(nw(pline));
      if (startsWith(pline,"ClosestToTarget")) ClosestToTarget = atof(nw(pline));
      if (startsWith(pline,"DescentFuel")) DescentFuel = atof(nw(pline));
      if (startsWith(pline,"DistanceTravelled")) DistanceTravelled = atof(nw(pline));
      if (startsWith(pline,"FarthestFromEarth")) FarthestFromEarth = atof(nw(pline));
      if (startsWith(pline,"FarthestFromLM")) FarthestFromLM = atof(nw(pline));
      if (startsWith(pline,"GreatestSampleValue")) GreatestSampleValue = atof(nw(pline));
      if (startsWith(pline,"HighestLatitude")) HighestLatitude = atof(nw(pline));
      if (startsWith(pline,"HighestVelocity")) HighestVelocity = atof(nw(pline));
      if (startsWith(pline,"LongestAverageEva")) LongestAverageEva = atoi(nw(pline));
      if (startsWith(pline,"LongestEva")) LongestEva = atoi(nw(pline));
      if (startsWith(pline,"LongestMission")) LongestMission = atoi(nw(pline));
      if (startsWith(pline,"LongestLunarMission")) LongestLunarMission = atoi(nw(pline));
      if (startsWith(pline,"LongestSingleDrive")) LongestSingleDrive = atof(nw(pline));
      if (startsWith(pline,"LongestSingleWalk")) LongestSingleWalk = atof(nw(pline));
      if (startsWith(pline,"LongestTotalEva")) LongestTotalEva = atoi(nw(pline));
      if (startsWith(pline,"LongestTotalDrive")) LongestTotalDrive = atof(nw(pline));
      if (startsWith(pline,"LongestTotalWalk")) LongestTotalWalk = atof(nw(pline));
      if (startsWith(pline,"LowestLatitude")) LowestLatitude = atof(nw(pline));
      if (startsWith(pline,"RcsFuel")) RcsFuel = atof(nw(pline));
      if (startsWith(pline,"ShortestDocking")) ShortestDocking = atoi(nw(pline));
      if (startsWith(pline,"ShortestLanding")) ShortestLanding = atoi(nw(pline));
      if (startsWith(pline,"Samples")) Samples = atoi(nw(pline));
      }
    fclose(file);
    }
  }

void Records::Save() {
  char  buffer[128];
  FILE* file;
  file = fopen("records.dat","w");
  fprintf(file,"AscentFuel %.18f%s",AscentFuel,LE);
  fprintf(file,"ClosestToTarget %.18f%s",ClosestToTarget,LE);
  fprintf(file,"DescentFuel %.18f%s",DescentFuel,LE);
  fprintf(file,"DistanceTravelled %.18f%s",DistanceTravelled,LE);
  fprintf(file,"FarthestFromEarth %.18f%s",FarthestFromEarth,LE);
  fprintf(file,"FarthestFromLM %.18f%s",FarthestFromLM,LE);
  fprintf(file,"GreatestSampleValue %.18f%s",GreatestSampleValue,LE);
  fprintf(file,"HighestLatitude %.18f%s",HighestLatitude,LE);
  fprintf(file,"HighestVelocity %.18f%s",HighestVelocity,LE);
  fprintf(file,"LongestAverageEva %d%s",LongestAverageEva,LE);
  fprintf(file,"LongestEva %d%s",LongestEva,LE);
  fprintf(file,"LongestMission %d%s",LongestMission,LE);
  fprintf(file,"LongestLunarMission %d%s",LongestLunarMission,LE);
  fprintf(file,"LongestSingleDrive %.18f%s",LongestSingleDrive,LE);
  fprintf(file,"LongestSingleWalk %.18f%s",LongestSingleWalk,LE);
  fprintf(file,"LongestTotalEva %d%s",LongestTotalEva,LE);
  fprintf(file,"LongestTotalDrive %.18f%s",LongestTotalDrive,LE);
  fprintf(file,"LongestTotalWalk %.18f%s",LongestTotalWalk,LE);
  fprintf(file,"LowestLatitude %.18f%s",LowestLatitude,LE);
  fprintf(file,"RcsFuel %.18f%s",RcsFuel,LE);
  fprintf(file,"ShortestDocking %d%s",ShortestDocking,LE);
  fprintf(file,"ShortestLanding %d%s",ShortestLanding,LE);
  fprintf(file,"Samples %d%s",Samples,LE);
  fclose(file);

  file = fopen("records.txt","w");
  fprintf(file,"  Longest Mission         : %s%s",ClockToString(buffer,LongestMission),LE);
  fprintf(file,"  Longest Lunar Mission   : %s%s",ClockToString(buffer,LongestLunarMission),LE);
  fprintf(file,"  Highest Velocity        : %9.2fm/s%s",HighestVelocity,LE);
  fprintf(file,"  Farthest From Earth     : %9.2fkm%s",FarthestFromEarth/1000.0,LE);
  fprintf(file,"  Distance Travelled      : %9.2fkm%s",DistanceTravelled/1000.0,LE);
  fprintf(file,"  Longest EVA             : %s%s",ClockToString(buffer,LongestEva),LE);
  fprintf(file,"  Longest Average EVA     : %s%s",ClockToString(buffer,LongestAverageEva),LE);
  fprintf(file,"  Longest Total EVA       : %s%s",ClockToString(buffer,LongestTotalEva),LE);
  fprintf(file,"  Shortest Time to Land   : %s%s",ClockToString(buffer,ShortestLanding),LE);
  fprintf(file,"  Shortest Time to Dock   : %s%s",ClockToString(buffer,ShortestDocking),LE);
  if (ClosestToTarget >= 10000)
    fprintf(file,"  Closest to Target       : %9.2fkm%s",ClosestToTarget/1000.0,LE);
  else 
    fprintf(file,"  Closest to Target       : %9.2fm%s",ClosestToTarget,LE);
  fprintf(file,"  Highest Latitude Landing: %9.2f%s",HighestLatitude,LE);
  fprintf(file,"  Lowest Latitude Landing : %9.2f%s",LowestLatitude,LE);
  fprintf(file,"  Longest Ind. EVA Walked : %9.2fkm%s",LongestSingleWalk/1000.0,LE);
  fprintf(file,"  Longest Tot. EVA Walked : %9.2fkm%s",LongestTotalWalk/1000.0,LE);
  fprintf(file,"  Longest Ind. EVA Driven : %9.2fkm%s",LongestSingleDrive/1000.0,LE);
  fprintf(file,"  Longest Tot. EVA Driven : %9.2fkm%s",LongestTotalDrive/1000.0,LE);
  fprintf(file,"  Farthest From LM        : %9.2fkm%s",FarthestFromLM/1000.0,LE);
  fprintf(file,"  Greatest Sample Value   : %9.2f%s",GreatestSampleValue,LE);
  fprintf(file,"  Samples Collected       : %9dkg%s",Samples,LE);
  fprintf(file,"  Descent Fuel Remaining  : %9.2fkg%s",DescentFuel,LE);
  fprintf(file,"  Ascent Fuel Remaining   : %9.2fkg%s",AscentFuel,LE);
  fprintf(file,"  RCS Fuel Remaining      : %9.2fkg%s",RcsFuel,LE);
  fclose(file);
  }
