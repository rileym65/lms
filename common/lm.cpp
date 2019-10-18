#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "vehicle.h"
#include "spacecraft.h"
#include "lm.h"
#include "terminal.h"
#include "computer.h"
#include "g_clockmi.h"
#include "common.h"
#include "helpers.h"

static Int32 samplePos;

LunarModule::LunarModule() {
  samplePos = 0;
  landed = 0;
  throttle = 0;
  pitchRate = 0;
  rollRate = 0;
  yawRate = 0;
  descentJettisoned = 0;
  rock = 0;
  ascentBatteryLeakage = 0;
  ascentOxygenLeakage = 0;
  ascentFuelLeakage = 0;
  ascentEngineEfficiency = 1.0;
  rcsFuelLeakage = 0;
  descentBatteryLeakage = 0;
  descentOxygenLeakage = 0;
  descentFuelLeakage = 0;
  descentEngineEfficiency = 1.0;
  damageReportStep = 0;
  ascentDryWeight = 2234.0;
  descentDryWeight = 2346.0;
  ascentIsp = 344.0;
  descentIsp = 334.0;
  rcsIsp = 401.0;
  ascentNewtons = 16890.0;
  descentNewtons = 49215.0;
  rcsNewtons = 1970.0;
  ascentFuelRate = ascentNewtons / (9.81 * ascentIsp);
  descentFuelRate = descentNewtons / (9.81 * descentIsp);
  rcsFuelRate = rcsNewtons / (9.81 * rcsIsp);
  type |= VT_LANDER;
  InitPanel();
  }

LunarModule::~LunarModule() {
  }

/* **************************** */
/* ***** Accessor methods ***** */
/* **************************** */

Double LunarModule::AscentFuel() {
  return ascentFuel;
  }

Double LunarModule::AscentFuel(Double d) {
  ascentFuel = d;
  return ascentFuel;
  }

Double LunarModule::AscentOxygen() {
  return ascentOxygen;
  }

Double LunarModule::AscentOxygen(Double d) {
  ascentOxygen = d;
  return ascentOxygen;
  }

Double LunarModule::AscentBattery() {
  return ascentBattery;
  }

Double LunarModule::AscentBattery(Double d) {
  ascentBattery = d;
  return ascentBattery;
  }

Double LunarModule::AscentDryWeight(Double d) {
  ascentDryWeight = d;
  return ascentDryWeight;
  }

Double LunarModule::AscentIsp(Double d) {
  ascentIsp = d;
  ascentFuelRate = ascentNewtons / (9.81 * ascentIsp);
  return ascentIsp;
  }

Double LunarModule::AscentNewtons(Double d) {
  ascentNewtons = d;
  ascentFuelRate = ascentNewtons / (9.81 * ascentIsp);
  return ascentNewtons;
  }

Double LunarModule::DescentOxygen() {
  return descentOxygen;
  }

Double LunarModule::DescentOxygen(Double d) {
  descentOxygen = d;
  return descentOxygen;
  }

Double LunarModule::DescentBattery() {
  return descentBattery;
  }

Double LunarModule::DescentBattery(Double d) {
  descentBattery = d;
  return descentBattery;
  }

Double LunarModule::AscentEOxygen() {
  return ascentEOxygen;
  }

Double LunarModule::AscentEOxygen(Double d) {
  ascentEOxygen = d;
  return ascentEOxygen;
  }

Double LunarModule::AscentEBattery() {
  return ascentEBattery;
  }

Double LunarModule::AscentEBattery(Double d) {
  ascentEBattery = d;
  return ascentEBattery;
  }

Double LunarModule::DescentEOxygen() {
  return descentEOxygen;
  }

Double LunarModule::DescentEOxygen(Double d) {
  descentEOxygen = d;
  return descentEOxygen;
  }

Double LunarModule::DescentEBattery() {
  return descentEBattery;
  }

Double LunarModule::DescentEBattery(Double d) {
  descentEBattery = d;
  return descentEBattery;
  }

Double LunarModule::DescentDryWeight(Double d) {
  descentDryWeight = d;
  return descentDryWeight;
  }

Double LunarModule::DescentIsp(Double d) {
  descentIsp = d;
  descentFuelRate = descentNewtons / (9.81 * descentIsp);
  return descentIsp;
  }

Double LunarModule::DescentNewtons(Double d) {
  descentNewtons = d;
  descentFuelRate = descentNewtons / (9.81 * descentIsp);
  return descentNewtons;
  }

Double LunarModule::Isp() {
  if (descentJettisoned) return ascentIsp;
  return descentIsp;
  }

Double LunarModule::RcsIsp() {
  return rcsIsp;
  }

Double LunarModule::RcsIsp(Double d) {
  rcsIsp = d;
  rcsFuelRate = rcsNewtons / (9.81 * rcsIsp);
  return rcsIsp;
  }

Double LunarModule::RcsNewtons(Double d) {
  rcsNewtons = d;
  rcsFuelRate = rcsNewtons / (9.81 * rcsIsp);
  return rcsNewtons;
  }

