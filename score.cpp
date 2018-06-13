#include <stdio.h>
#include <string.h>
#include "header.h"
#include "records.h"

void Score() {
  int i;
  ScoreLandedTime = 1000 - (landedMet - 10800);
  if (ScoreLandedTime < 0) ScoreLandedTime = 0;
  ScoreDescentFuel = lm->DescentFuel();
  ScoreLandedDistance = 1000 - (distance(landedLongitude,landedLatitude,
    mission->TargetLongitude(), mission->TargetLatitude()) / 10);
  if (ScoreLandedDistance < 0) ScoreLandedDistance = 0;
  ScoreLandedVVel = 1000 - (landedVVel * 327.8689);
  if (ScoreLandedVVel < 0) ScoreLandedVVel = 0;
  ScoreLandedHVel = 1000 - (landedHVel * 819.6721);
  if (ScoreLandedHVel < 0) ScoreLandedHVel = 0;
  if (fabs(landedLatitude) >= 1) {
    ScoreLatitudeBonus = (200.0 * (fabs(landedLatitude) - 1.0));
    }
  else ScoreLatitudeBonus = 0;
  ScoreLanding = ScoreLandedTime + ScoreDescentFuel + ScoreLandedDistance +
                 ScoreLandedVVel + ScoreLandedHVel + ScoreLatitudeBonus;

  ScoreEvaCompleted = 0;
  for (i=0; i<evaCount; i++)
    if (evas[i].end-evas[i].start >= 14400) ScoreEvaCompleted += 250;
  ScoreEvaSamples = (lm->Rock() * 4.16666667);
  ScoreEvaTime = clockTe * 0.009259;
  ScoreEvaValue = lm->Value() * 3;
  ScoreEvaFarthest = farthest / 100;
  ScoreEvaDriven = lrv->Driven() / 200.0;
  
  ScoreEvaTotal = ScoreEvaCompleted + ScoreEvaSamples + ScoreEvaTime +
                  ScoreEvaValue + ScoreEvaFarthest + ScoreEvaDriven;

  ScoreDockTime = 1000 - (clockDk - 5400);
  if (ScoreDockTime < 0) ScoreDockTime = 0;
  ScoreDockAscentFuel = lm->AscentFuel();
  ScoreDockRcsFuel = lm->RcsFuel();

  ScoreDockTotal = ScoreDockTime + ScoreDockAscentFuel + ScoreDockRcsFuel;

  ScoreTotal = ScoreLanding + ScoreEvaTotal + ScoreDockTotal;

  printf("Landing Score:%s",LE);
  printf("  Landing Time:         %d%s",ScoreLandedTime, LE);
  printf("  Fuel Remaining:       %d%s",ScoreDescentFuel, LE);
  printf("  Distance from target: %d%s",ScoreLandedDistance, LE);
  printf("  Vertical Velocity:    %d%s",ScoreLandedVVel, LE);
  printf("  Horizontal Velocity:  %d%s",ScoreLandedHVel, LE);
  if (ScoreLatitudeBonus > 0)
    printf("  Latitude Bonus:       %d%s",ScoreLatitudeBonus, LE);
  printf("                                --------%s",LE);
  printf("    Landing Total:              %d%s",ScoreLanding,LE);
  printf("%s",LE);
  printf("Surface Operations Score:%s",LE);
  printf("  EVAs completed:       %d%s",ScoreEvaCompleted,LE);
  printf("  Time Spent on EVA:    %d%s",ScoreEvaTime,LE);
  printf("  Samples Collected:    %d%s",ScoreEvaSamples,LE);
  printf("  Sample Value:         %d%s",ScoreEvaValue,LE);
  printf("  Distance from LM:     %d%s",ScoreEvaFarthest,LE);
  printf("  Distance Driven:      %d%s",ScoreEvaDriven,LE);
  printf("                                --------%s",LE);
  printf("    Surface Operations Total:   %d%s",ScoreEvaTotal,LE);
  printf("%s",LE);
  printf("Rendevous/Docking Score:%s",LE);
  printf("  Docking Time:         %d%s",ScoreDockTime,LE);
  printf("  Asc Fuel Remaining:   %d%s",ScoreDockAscentFuel,LE);
  printf("  RCS Fuel Remaining:   %d%s",ScoreDockRcsFuel,LE);
  printf("                                --------%s",LE);
  printf("    Rendevous/Docking Total:    %d%s",ScoreDockTotal,LE);
  printf("%s",LE);
  printf("                                --------%s",LE);
  printf("    Total Score:                %d%s",ScoreTotal,LE);
  }

