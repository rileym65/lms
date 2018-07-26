#include <stdio.h>
#include <string.h>
#include "header.h"
#include "records.h"

void Score() {
  int i;
  Int32 cellX,cellY;
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
  ScoreEvaFlagSetup = (flagPlanted) ? 250 : 0;
  ScoreEvaLrvSetup = (lrv->IsSetup()) ? 250 : 0;
  ScoreEvaLaserSetup = (laserSetup) ? 250 : 0;
  ScoreEvaAlsepSetup = (alsepSetup) ? 250 : 0;
  if (ScoreEvaAlsepSetup == 250 && mission->Lsep() == 1)
    ScoreEvaAlsepSetup = 125;
  primarySamples = 0;
  secondary1Samples = 0;
  secondary2Samples = 0;
  secondary3Samples = 0;
  for (i=0; i<numSamples; i++) {
    cellX = map->Cell(mission->PrimaryLongitude());
    cellY = map->Cell(mission->PrimaryLatitude());
    if (abs(samples[i].cellX - cellX) <= 20 &&
        abs(samples[i].cellY - cellY) <= 20) primarySamples++;
    else {
      cellX = map->Cell(mission->Secondary1Longitude());
      cellY = map->Cell(mission->Secondary1Latitude());
      if (abs(samples[i].cellX - cellX) <= 20 &&
          abs(samples[i].cellY - cellY) <= 20) secondary1Samples++;
      else {
        cellX = map->Cell(mission->Secondary2Longitude());
        cellY = map->Cell(mission->Secondary2Latitude());
        if (abs(samples[i].cellX - cellX) <= 20 &&
            abs(samples[i].cellY - cellY) <= 20) secondary2Samples++;
        else {
          cellX = map->Cell(mission->Secondary3Longitude());
          cellY = map->Cell(mission->Secondary3Latitude());
          if (abs(samples[i].cellX - cellX) <= 20 &&
              abs(samples[i].cellY - cellY) <= 20) secondary3Samples++;
          }
        }
      }
    }
  ScoreEvaPrimarySamples = 1000.0 * ((Double)primarySamples / 30.0);
  ScoreEvaSecondary1Samples = 1000.0 * ((Double)secondary1Samples / 30.0);
  ScoreEvaSecondary2Samples = 1000.0 * ((Double)secondary2Samples / 30.0);
  ScoreEvaSecondary3Samples = 1000.0 * ((Double)secondary3Samples / 30.0);
  ScoreEvaVariety = 0;
  if (sampleSmallRock) ScoreEvaVariety += 100;
  if (sampleMediumRock) ScoreEvaVariety += 100;
  if (sampleLargeRock) ScoreEvaVariety += 100;
  if (sampleSmallCrater) ScoreEvaVariety += 100;
  if (sampleMediumCrater) ScoreEvaVariety += 100;
  if (sampleLargeCrater) ScoreEvaVariety += 100;
  if (samplePlains) ScoreEvaVariety += 100;
  if (sampleRise) ScoreEvaVariety += 100;
  if (sampleSpecial) ScoreEvaVariety += 100;
  if (sampleDepression) ScoreEvaVariety += 100;
  if (sampleCraterWall) ScoreEvaVariety += 100;

  
  ScoreEvaTotal = ScoreEvaCompleted + ScoreEvaSamples + ScoreEvaTime +
                  ScoreEvaValue + ScoreEvaFarthest + ScoreEvaDriven;
  ScoreEvaTotal += ScoreEvaFlagSetup + ScoreEvaLrvSetup +
                   ScoreEvaLaserSetup + ScoreEvaAlsepSetup;
  ScoreEvaTotal += ScoreEvaPrimarySamples + ScoreEvaSecondary1Samples +
                   ScoreEvaSecondary2Samples + ScoreEvaSecondary3Samples;
  ScoreEvaTotal += ScoreEvaVariety;

  ScoreDockTime = 1000 - (clockDk - 5400);
  if (ScoreDockTime < 0) ScoreDockTime = 0;
  ScoreDockAscentFuel = lm->AscentFuel();
  ScoreDockRcsFuel = lm->RcsFuel();
  ScoreDockLVel = 1000 - (dockingLVel * 30339.0584);
  if (ScoreDockLVel < 0) ScoreDockLVel = 0;
  ScoreDockVel = 1000 - (fabs(fabs(dockingVel) - 0.3) * 10000.0);
  if (ScoreDockVel < 0) ScoreDockVel = 0;

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
  printf("  LRV Setup:            %d%s",ScoreEvaLrvSetup,LE);
  printf("  Laser Refl. Setup:    %d%s",ScoreEvaLaserSetup,LE);
  printf("  Flag Planted:         %d%s",ScoreEvaFlagSetup,LE);
  printf("  ALSEP Setup:          %d%s",ScoreEvaAlsepSetup,LE);
  printf("  Samples Collected:    %d%s",ScoreEvaSamples,LE);
  printf("  Sample Variety:       %d%s",ScoreEvaVariety,LE);
  printf("  Primary Samples:      %d%s",ScoreEvaPrimarySamples,LE);
  printf("  Sec. Site 1 Samples:  %d%s",ScoreEvaSecondary1Samples,LE);
  printf("  Sec. Site 2 Samples:  %d%s",ScoreEvaSecondary2Samples,LE);
  printf("  Sec. Site 3 Samples:  %d%s",ScoreEvaSecondary3Samples,LE);
  printf("  Sample Value:         %d%s",ScoreEvaValue,LE);
  printf("  Distance from LM:     %d%s",ScoreEvaFarthest,LE);
  printf("  Distance Driven:      %d%s",ScoreEvaDriven,LE);
  printf("                                --------%s",LE);
  printf("    Surface Operations Total:   %d%s",ScoreEvaTotal,LE);
  printf("%s",LE);
  printf("Rendevous/Docking Score:%s",LE);
  printf("  Docking Time:         %d%s",ScoreDockTime,LE);
  printf("  Docking Velocity:     %d%s",ScoreDockVel,LE);
  printf("  Lateral Velocity:     %d%s",ScoreDockLVel,LE);
  printf("  Asc Fuel Remaining:   %d%s",ScoreDockAscentFuel,LE);
  printf("  RCS Fuel Remaining:   %d%s",ScoreDockRcsFuel,LE);
  printf("                                --------%s",LE);
  printf("    Rendevous/Docking Total:    %d%s",ScoreDockTotal,LE);
  printf("%s",LE);
  printf("                                --------%s",LE);
  printf("    Total Score:                %d%s",ScoreTotal,LE);
  }