Double LunarModule::Battery() {
  Double ret;
  ret = ascentBattery;
  if (!descentJettisoned) ret += descentBattery;
  return ret;
  }

Double LunarModule::EBattery() {
  Double ret;
  ret = ascentEBattery;
  if (!descentJettisoned) ret += descentEBattery;
  return ret;
  }

Double LunarModule::DescentFuel() {
  return descentFuel;
  }

Double LunarModule::DescentFuel(Double d) {
  descentFuel = d;
  return descentFuel;
  }

Int8 LunarModule::DescentJettisoned() {
  return descentJettisoned;
  }

Double LunarModule::Fuel() {
  if (descentJettisoned) return AscentFuel();
  return DescentFuel();
  }

Int8 LunarModule::Landed() {
  return landed;
  }

Double LunarModule::MaxAscentFuel() {
  return maxAscentFuel;
  }

Double LunarModule::MaxAscentFuel(Double d) {
  maxAscentFuel = d;
  return maxAscentFuel;
  }

Double LunarModule::MaxAscentBattery() {
  return maxAscentBattery;
  }

Double LunarModule::MaxAscentBattery(Double d) {
  maxAscentBattery = d;
  return maxAscentBattery;
  }

Double LunarModule::MaxAscentEBattery() {
  return maxAscentEBattery;
  }

Double LunarModule::MaxAscentEBattery(Double d) {
  maxAscentEBattery = d;
  return maxAscentEBattery;
  }

Double LunarModule::MaxAscentOxygen() {
  return maxAscentOxygen;
  }

Double LunarModule::MaxAscentOxygen(Double d) {
  maxAscentOxygen = d;
  return maxAscentOxygen;
  }

Double LunarModule::MaxAscentEOxygen() {
  return maxAscentEOxygen;
  }

Double LunarModule::MaxAscentEOxygen(Double d) {
  maxAscentEOxygen = d;
  return maxAscentEOxygen;
  }

Double LunarModule::MaxDescentFuel() {
  return maxDescentFuel;
  }

Double LunarModule::MaxDescentFuel(Double d) {
  maxDescentFuel = d;
  return maxDescentFuel;
  }

Double LunarModule::MaxRcsFuel() {
  return maxRcsFuel;
  }

Double LunarModule::MaxRcsFuel(Double d) {
  maxRcsFuel = d;
  return maxRcsFuel;
  }

Double LunarModule::MaxDescentBattery() {
  return maxDescentBattery;
  }

Double LunarModule::MaxDescentBattery(Double d) {
  maxDescentBattery = d;
  return maxDescentBattery;
  }

Double LunarModule::MaxDescentEBattery() {
  return maxDescentEBattery;
  }

Double LunarModule::MaxDescentEBattery(Double d) {
  maxDescentEBattery = d;
  return maxDescentEBattery;
  }

Double LunarModule::MaxDescentOxygen() {
  return maxDescentOxygen;
  }

Double LunarModule::MaxDescentOxygen(Double d) {
  maxDescentOxygen = d;
  return maxDescentOxygen;
  }

Double LunarModule::MaxDescentEOxygen() {
  return maxDescentEOxygen;
  }

Double LunarModule::MaxDescentEOxygen(Double d) {
  maxDescentEOxygen = d;
  return maxDescentEOxygen;
  }

Double LunarModule::Oxygen() {
  Double ret;
  ret = ascentOxygen;
  if (!descentJettisoned) ret += descentOxygen;
  return ret;
  }

Double LunarModule::EOxygen() {
  Double ret;
  ret = ascentEOxygen;
  if (!descentJettisoned) ret += descentEOxygen;
  return ret;
  }

Double LunarModule::RcsFuel() {
  return rcsFuel;
  }

Double LunarModule::RcsFuel(Double d) {
  rcsFuel = d;
  return rcsFuel;
  }

Int16 LunarModule::Rock() {
  return rock;
  }

Double LunarModule::Value() {
  return value;
  }

Double LunarModule::Value(Double d) {
  value = d;
  return value;
  }


/* ************************* */
/* ***** Other methods ***** */
/* ************************* */

void LunarModule::AddSample(SAMPLE s) {
  if (rock >= 512) return;
  samples[rock++] = s;
  switch (s.type) {
    case S_SMALL_CRATER:sampleSmallCrater++; break;
    case S_MEDIUM_CRATER:sampleMediumCrater++; break;
    case S_LARGE_CRATER:sampleLargeCrater++; break;
    case S_SMALL_ROCK:sampleSmallRock++; break;
    case S_MEDIUM_ROCK:sampleMediumRock++; break;
    case S_LARGE_ROCK:sampleLargeRock++; break;
    case S_RISE:sampleRise++; break;
    case S_CRATERWALL:sampleCraterWall++; break;
    case S_DEPRESSION:sampleDepression++; break;
    case S_PLAINS:samplePlains++; break;
    case S_SPECIAL:sampleSpecial++; break;
    }
  }

Boolean LunarModule::DuplicateSample(SAMPLE s) {
  Int16 i;
  for (i=0; i<rock; i++)
    if (s.cellX == samples[i].cellX && s.cellY == samples[i].cellY) return true;
  return false;
  }

