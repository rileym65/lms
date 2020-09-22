#ifndef _RECORDS_H
#define _RECORDS_H

#include <stdio.h>
#include <string.h>
#include "types.h"
#include "common.h"

class Records {
  protected:
    void load();
  public:
    Double AscentFuel;
    Double ClosestToTarget;
    Double DescentFuel;
    Double DistanceTravelled;
    Double FarthestFromEarth;
    Double FarthestFromLM;
    Double GreatestSampleValue;
    Double GreatestSampleDiversity;
    Double HighestLatitude;
    Double HighestVelocity;
    Int32  LongestAverageEva;
    Int32  LongestEva;
    Int32  LongestMission;
    Int32  LongestLunarMission;
    Double LongestSingleDrive;
    Double LongestSingleWalk;
    Double LongestTotalDrive;
    Double LongestTotalWalk;
    Int32  LongestTotalEva;
    Double LowestLatitude;
    Double RcsFuel;
    Int32  ShortestDocking;
    Int32  ShortestLanding;
    Int32  Samples;
    Double ClosestRendezvous;
    Int32  LongestSurface;
    Double LowestAscentFuel;
    Double LowestDescentFuel;
    Double LowestRcsFuel;
    Records();
    ~Records();
    void Save();
  };

#endif

