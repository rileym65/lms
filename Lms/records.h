#ifndef _RECORDS_H
#define _RECORDS_H

#include <stdio.h>
#include <string.h>
#include "header.h"

class Records {
  protected:
    void load();
  public:
    Double AscentFuel;
    Double ClosestToTarget;
    Double DescentFuel;
    Double FarthestFromLM;
    Double GreatestSampleValue;
    Double HighestLatitude;
    Int32  LongestAverageEva;
    Int32  LongestEva;
    Int32  LongestMission;
    Double LongestSingleDrive;
    Double LongestSingleWalk;
    Double LongestTotalDrive;
    Double LongestTotalWalk;
    Int32  LongestTotalEva;
    Double LowestLatitude;
    Double RcsFuel;
    Int32  ShortestDocking;
    Int32  ShortestLanding;
    Records();
    ~Records();
    void Save();
  };

#endif