void LunarModule::Abort() {
  descentJettisoned = -1;
  mode_arm = 0;
  throttle = 100;
  clockBu = 0;
  liftoffMet = clockMi;
  numBurns++;
  if (landed) velocity = Orbiting()->Velocity();
  burn[numBurns-1].start = clockMi;
  if (descentJettisoned) {
    burn[numBurns-1].fuelUsed = ascentFuel;
    burn[numBurns-1].engine = 'A';
    }
  else {
    burn[numBurns-1].fuelUsed = descentFuel;
    burn[numBurns-1].engine = 'D';
    }
  landed = 0;
  }

Boolean LunarModule::UseBattery(Double units) {
  if (!descentJettisoned) {
    if (descentBattery >= units) {
      descentBattery -= units;
      units = 0;
      }
    else {
      units -= descentBattery;
      descentBattery = 0;
      }
    if (units <= 0.0) return true;
    if (descentEBattery >= units) {
      descentEBattery -= units;
      units = 0;
      }
    else {
      units -= descentEBattery;
      descentEBattery = 0;
      }
    if (units <= 0.0) return true;
    }
  if (ascentBattery >= units) {
    ascentBattery -= units;
    units = 0;
    }
  else {
    units -= ascentBattery;
    ascentBattery = 0;
    }
  if (units <= 0.0) return true;
  if (ascentEBattery >= units) {
    ascentEBattery -= units;
    units = 0;
    }
  else {
    units -= ascentEBattery;
    ascentEBattery = 0;
    }
  if (units <= 0.0) return true;
  return false;
  }

Boolean LunarModule::UseOxygen(Double units) {
  if (metabolicRate < 60) units += (.2 * ((metabolicRate - 30) / 30.0));
  if (metabolicRate >= 60) {
    units += .2;
    units += ((metabolicRate - 60) / 10.0);
    }
  if (!descentJettisoned) {
    if (descentOxygen >= units) {
      descentOxygen -= units;
      units = 0;
      }
    else {
      units -= descentOxygen;
      descentOxygen = 0;
      }
    if (units <= 0.0) return true;
    if (descentEOxygen >= units) {
      descentEOxygen -= units;
      units = 0;
      }
    else {
      units -= descentEOxygen;
      descentEOxygen = 0;
      }
    if (units <= 0.0) return true;
    }
  if (ascentOxygen >= units) {
    ascentOxygen -= units;
    units = 0;
    }
  else {
    units -= ascentOxygen;
    ascentOxygen = 0;
    }
  if (units <= 0.0) return true;
  if (ascentEOxygen >= units) {
    ascentEOxygen -= units;
    units = 0;
    }
  else {
    units -= ascentEOxygen;
    ascentEOxygen = 0;
    }
  if (units <= 0.0) return true;
  return false;

  }


