#include <stdio.h>
#include <string.h>
#include "header.h"
#include "records.h"
#include "common.h"
#include "helpers.h"

void Score() {
  int i;
  Int32 cellX,cellY;
  Double sampleAvg;
  Double sampleChi;
  Double sampleDiv;
  SAMPLE sample;

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
//  if (fabs(landedLatitude) >= 1) {
//    ScoreLatitudeBonus = (200.0 * (fabs(landedLatitude) - 1.0));
//    }
//  else ScoreLatitudeBonus = 0;
  ScoreLatitudeBonus = 0;
  ScoreLanding = ScoreLandedTime + ScoreDescentFuel + ScoreLandedDistance +
                 ScoreLandedVVel + ScoreLandedHVel + ScoreLatitudeBonus;

  ScoreEvaCompleted = 0;
  for (i=0; i<evaCount; i++)
    if (evas[i].end-evas[i].start >= 14400) ScoreEvaCompleted += 250;
  ScoreEvaSamples = (lm->Rock() * 4.16666667);
  ScoreEvaTime = clockTe * 0.009259;
  ScoreEvaValue = lm->Value() * 3;
  if (mission->Rover() == 1) {
    ScoreEvaDriven = lrv->Driven() / 35.0;
    ScoreEvaFarthest = farthest / 17.5;
    }
  else if (mission->Rover() == 2) {
    ScoreEvaDriven = lrv->Driven() / 200.0;
    ScoreEvaFarthest = farthest / 100.0;
    }
  else if (mission->Rover() == 3) {
    ScoreEvaDriven = lrv->Driven() / 2000.0;
    ScoreEvaFarthest = farthest / 1000.0;
    }
  else {
    ScoreEvaDriven = 0;
    ScoreEvaFarthest = farthest / 5.0;
    }
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
  for (i=0; i<lm->Rock(); i++) {
    sample = lm->Sample(i);
    cellX = map->Cell(mission->PrimaryLongitude());
    cellY = map->Cell(mission->PrimaryLatitude());
    if (abs(sample.cellX - cellX) <= 20 &&
        abs(sample.cellY - cellY) <= 20) primarySamples++;
    else {
      cellX = map->Cell(mission->Secondary1Longitude());
      cellY = map->Cell(mission->Secondary1Latitude());
      if (abs(sample.cellX - cellX) <= 20 &&
          abs(sample.cellY - cellY) <= 20) secondary1Samples++;
      else {
        cellX = map->Cell(mission->Secondary2Longitude());
        cellY = map->Cell(mission->Secondary2Latitude());
        if (abs(sample.cellX - cellX) <= 20 &&
            abs(sample.cellY - cellY) <= 20) secondary2Samples++;
        else {
          cellX = map->Cell(mission->Secondary3Longitude());
          cellY = map->Cell(mission->Secondary3Latitude());
          if (abs(sample.cellX - cellX) <= 20 &&
              abs(sample.cellY - cellY) <= 20) secondary3Samples++;
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

  sampleAvg = sampleSmallRock + sampleMediumRock + sampleLargeRock +
              sampleSmallCrater + sampleMediumCrater + sampleLargeCrater +
              samplePlains + sampleRise + sampleDepression;
  sampleAvg /= 9.0;
  sampleChi = (sampleSmallRock - sampleAvg) * (sampleSmallRock - sampleAvg);
  sampleChi += (sampleMediumRock - sampleAvg) * (sampleMediumRock - sampleAvg);
  sampleChi += (sampleLargeRock - sampleAvg) * (sampleLargeRock - sampleAvg);
  sampleChi += (sampleSmallCrater - sampleAvg) * (sampleSmallCrater - sampleAvg);
  sampleChi += (sampleMediumCrater - sampleAvg) * (sampleMediumCrater - sampleAvg);
  sampleChi += (sampleLargeCrater - sampleAvg) * (sampleLargeCrater - sampleAvg);
  sampleChi += (samplePlains - sampleAvg) * (samplePlains - sampleAvg);
  sampleChi += (sampleRise - sampleAvg) * (sampleRise - sampleAvg);
  sampleChi += (sampleDepression - sampleAvg) * (sampleDepression - sampleAvg);
  sampleDiv = 1000.0 - sampleChi;
  if (sampleDiv < 0) sampleDiv = 0;
  ScoreSampleDiv = (Int32)sampleDiv;

  
  ScoreEvaTotal = ScoreEvaCompleted + ScoreEvaSamples + ScoreEvaTime +
                  ScoreEvaValue + ScoreEvaFarthest + ScoreEvaDriven;
  ScoreEvaTotal += ScoreEvaFlagSetup + ScoreEvaLrvSetup +
                   ScoreEvaLaserSetup + ScoreEvaAlsepSetup;
  ScoreEvaTotal += ScoreEvaPrimarySamples + ScoreEvaSecondary1Samples +
                   ScoreEvaSecondary2Samples + ScoreEvaSecondary3Samples;
  ScoreEvaTotal += ScoreEvaVariety + ScoreSampleDiv;

  ScoreRendezvous = (10000 - rendezvousDistance) / 10.0;
  if (ScoreRendezvous < 0) ScoreRendezvous = 0;
  ScoreDockTime = 1000 - (clockDk - 5400);
  if (ScoreDockTime < 0) ScoreDockTime = 0;
  ScoreDockAscentFuel = lm->AscentFuel();
  ScoreDockRcsFuel = lm->RcsFuel();
  ScoreDockLVel = 1000 - (dockingLVel * 30339.0584);
  if (ScoreDockLVel < 0) ScoreDockLVel = 0;
  ScoreDockVel = 1000 - (fabs(fabs(dockingVel) - 0.3) * 10000.0);
  if (ScoreDockVel < 0) ScoreDockVel = 0;
  ScoreDockXAlign = 1000 - (fabs(dockingXAlign) * 2000.0);
  if (ScoreDockXAlign < 0) ScoreDockXAlign = 0;
  ScoreDockYAlign = 1000 - (fabs(dockingYAlign) * 2000.0);
  if (ScoreDockYAlign < 0) ScoreDockYAlign = 0;

  ScoreDockTotal = ScoreDockTime + ScoreDockAscentFuel + ScoreDockRcsFuel +
                   ScoreDockLVel + ScoreDockVel + ScoreRendezvous +
                   ScoreDockXAlign + ScoreDockYAlign;

  ScoreTotal = ScoreLanding + ScoreEvaTotal + ScoreDockTotal;

  }