void LunarModule::Cycle() {
  Double rcsfuel;
  Double rcsThrust;
  Double newtons;
  Double mainThrust;
  Double mainfuel;
  Double vVel;
  Double hVel;
  Double damage;
  Double fuel;
  Vector v;
  Matrix m;
  char   cell;
  ascentOxygen -= ascentOxygenLeakage;
  ascentBattery -= ascentBatteryLeakage;
  ascentFuel -= (ascentFuelLeakage / 10.0);
  descentOxygen -= descentOxygenLeakage;
  descentBattery -= descentBatteryLeakage;
  descentFuel -= (descentFuelLeakage / 10.0);
  rcsFuel -= (rcsFuelLeakage / 100.0);
  if (ascentOxygen < 0.0) ascentOxygen = 0.0;
  if (ascentBattery < 0.0) ascentBattery = 0.0;
  if (ascentFuel < 0.0) ascentFuel = 0.0;
  if (descentOxygen < 0.0) descentOxygen = 0.0;
  if (descentBattery < 0.0) descentBattery = 0.0;
  if (descentFuel < 0.0) descentFuel = 0.0;
  if (rcsFuel < 0.0) rcsFuel = 0.0;
  if (damageReportStep != 0) {
    if (damageReportStep == 1) {
      if (seq->Time() <= 0) {
        seq->Message("ASC BAT LK:",ascentBatteryLeakage*100,5);
        damageReportStep = 2;
        }
      }
    if (damageReportStep == 2) {
      if (seq->Time() <=  1) {
        seq->Message("ASC OXY LK:",ascentOxygenLeakage*100,5);
        damageReportStep = 3;
        }
      }
    if (damageReportStep == 3) {
      if (seq->Time() <=  1) {
        seq->Message("ASC FUL LK:",ascentFuelLeakage*100,5);
        damageReportStep = 4;
        }
      }
    if (damageReportStep == 4) {
      if (seq->Time() <=  1) {
        seq->Message("ASC ENGINE:",(1.0 - ascentEngineEfficiency)*100,5);
        damageReportStep = 5;
        }
      }
    if (damageReportStep == 5) {
      if (seq->Time() <=  1) {
        seq->Message("RCS FUL LK:",rcsFuelLeakage*100,5);
        if (descentJettisoned) damageReportStep = 0;
          else damageReportStep = 11;
        }
      }
    if (damageReportStep == 11) {
      if (seq->Time() <= 1) {
        seq->Message("DSC BAT LK:",descentBatteryLeakage*100,5);
        damageReportStep = 12;
        }
      }
    if (damageReportStep == 12) {
      if (seq->Time() <=  1) {
        seq->Message("DSC OXY LK:",descentOxygenLeakage*100,5);
        damageReportStep = 13;
        }
      }
    if (damageReportStep == 13) {
      if (seq->Time() <=  1) {
        seq->Message("DSC FUL LK:",descentFuelLeakage*100,5);
        damageReportStep = 14;
        }
      }
    if (damageReportStep == 14) {
      if (seq->Time() <=  1) {
        seq->Message("DSC ENGINE:",(1.0 - descentEngineEfficiency)*100,5);
        damageReportStep = 0;
        }
      }
    }
  if (landed && throttle == 0) return;
  if (rollRate >= -0.0001 && rollRate < 0.0001) rollRate = 0;
  if (pitchRate >= -0.0001 && pitchRate < 0.0001) pitchRate = 0;
  if (yawRate >= -0.0001 && yawRate < 0.0001) yawRate = 0;

  switch (rcsThrottle) {
    case 1: rcsThrust = rcsNewtons/100.0; rcsfuel = rcsFuelRate/100.0; break;
    case 10: rcsThrust = rcsNewtons/10.0; rcsfuel = rcsFuelRate/10.0; break;
    case 100: rcsThrust = rcsNewtons; rcsfuel = rcsFuelRate; break;
    default : rcsThrust = 0;
    }
  rcsfuel = rcsThrust / (9.80665 * rcsIsp) / GRAN;
  rcsThrust = rcsThrust / Mass();
  thrust = Vector(0,0,0);
  if (rcsUdMode == 'D' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceUp.Neg().Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsUdMode == 'U' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceUp.Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsLrMode == 'R' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceLeft.Neg().Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsLrMode == 'L' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceLeft.Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsFbMode == 'F' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceFront.Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsFbMode == 'B' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceFront.Neg().Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  fuelUsed = 0;
  if (throttle != 0) {
    if (descentJettisoned) {
      throttle = 100;
      mainThrust = ascentEngineEfficiency * ascentNewtons;
      fuel = mainThrust / (9.80665 * ascentIsp) / GRAN;
      mainThrust = mainThrust / Mass();
      if (ascentFuel >= fuel) {
        thrust = thrust + faceUp.Scale(mainThrust);
        ascentFuel -= fuel;
        fuelUsed += fuel;
        }
      }
    else {
      newtons = (double)throttle / 100.0;
      mainfuel = descentFuelRate * newtons;
      newtons *= descentEngineEfficiency * descentNewtons;
      mainfuel = newtons / (9.80665 * descentIsp) / GRAN;
      mainThrust = newtons / Mass();
      if (mainfuel <= descentFuel) {
        thrust = thrust + faceUp.Scale(mainThrust);
        descentFuel -= mainfuel;
        fuelUsed += mainfuel;
        }
      }
    }
  fuelUsed *= GRAN;
  Spacecraft::Cycle();
  if (Radius() <= Orbiting()->Radius()) {
    vVel = fabs(velocityAltitude);
    hVel = sqrt(lm->VelocityEast() * lm->VelocityEast() +
                lm->LatitudeVelocity() * lm->LatitudeVelocity());
    landedVVel = vVel;
    landedHVel = hVel;
    if (vVel >= 5.05 || hVel > 2.22) {
      run = false;
      endReason = END_CRASHED;
      }
    damage = 0;
    if (vVel >= 3.05 || hVel > 1.22) {
      damage = ((vVel - 3.05) / 2.0) + (hVel - 1.22);
      }
    cell = map->Lurrain(lm->Longitude(), lm->Latitude());
    switch (cell) {
      case '.': damage += 0.05; break;
      case 'o': damage += 0.10; break;
      case 'O': damage += 0.25; break;
      case ',': damage += 0.05; break;
      case '+': damage += 0.20; break;
      case '*': damage += 0.50; break;
      case '^': damage += 0.75; break;
      case '(': damage += 0.75; break;
      case ')': damage += 0.75; break;
      case 'u': damage += 0.75; break;
      case ' ': break;
      case '=': damage += 1.0; break;
      case '%': damage += 0.75; break;
      case 'f': break;
      case '&': damage += 0.50; break;
      case '/': damage += 0.75; break;
      case '"': damage += 0.25; break;
      case '_': break;
      default : damage += 1.0; break;
      }
    if (damage > 0) {
      if (damage > 1.0) damage = 1.0;
      lm->Damage(damage * 100.0);
      lrv->Damage(damage * 100.0);
      plss->Damage(damage * 100.0);
      hardInjury += ((Double)rng.Next(damage * 100.0));
      }
    RollRate(0);
    PitchRate(0);
    YawRate(0);
    velocity = Vector(0,0,0);
    velocityAltitude = 0;
    landed = -1;
    throttle = 0;
    position = (position - Orbiting()->Position()).Norm().Scale(Orbiting()->Radius()) +
               Orbiting()->Position();
    rcsFbMode = ' ';
    rcsLrMode = ' ';
    rcsUdMode = ' ';
    Altitude(0);
    Radius(Orbiting()->Radius());
    landedMet = clockMi;
    landedLongitude = Longitude();
    landedLatitude = Latitude();
    clockPDI = ignitionTime;
    burn[numBurns-1].end = clockMi;
    burn[numBurns-1].fuelUsed -= descentFuel;
    accelNorth = 0;
    accelEast = 0;
    accelAltitude = 0;
    velocityAltitude = 0;
    velocityNorth = 0;
    velocityEast = 0;
    ins->LatitudeVel(0.0);
    ins->LatitudeAcc(0.0);
    ins->LastLatitudeVel(0.0);
    }
  }

void LunarModule::Damage(Double dmg) {
  if (rng.Next(100) < dmg) ascentBatteryLeakage = ((Double)rng.Next(dmg) / 100.0);
  if (rng.Next(100) < dmg) ascentOxygenLeakage = ((Double)rng.Next(dmg) / 100.0);
  if (rng.Next(100) < dmg) ascentFuelLeakage = ((Double)rng.Next(dmg) / 100.0);
  if (rng.Next(100) < dmg) ascentEngineEfficiency -= ((Double)rng.Next(dmg) / 100.0);
  if (rng.Next(100) < dmg) descentBatteryLeakage = ((Double)rng.Next(dmg) / 100.0);
  if (rng.Next(100) < dmg) descentOxygenLeakage = ((Double)rng.Next(dmg) / 100.0);
  if (rng.Next(100) < dmg) descentFuelLeakage = ((Double)rng.Next(dmg) / 100.0);
  if (rng.Next(100) < dmg) descentEngineEfficiency -= ((Double)rng.Next(dmg) / 100.0);
  if (rng.Next(100) < dmg) rcsFuelLeakage = ((Double)rng.Next(dmg) / 100.0);
  }

void LunarModule::InitPanel() {
  panel = new Panel("lm.pnl",this);
  }

Double LunarModule::Mass() {
  Double ret;
  ret = ascentDryWeight;
  ret += ascentFuel;
  ret += rcsFuel;
  if (!descentJettisoned) {
    ret += descentDryWeight;
    ret += descentFuel;
    }
  ret += rock;
  return ret;
  }

Double LunarModule::rcsRotationFuelUsage() {
  switch (rcsRotThrottle) {
    case 10: return 0.01;
    case 50: return 0.05;
    case 100: return 0.10;
    }
  return 0.01;
  }

void LunarModule::ProcessKey(Int32 key) {
  Double rf;
  if (key == 'M') {
    if (docked) seq->MoveCsm();
    if (landed && spaceSuitOn && plssOn && !cabinPressurized)
      seq->MoveEva();
    }
  if (key == 'E') {
    if (landed && spaceSuitOn && plssOn && !cabinPressurized)
      seq->MoveEva();
    }
  if (key == 'U' && docked) seq->Undock();
  if (key == 'S') {
    if (!spaceSuitOn) seq->SpaceSuitOn();
    else if (cabinPressurized && ! plssOn) seq->SpaceSuitOff();
    }
  if (key == 'P') {
    if (!plssOn && spaceSuitOn && plssPacks > 0) seq->PlssOn();
    else if (plssOn && cabinPressurized) seq->PlssOff();
    }
  if (key == 'C') {
    if (!cabinPressurized) seq->CabinPressurize();
    else if (spaceSuitOn) seq->CabinEvacuate();
    }
  if (key == '?') {
    dsnOn = -1;
    dockingRadarOn = 0;
    landingRadarOn = 0;
    }
  if (key == '>') {
    dsnOn = 0;
    dockingRadarOn = -1;
    landingRadarOn = 0;
    }
  if (key == '<') {
    dsnOn = 0;
    dockingRadarOn = 0;
    landingRadarOn = -1;
    }
  if (key == 27 && !landed && mode_arm != 0 && !descentJettisoned) {
    seq->Abort();
    }
  if (landed) {
    if (key == '*') seq->Rest();
    if (key == ')') seq->Sleep();
    if (key == 'L' && mode_arm != 0) {
      seq->Liftoff();
      }
    }
  if (!docked) {
    if (key == 'f' && RcsFbMode() != 'F') RcsFbMode('F');
    else if (key == 'f' && RcsFbMode() == 'F') RcsFbMode(' ');
    if (key == 'b' && RcsFbMode() != 'B') RcsFbMode('B');
    else if (key == 'b' && RcsFbMode() == 'B') RcsFbMode(' ');
    if (key == 'l' && RcsLrMode() != 'L') RcsLrMode('L');
    else if (key == 'l' && RcsLrMode() == 'L') RcsLrMode(' ');
    if (key == 'r' && RcsLrMode() != 'R') RcsLrMode('R');
    else if (key == 'r' && RcsLrMode() == 'R') RcsLrMode(' ');
    if (key == 'u' && RcsUdMode() != 'U') RcsUdMode('U');
    else if (key == 'u' && RcsUdMode() == 'U') RcsUdMode(' ');
    if (key == 'd' && RcsUdMode() != 'D') RcsUdMode('D');
    else if (key == 'd' && RcsUdMode() == 'D') RcsUdMode(' ');
    if (key == ' ') {
      RcsFbMode(' ');
      RcsLrMode(' ');
      RcsUdMode(' ');
      }
    if (key == '=' && RcsThrottle() == 10) RcsThrottle(100);
    if (key == '=' && RcsThrottle() == 1) RcsThrottle(10);
    if (key == '-' && RcsThrottle() == 10) RcsThrottle(1);
    if (key == '-' && RcsThrottle() == 100) RcsThrottle(10);

    if (key == '+' && RcsRotThrottle() == 50) RcsRotThrottle(100);
    if (key == '+' && RcsRotThrottle() == 10) RcsRotThrottle(50);
    if (key == '_' && RcsRotThrottle() == 50) RcsRotThrottle(10);
    if (key == '_' && RcsRotThrottle() == 100) RcsRotThrottle(50);
    if (key == 'I' && Throttle() == 0 && !landed) {
      Throttle(10);
      clockBu = 0;
      ignitionAltitude = Altitude();
      ignitionApoapsis = Apoapsis();
      ignitionPeriapsis = Periapsis();
      ignitionTime = clockMi;
      numBurns++;
      burn[numBurns-1].start = clockMi;
      if (descentJettisoned) {
        burn[numBurns-1].fuelUsed = ascentFuel;
        burn[numBurns-1].engine = 'A';
        }
      else {
        burn[numBurns-1].fuelUsed = descentFuel;
        burn[numBurns-1].engine = 'D';
        }
      }
    if (key == 'i' && Throttle() > 0) { 
      Throttle(0);
      burn[numBurns-1].end = clockMi;
      if (descentJettisoned)
        burn[numBurns-1].fuelUsed -= ascentFuel;
      else
        burn[numBurns-1].fuelUsed -= descentFuel;
      if (!descentJettisoned) {
        if (ignitionAltitude > 50000 && ins->Periapsis()-Orbiting()->Radius() < 50000)
          clockDOI = ignitionTime;
        }
      if (descentJettisoned && rendezvousDistance == 0) {
        if (ignitionAltitude > 90000 &&
            ignitionPeriapsis-Orbiting()->Radius() < 50000 &&
            Periapsis()-Orbiting()->Radius() > 50000) {
          rendezvousDistance = (lm->Position() - csm->Position()).Length();
          }
        }
      }
    if (key == 'K') seq->Kill();
    if (key == 9) {
      if (mode_arm != 0) mode_arm = 0;
      else if (!descentJettisoned) mode_arm = 0xff;
      }
    if (key == KEY_KP_HOME) {
      rf = rcsRotationFuelUsage();
      if (rcsFuel >= rf) {
        RollRate(RollRate()+(rcsRotThrottle / 100.0));
        rcsFuel -= rf;
        }
      }
    if (key == KEY_HOME) {
      rf = rcsRotationFuelUsage();
      if (rcsFuel >= rf) {
        RollRate(RollRate()+(rcsRotThrottle / 100.0));
        rcsFuel -= rf;
        }
      }
    if (key == KEY_PGUP) {
      rf = rcsRotationFuelUsage();
      if (rcsFuel >= rf) {
        RollRate(RollRate()-(rcsRotThrottle / 100.0));
        rcsFuel -= rf;
        }
      }
    if (key == KEY_UP_ARROW) {
      rf = rcsRotationFuelUsage();
      if (rcsFuel >= rf) {
        PitchRate(PitchRate()+(rcsRotThrottle / 100.0));
        rcsFuel -= rf;
        }
      }
    if (key == KEY_DOWN_ARROW) {
      rf = rcsRotationFuelUsage();
      if (rcsFuel >= rf) {
        PitchRate(PitchRate()-(rcsRotThrottle / 100.0));
        rcsFuel -= rf;
        }
      }
    if (key == KEY_RIGHT_ARROW) {
      rf = rcsRotationFuelUsage();
      if (rcsFuel >= rf) {
        YawRate(YawRate()+(rcsRotThrottle / 100.0));
        rcsFuel -= rf;
        }
      }
    if (key == KEY_LEFT_ARROW) {
      rf = rcsRotationFuelUsage();
      if (rcsFuel >= rf) {
        YawRate(YawRate()-(rcsRotThrottle / 100.0));
        rcsFuel -= rf;
        }
      }
    if (Throttle() > 0 && !descentJettisoned) {
      if (key == KEY_PGDN) Throttle(Throttle()+2);
      if (key == KEY_END) Throttle(Throttle()-2);
      if (key == KEY_KP_END) Throttle(Throttle()-2);
      if (key == KEY_F1) Throttle(10);
      if (key == KEY_F2) Throttle(20);
      if (key == KEY_F3) Throttle(30);
      if (key == KEY_F4) Throttle(40);
      if (key == KEY_F5) Throttle(50);
      if (key == KEY_F6) Throttle(60);
      if (key == KEY_F7) Throttle(70);
      if (key == KEY_F8) Throttle(80);
      if (key == KEY_F9) Throttle(90);
      if (key == KEY_F10) Throttle(100);
      }
    }
  if (key == 'Z') damageReportStep = 1;
  panel->ProcessKey(key);
  if (comp != NULL) comp->ProcessKey(key);
  }

SAMPLE LunarModule::Sample(Int32 i) {
  SAMPLE ret;
  if (i < rock) return samples[i];
  ret.value = 0;
  ret.type = 0;
  return ret;
  }

void LunarModule::Save(FILE* file) {
  Int16 i;
  fprintf(file,"LunarModule {%s",LE);
  Spacecraft::Save(file);
  fprintf(file,"  RcsFbMode %d%s",rcsFbMode,LE);
  fprintf(file,"  RcsLrMode %d%s",rcsLrMode,LE);
  fprintf(file,"  RcsUdMode %d%s",rcsUdMode,LE);
  fprintf(file,"  AscentFuel %.18f%s",ascentFuel,LE);
  fprintf(file,"  DescentFuel %.18f%s",descentFuel,LE);
  fprintf(file,"  RcsFuel %.18f%s",rcsFuel,LE);
  fprintf(file,"  Landed %d%s",landed,LE);
  fprintf(file,"  DescentJettisoned %d%s",descentJettisoned,LE);
  fprintf(file,"  Rock %d%s",rock,LE);
  fprintf(file,"  Value %.18f%s",value,LE);
  fprintf(file,"  AscentOxygen %.18f%s",ascentOxygen,LE);
  fprintf(file,"  AscentBattery %.18f%s",ascentBattery,LE);
  fprintf(file,"  DescentOxygen %.18f%s",descentOxygen,LE);
  fprintf(file,"  DescentBattery %.18f%s",descentBattery,LE);
  fprintf(file,"  AscentEOxygen %.18f%s",ascentEOxygen,LE);
  fprintf(file,"  AscentEBattery %.18f%s",ascentEBattery,LE);
  fprintf(file,"  DescentEOxygen %.18f%s",descentEOxygen,LE);
  fprintf(file,"  DescentEBattery %.18f%s",descentEBattery,LE);
  fprintf(file,"  AscentBatteryLeakage %.18f%s",ascentBatteryLeakage,LE);
  fprintf(file,"  AscentOxygenLeakage %.18f%s",ascentOxygenLeakage,LE);
  fprintf(file,"  AscentFuelLeakage %.18f%s",ascentFuelLeakage,LE);
  fprintf(file,"  AscentEngineEfficiency %.18f%s",ascentEngineEfficiency,LE);
  fprintf(file,"  DescentBatteryLeakage %.18f%s",descentBatteryLeakage,LE);
  fprintf(file,"  DescentOxygenLeakage %.18f%s",descentOxygenLeakage,LE);
  fprintf(file,"  DescentfuelLeakage %.18f%s",descentFuelLeakage,LE);
  fprintf(file,"  DescentEngineEfficiency %.18f%s",descentEngineEfficiency,LE);
  fprintf(file,"  RcsFuelLeakage %.18f%s",rcsFuelLeakage,LE);
  fprintf(file,"  AscentDryWeight %.18f%s",ascentDryWeight,LE);
  fprintf(file,"  DescentDryWeight %.18f%s",descentDryWeight,LE);
  fprintf(file,"  AscentIsp %.18f%s",ascentIsp,LE);
  fprintf(file,"  DescentIsp %.18f%s",descentIsp,LE);
  fprintf(file,"  RcsIsp %.18f%s",rcsIsp,LE);
  fprintf(file,"  AscentNewtons %.18f%s",ascentNewtons,LE);
  fprintf(file,"  DescentNewtons %.18f%s",descentNewtons,LE);
  fprintf(file,"  RcsNewtons %.18f%s",rcsNewtons,LE);
  fprintf(file,"  MaxAscentFuel %.18f%s",maxAscentFuel,LE);
  fprintf(file,"  MaxAscentBattery %.18f%s",maxAscentBattery,LE);
  fprintf(file,"  MaxAscentEBattery %.18f%s",maxAscentEBattery,LE);
  fprintf(file,"  MaxAscentOxygen %.18f%s",maxAscentOxygen,LE);
  fprintf(file,"  MaxAscentEOxygen %.18f%s",maxAscentEOxygen,LE);
  fprintf(file,"  MaxDescentFuel %.18f%s",maxDescentFuel,LE);
  fprintf(file,"  MaxDescentBattery %.18f%s",maxDescentBattery,LE);
  fprintf(file,"  MaxDescentEBattery %.18f%s",maxDescentEBattery,LE);
  fprintf(file,"  MaxDescentOxygen %.18f%s",maxDescentOxygen,LE);
  fprintf(file,"  MaxDescentEOxygen %.18f%s",maxDescentEOxygen,LE);
  fprintf(file,"  MaxRcsFuel %.18f%s",maxRcsFuel,LE);
  for (i=0; i<rock; i++)
    fprintf(file,"  Sample %d,%d,%d,%f,%d%s",samples[i].cellX,samples[i].cellY,
            samples[i].clockGe,samples[i].value,samples[i].type,LE);
  fprintf(file,"  }%s",LE);
  }

Int8 LunarModule::SubLoad(FILE* file, char* pline) {
  SAMPLE sample;
  if (startsWith(pline,"ascentfuel ")) ascentFuel = atof(nw(pline));
  else if (startsWith(pline,"descentfuel ")) descentFuel = atof(nw(pline));
  else if (startsWith(pline,"rcsfuel ")) rcsFuel = atof(nw(pline));
  else if (startsWith(pline,"landed ")) landed = atoi(nw(pline));
  else if (startsWith(pline,"descentjettisoned ")) descentJettisoned = atoi(nw(pline));
  else if (startsWith(pline,"rock ")) rock = atoi(nw(pline));
  else if (startsWith(pline,"value ")) value = atof(nw(pline));
  else if (startsWith(pline,"ascentoxygen ")) ascentOxygen = atof(nw(pline));
  else if (startsWith(pline,"ascentbattery ")) ascentBattery = atof(nw(pline));
  else if (startsWith(pline,"descentoxygen ")) descentOxygen = atof(nw(pline));
  else if (startsWith(pline,"descentbattery ")) descentBattery = atof(nw(pline));
  else if (startsWith(pline,"ascenteoxygen ")) ascentEOxygen = atof(nw(pline));
  else if (startsWith(pline,"ascentebattery ")) ascentEBattery = atof(nw(pline));
  else if (startsWith(pline,"descenteoxygen ")) descentEOxygen = atof(nw(pline));
  else if (startsWith(pline,"descentebattery ")) descentEBattery = atof(nw(pline));
  else if (startsWith(pline,"ascentbatteryleakage ")) ascentBatteryLeakage = atof(nw(pline));
  else if (startsWith(pline,"ascentoxygenleakage ")) ascentOxygenLeakage = atof(nw(pline));
  else if (startsWith(pline,"ascentfuelleakage ")) ascentFuelLeakage = atof(nw(pline));
  else if (startsWith(pline,"ascentengineefficiency ")) ascentEngineEfficiency = atof(nw(pline));
  else if (startsWith(pline,"descentbatteryleakage ")) descentBatteryLeakage = atof(nw(pline));
  else if (startsWith(pline,"descentoxygenleakage ")) descentOxygenLeakage = atof(nw(pline));
  else if (startsWith(pline,"descentfuelleakage ")) descentFuelLeakage = atof(nw(pline));
  else if (startsWith(pline,"descentengineefficiency ")) descentEngineEfficiency = atof(nw(pline));
  else if (startsWith(pline,"rcsfuelleakage ")) rcsFuelLeakage = atof(nw(pline));
  else if (startsWith(pline,"ascentdryweight ")) ascentDryWeight = atof(nw(pline));
  else if (startsWith(pline,"descentdryweight ")) descentDryWeight = atof(nw(pline));
  else if (startsWith(pline,"ascentisp ")) ascentIsp = atof(nw(pline));
  else if (startsWith(pline,"descentisp ")) descentIsp = atof(nw(pline));
  else if (startsWith(pline,"rcsisp ")) rcsIsp = atof(nw(pline));
  else if (startsWith(pline,"ascentnewtons ")) AscentNewtons(atof(nw(pline)));
  else if (startsWith(pline,"descentnewtons ")) DescentNewtons(atof(nw(pline)));
  else if (startsWith(pline,"rcsnewtons ")) RcsNewtons(atof(nw(pline)));
  else if (startsWith(pline,"maxascentfuel ")) maxAscentFuel = atof(nw(pline));
  else if (startsWith(pline,"maxascentbattery ")) maxAscentBattery = atof(nw(pline));
  else if (startsWith(pline,"maxascentebattery ")) maxAscentEBattery = atof(nw(pline));
  else if (startsWith(pline,"maxascentoxygen ")) maxAscentOxygen = atof(nw(pline));
  else if (startsWith(pline,"maxascenteoxygen ")) maxAscentEOxygen = atof(nw(pline));
  else if (startsWith(pline,"maxdescentfuel ")) maxDescentFuel = atof(nw(pline));
  else if (startsWith(pline,"maxdescentbattery ")) maxDescentBattery = atof(nw(pline));
  else if (startsWith(pline,"maxdescentebattery ")) maxDescentEBattery = atof(nw(pline));
  else if (startsWith(pline,"maxdescentoxygen ")) maxDescentOxygen = atof(nw(pline));
  else if (startsWith(pline,"maxdescenteoxygen ")) maxDescentEOxygen = atof(nw(pline));
  else if (startsWith(pline,"maxrcsfuel ")) maxRcsFuel = atof(nw(pline));
  else if (startsWith(pline,"sample ")) {
    sample = ParseSample(nw(pline));
    samples[samplePos++] = sample;
    }
  else return Spacecraft::SubLoad(file, pline);
  return -1;
  }

