#include "command.h"
#include "header.h"
#include "helpers.h"
#include "g_clockbu.h"
#include "csmcomputer.h"

CommandModule::CommandModule() {
  launchVehicle = NULL;
  launchVehicleJettisoned = true;
  panel = new Panel("csm.pnl",this);
  parachuteArea = 0;
  parachuteDeployment = 0;
  serviceModuleDryWeight = 0;
  serviceModuleFuel = 0;
  serviceModuleMaxFuel = 0;
  serviceModuleIsp = 0;
  serviceModuleThrust = 0;
  serviceModuleRcsIsp = 0;
  serviceModuleRcsUThrust = 0;
  serviceModuleRcsDThrust = 0;
  serviceModuleRcsLThrust = 0;
  serviceModuleRcsRThrust = 0;
  serviceModuleRcsFThrust = 0;
  serviceModuleRcsBThrust = 0;
  serviceModuleRcsFuel = 0;
  serviceModuleRcsMaxFuel = 0;
  commandModuleRcsIsp = 0;
  commandModuleRcsThrust = 0;
  commandModuleRcsFuel = 0;
  commandModuleRcsMaxFuel = 0;
  retroModuleDryWeight = 0;
  retroModuleFuel = 0;
  retroModuleIsp = 0;
  retroModuleThrust = 0;
  armed = false;
  type |= VT_COMMAND;
  maxHeat = 0;
  computer = new CsmComputer(this);
  }

CommandModule::~CommandModule() {
  }

Booster* CommandModule::LaunchVehicle() {
  return launchVehicle;
  }

void CommandModule::Ins() {
  Spacecraft::Ins();
  if ((velocity - Orbiting()->Velocity()).Length() > highestVelocity)
    highestVelocity = (velocity - Orbiting()->Velocity()).Length();
  if ((position - Earth->Position()).Length()-Earth->Radius() > farthestFromEarth)
    farthestFromEarth = (position - Earth->Position()).Length()-Earth->Radius();
  if (Orbiting() == Earth) {
    if (inAtmosphere) {
      if (Radius()  > Orbiting()->Radius() + 100000) inAtmosphere = 0;
      }
    else {
      if (Radius() <= Orbiting()->Radius() + 100000) {
        inAtmosphere = 0xff;
        clockRent = clockGe;
        }
      }
    }
  if (Orbiting() == Moon && clockMSoi == 0) {
    clockMSoi = clockGe;
    }
  if (Orbiting() == Earth && clockESoi == 0 && clockMSoi != 0) {
    clockESoi = clockGe;
    }
  if (!launchVehicleJettisoned) accGs =  booster->AccGs();
  if (accGs > maxGs) maxGs = accGs;
  if (accGs < minGs) minGs = accGs;
  }

void CommandModule::capsuleSep() {
  Double h;
  h = booster->Height() + booster->CmOffset();
  Position(booster->Position()+booster->FaceUp().Scale(h));
  Velocity(booster->Velocity()+booster->FaceUp().Scale(0.1));
  faceUp = booster->FaceUp();
  faceLeft = booster->FaceLeft();
  faceFront = booster->FaceFront();
  Latitude(booster->Latitude());
  Longitude(booster->Longitude());
  ins->Apoapsis(booster->Apoapsis());
  ins->Periapsis(booster->Periapsis());
  Radius(booster->Radius());
  ins->Inclination(booster->Inclination());
  ins->AscendingNode(booster->AscendingNode());
  launchVehicleJettisoned = true;
  clockBsp = clockGe;
  }

void CommandModule::Undock() {
  lm->Position(csm->Position()+csm->FaceUp().Scale(5.375));
  lm->Velocity(csm->Velocity() + csm->FaceUp().Scale(0.1));
  lm->FaceUp(csm->FaceUp().Neg());
  lm->FaceLeft(csm->FaceLeft());
  lm->FaceFront(csm->FaceFront());
  lm->Latitude(csm->Latitude());
  lm->Longitude(csm->Longitude());
  lm->Orbiting(csm->Orbiting());
  docked = 0;
  }

void CommandModule::Launch() {
  Vector vu;
  Vector vl;
  Vector vf;
  minGs = 0;
  maxGs = 0;
  booster->Ignition();
  vu = booster->Position().Norm();
  vf = Vector(-vu.Y(), vu.X(), 0).Norm();
  vl = vf.Cross(vu);
  booster->FaceUp(vu);
  booster->FaceLeft(vl);
  booster->FaceFront(vf);
  booster->Velocity(vf.Scale(408));
  launched = true;
  clockLo = clockUt;
  }

void CommandModule::Cycle() {
  Double alt;
  Double air;
  Double d;
  Double v;
  Double cd;
  Double a;
  Double th;
  Double f;
  Double rcsThrust;
  Double rcsfuel;
  Vector vel;
  Vector vl;
  Vector vu;
Double dot;
Double angle;
Vector axis;
Matrix m;
  if (launchVehicleJettisoned) {
    vu = position.Norm();
    vl = Vector(vu.Y(),-vu.X(), 0).Norm().Scale(408);
    vel = velocity + vl;
//    alt = position.Length() - GROUND;
    alt = position.Length() - Orbiting()->Radius();
    thrust = Vector(0,0,0);
    drag = Vector(0,0,0);
    air = AirDensity(alt);
    heat = 0;
    if (air > 0) {
      cd = 0.8;
      if (faceUp.Dot(vel) < 0) cd = 1.1;
 
    dot = faceUp.Norm().Dot(vel.Norm());
    angle = 180 - acos(dot)*180/PI;
    axis = vel.Norm().Cross(faceUp.Norm());
    m = Matrix::Rotate(axis, (angle / 1) / GRAN);
    faceLeft = m.Transform(faceLeft).Norm();
    faceUp = m.Transform(faceUp).Norm();
    faceFront = m.Transform(faceFront).Norm();
 
      if (parachuteDeployment == 0) {
        a = area;
        }
      else {
        a = parachuteArea * parachuteDeployment;
        parachuteDeployment += (parachuteDeployment / GRAN);
        if (parachuteDeployment > 1) parachuteDeployment = 1;
        }
      v = vel.Length();
      d = cd * a * 0.5 * (air * 1.2 * v * v);
      heat = d / area * 0.060136581;
      if (heat > maxHeat) maxHeat = heat;
      d /= Mass();
      drag = vel.Norm().Scale(d).Neg();
      }
    if (serviceModuleDryWeight > 0) {
      switch (rcsThrottle) {
        case 1: rcsThrust = 0.01; break;
        case 10: rcsThrust = 0.10; break;
        case 100: rcsThrust = 1.00; break;
        default : rcsThrust = 0;
        }
      if (rcsUdMode == 'D') {
        rcsThrust = (rcsThrust * serviceModuleRcsDThrust);
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        rcsThrust /= Mass();
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceUp.Neg().Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsfuel;
          }
        }
      if (rcsUdMode == 'U') {
        rcsThrust = (rcsThrust * serviceModuleRcsUThrust);
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        rcsThrust /= Mass();
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceUp.Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsfuel;
          }
        }
      if (rcsLrMode == 'R') {
        rcsThrust = (rcsThrust * serviceModuleRcsRThrust);
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        rcsThrust /= Mass();
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceLeft.Neg().Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsFuel;
          }
        }
      if (rcsLrMode == 'L') {
        rcsThrust = (rcsThrust * serviceModuleRcsLThrust);
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        rcsThrust /= Mass();
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceLeft.Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsFuel;
          }
        }
      if (rcsFbMode == 'F') {
        rcsThrust = (rcsThrust * serviceModuleRcsFThrust);
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        rcsThrust /= Mass();
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceFront.Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsfuel;
          }
        }
      if (rcsFbMode == 'B') {
        rcsThrust = (rcsThrust * serviceModuleRcsBThrust);
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        rcsThrust /= Mass();
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceFront.Neg().Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsfuel;
          }
        }
      }
    fuelUsed = 0;
    if (throttle > 0) {
      if (serviceModuleDryWeight > 0) {
        th = serviceModuleThrust / Mass();
        f = serviceModuleThrust / (9.80665 * serviceModuleIsp) / GRAN;
        if (f <= serviceModuleFuel) {
          serviceModuleFuel -= f;
          fuelUsed += f * GRAN;
          thrust = thrust + faceUp.Scale(th);
          }
        else {
          throttle = 0;
          burn[numBurns-1].end = clockGe;
          burn[numBurns-1].fuelUsed -= serviceModuleFuel;
          }
        }
      else if (retroModuleDryWeight > 0) {
        th = retroModuleThrust / Mass();
        f = retroModuleThrust / (9.80665 * retroModuleIsp) / GRAN;
        if (f <= retroModuleFuel) {
          retroModuleFuel -= f;
          thrust = thrust + faceUp.Scale(th);
          }
        else {
          throttle = 0;
          burn[numBurns-1].end = clockGe;
          burn[numBurns-1].fuelUsed -= retroModuleFuel;
          }
        }
      }
    Spacecraft::Cycle();
    }
  else {
    position = booster->Position()+booster->FaceUp().Scale(booster->Height()+booster->CmOffset());
    velocity = booster->Velocity();
    faceUp = booster->FaceUp();
    faceLeft = booster->FaceLeft();
    faceFront = booster->FaceFront();
    Latitude(booster->Latitude());
    Longitude(booster->Longitude());
    distanceTravelled = booster->DistanceTravelled();
    }
//  computer->Cycle();

  }

void CommandModule::Cutoff() {
  if (!launchVehicleJettisoned) booster->Cutoff();
  else {
    throttle = 0;
    burn[numBurns-1].end = clockGe;
    burn[numBurns-1].fuelUsed -= Fuel();
    }
  if (Orbiting() == Moon) {
    if (ignitionEccentricity >= 1 && ins->Eccentricity() <1) clockLoi = ignitionTime;
    if (ignitionEccentricity <1 && ins->Eccentricity() >= 1) clockTei = ignitionTime;
    }
  if (Orbiting() == Earth) {
    if (ignitionApoapsis < 200000000 && ins->Apoapsis() > 350000000) clockTli = ignitionTime;
    }
  }
Double CommandModule::AccGs() {
  return accGs;
  }

Double CommandModule::MaxGs() {
  return maxGs;
  }

Double CommandModule::MinGs() {
  return minGs;
  }

Double CommandModule::Apoapsis() {
  if (!launchVehicleJettisoned) return booster->Apoapsis();
  return ins->Apoapsis();
  }

Boolean CommandModule::Armed() {
  return armed;
  }

Double CommandModule::AscendingNode() {
  if (!launchVehicleJettisoned) return booster->AscendingNode();
  return ins->AscendingNode();
  }

Double CommandModule::CommandModuleRcsIsp(Double d) {
  commandModuleRcsIsp = d;
  return commandModuleRcsIsp;
  }

Double CommandModule::CommandModuleRcsFuel() {
  return commandModuleRcsFuel;
  }

Double CommandModule::CommandModuleRcsFuel(Double d) {
  commandModuleRcsFuel = d;
  return commandModuleRcsFuel;
  }

Double CommandModule::CommandModuleRcsMaxFuel() {
  return commandModuleRcsMaxFuel;
  }

Double CommandModule::CommandModuleRcsMaxFuel(Double d) {
  commandModuleRcsMaxFuel = d;
  return commandModuleRcsMaxFuel;
  }

Double CommandModule::CommandModuleRcsThrust(Double d) {
  commandModuleRcsThrust = d;
  return commandModuleRcsThrust;
  }

CsmComputer* CommandModule::Computer() {
  return computer;
  }

Double CommandModule::DeltaV() {
  if (!launchVehicleJettisoned) return booster->DeltaV();
  return deltaV;
  }

void CommandModule::Diameter(Double d) {
  d /= 2;
  area = d * d * PI;
  }

Byte CommandModule::EnginesLit() {
  if (!launchVehicleJettisoned) return booster->EnginesLit();
  return 0;
  }

Double CommandModule::Fuel() {
  if (!launchVehicleJettisoned) return booster->Fuel();
  else if (serviceModuleDryWeight > 0) return serviceModuleFuel;
  else if (retroModuleDryWeight > 0) return retroModuleFuel;
  return 0;
  }

Double CommandModule::FuelUsed() {
  if (!launchVehicleJettisoned) return booster->FuelUsed();
  return fuelUsed;
  }

Double CommandModule::Heat() {
  return heat;
  }

Double CommandModule::Isp() {
  if (!launchVehicleJettisoned) return booster->Isp();
  else if (serviceModuleDryWeight > 0) return serviceModuleIsp;
  else if (retroModuleDryWeight > 0) return retroModuleIsp;
  return 0;
  }

void CommandModule::Ignition() {
  if (!launchVehicleJettisoned) booster->Ignition();
  else {
    if (serviceModuleDryWeight > 0 && serviceModuleIsp > 0) {
      throttle = 100;
      clockBu = 0;
      armed = false;
      burn[numBurns].start = clockGe;
      burn[numBurns].engine = 'S';
      burn[numBurns].fuelUsed = Fuel();
      numBurns++;
      ignitionTime = clockGe;
      ignitionApoapsis = ins->Apoapsis();
      ignitionPeriapsis = ins->Periapsis();
      ignitionEccentricity = ins->Eccentricity();
      deltaV = 0;
      }
    }
  }

Double CommandModule::Inclination() {
  if (!launchVehicleJettisoned) return booster->Inclination();
  return ins->Inclination();
  }

Booster* CommandModule::LaunchVehicle(Booster* lv) {
  launchVehicle = lv;
  launchVehicleJettisoned = false;
  return launchVehicle;
  }

Boolean CommandModule::LaunchVehicleJettisoned() {
  return launchVehicleJettisoned;
  }

Boolean CommandModule::LaunchVehicleJettisoned(Boolean b) {
  launchVehicleJettisoned = b;
  return launchVehicleJettisoned;
  }

Double CommandModule::Mass() {
  Double ret;
  ret = dryWeight;
  ret += commandModuleRcsFuel;
  if (serviceModuleDryWeight != 0) {
    ret += serviceModuleDryWeight;
    ret += serviceModuleFuel;
    ret += serviceModuleRcsFuel;
    }
  if (retroModuleDryWeight != 0) {
    ret += retroModuleDryWeight;
    ret += retroModuleFuel;
    }
  if (docked && targetVehicle != NULL) {
    ret += targetVehicle->Mass();
    if (lmExtracted == 0) ret += booster->Mass();
    }
  if (!launchVehicleJettisoned) ret += booster->Mass();
  return ret;
  }

Double CommandModule::MaxHeat() {
  return maxHeat;
  }

Double CommandModule::MaxRcsFuel() {
  if (serviceModuleDryWeight > 0) return serviceModuleRcsMaxFuel;
  return commandModuleRcsMaxFuel;
  }

Double CommandModule::MaxFuel() {
  if (!launchVehicleJettisoned) return booster->MaxFuel();
  else if (serviceModuleDryWeight > 0) return serviceModuleMaxFuel;
  else if (retroModuleDryWeight > 0) return retroModuleMaxFuel;
  return 0;
  }

Byte CommandModule::NumEngines() {
  if (!launchVehicleJettisoned) return booster->NumEngines();
  return 1;
  }

Byte CommandModule::NumEngines(Byte stage) {
  if (!launchVehicleJettisoned) return booster->NumEngines(stage);
  return 1;
  }

Byte CommandModule::NumEngines(Byte stage, Byte b) {
  if (!launchVehicleJettisoned) return booster->NumEngines(stage, b);
  return 1;
  }

Byte CommandModule::NumStages() {
  return booster->NumStages();
  }

Double CommandModule::OrbitTime() {
  if (!launchVehicleJettisoned) return booster->OrbitTime();
  return ins->OrbitTime();
  }

Double CommandModule::ParachuteDeployment() {
  return parachuteDeployment;
  }

void CommandModule::ParachuteDiameter(Double d) {
  d /= 2;
  parachuteArea = d * d * PI;
  }

Double CommandModule::Periapsis() {
  if (!launchVehicleJettisoned) return booster->Periapsis();
  return ins->Periapsis();
  }

Double CommandModule::PitchRate() {
  if (!launchVehicleJettisoned) return booster->PitchRate();
  return pitchRate;
  }

Double CommandModule::RcsFuel() {
  if (serviceModuleDryWeight > 0) return serviceModuleRcsFuel;
  return commandModuleRcsFuel;
  }

Double CommandModule::RcsIsp() {
  if (serviceModuleDryWeight > 0) return serviceModuleRcsIsp;
  return rcsIsp;
  }

Double CommandModule::Radius() {
  if (!launchVehicleJettisoned) return booster->Radius();
  return ins->Radius();
  }

Double CommandModule::Radius(Double d) {
  if (!launchVehicleJettisoned) return booster->Radius(d);
  return ins->Radius(d);
  }

Double CommandModule::RateOfClimb() {
  if (!launchVehicleJettisoned) return booster->RateOfClimb();
  return rateOfClimb;
  }

Double CommandModule::RateOfClimb(Double d) {
  rateOfClimb = d;
  if (!launchVehicleJettisoned) return booster->RateOfClimb(d);
  return rateOfClimb;
  }

Double CommandModule::RollRate() {
  if (!launchVehicleJettisoned) return booster->RollRate();
  return rollRate;
  }

Double CommandModule::RetroModuleDryWeight() {
  return retroModuleDryWeight;
  }

Double CommandModule::RetroModuleDryWeight(Double d) {
  retroModuleDryWeight = d;
  return retroModuleDryWeight;
  }

Double CommandModule::RetroModuleFuel() {
  return retroModuleFuel;
  }

Double CommandModule::RetroModuleFuel(Double d) {
  retroModuleFuel = d;
  return retroModuleFuel;
  }

Double CommandModule::RetroModuleMaxFuel() {
  return retroModuleMaxFuel;
  }

Double CommandModule::RetroModuleMaxFuel(Double d) {
  retroModuleMaxFuel = d;
  return retroModuleMaxFuel;
  }

Double CommandModule::RetroModuleIsp() {
  return retroModuleIsp;
  }

Double CommandModule::RetroModuleIsp(Double d) {
  retroModuleIsp = d;
  return retroModuleIsp;
  }

Double CommandModule::RetroModuleThrust(Double d) {
  retroModuleThrust = d;
  return retroModuleThrust;
  }

Double CommandModule::ServiceModuleDryWeight() {
  return serviceModuleDryWeight;
  }

Double CommandModule::ServiceModuleDryWeight(Double d) {
  serviceModuleDryWeight = d;
  return serviceModuleDryWeight;
  }

Double CommandModule::ServiceModuleFuel() {
  return serviceModuleFuel;
  }

Double CommandModule::ServiceModuleFuel(Double d) {
  serviceModuleFuel = d;
  return serviceModuleFuel;
  }

Double CommandModule::ServiceModuleMaxFuel() {
  return serviceModuleMaxFuel;
  }

Double CommandModule::ServiceModuleMaxFuel(Double d) {
  serviceModuleMaxFuel = d;
  return serviceModuleMaxFuel;
  }

Double CommandModule::ServiceModuleIsp() {
  return serviceModuleIsp;
  }

Double CommandModule::ServiceModuleIsp(Double d) {
  serviceModuleIsp = d;
  return serviceModuleIsp;
  }

Double CommandModule::ServiceModuleThrust(Double d) {
  serviceModuleThrust = d;
  return serviceModuleThrust;
  }

Double CommandModule::ServiceModuleRcsIsp(Double d) {
  serviceModuleRcsIsp = d;
  return serviceModuleRcsIsp;
  }

Double CommandModule::ServiceModuleRcsFuel() {
  return serviceModuleRcsFuel;
  }

Double CommandModule::ServiceModuleRcsFuel(Double d) {
  serviceModuleRcsFuel = d;
  return serviceModuleRcsFuel;
  }

Double CommandModule::ServiceModuleRcsMaxFuel() {
  return serviceModuleRcsMaxFuel;
  }

Double CommandModule::ServiceModuleRcsMaxFuel(Double d) {
  serviceModuleRcsMaxFuel = d;
  return serviceModuleRcsMaxFuel;
  }

Double CommandModule::ServiceModuleRcsThrust(Double d) {
  serviceModuleRcsUThrust = d;
  serviceModuleRcsDThrust = d;
  serviceModuleRcsLThrust = d;
  serviceModuleRcsRThrust = d;
  serviceModuleRcsFThrust = d;
  serviceModuleRcsBThrust = d;
  return serviceModuleRcsUThrust;
  }

Double CommandModule::ServiceModuleRcsUThrust(Double d) {
  serviceModuleRcsUThrust = d;
  return serviceModuleRcsUThrust;
  }

Double CommandModule::ServiceModuleRcsDThrust(Double d) {
  serviceModuleRcsDThrust = d;
  return serviceModuleRcsDThrust;
  }

Double CommandModule::ServiceModuleRcsLThrust(Double d) {
  serviceModuleRcsLThrust = d;
  return serviceModuleRcsLThrust;
  }

Double CommandModule::ServiceModuleRcsRThrust(Double d) {
  serviceModuleRcsRThrust = d;
  return serviceModuleRcsRThrust;
  }

Double CommandModule::ServiceModuleRcsFThrust(Double d) {
  serviceModuleRcsFThrust = d;
  return serviceModuleRcsFThrust;
  }

Double CommandModule::ServiceModuleRcsBThrust(Double d) {
  serviceModuleRcsBThrust = d;
  return serviceModuleRcsBThrust;
  }

Byte CommandModule::Stage() {
  if (!launchVehicleJettisoned) return booster->Stage();
  return 1;
  }

Int8 CommandModule::Throttle() {
  if (!launchVehicleJettisoned) return booster->Throttle();
  return throttle;
  }

Double CommandModule::YawRate() {
  if (!launchVehicleJettisoned) return booster->YawRate();
  return yawRate;
  }

Double CommandModule::rcsRotationFuelUsage() {
  switch (rcsRotThrottle) {
    case 10: return 0.01;
    case 50: return 0.05;
    case 100: return 0.10;
    }
  return 0.01;
  }
  
void CommandModule::Prograde(Double maxRate) {
  if (!launchVehicleJettisoned) booster->Prograde(maxRate);
    else Spacecraft::Prograde(maxRate);
  }

void CommandModule::Retrograde(Double maxRate) {
  if (!launchVehicleJettisoned) booster->Retrograde(maxRate);
    else Spacecraft::Retrograde(maxRate);
  }

void CommandModule::ProcessKey(Int32 key) {
  Double *rcsFuel;
  Double rf;
  if (!launchVehicleJettisoned) booster->ProcessKey(key);
  if (panel != NULL) panel->ProcessKey(key);
  if (mission->StartLocation() == 'M') {
    if (key == 'M' && docked && lm != NULL) {
      seq->MoveLm();
      }
    return;
    }
  if (computer != NULL) computer->ProcessKey(key);
  if (key == 9) {
    armed = !armed;
    }
  if (key == 'J' && armed) {
    if (!launchVehicleJettisoned) {
      capsuleSep();
      armed = false;
      }
    else if (serviceModuleDryWeight > 0) {
      serviceModuleDryWeight = 0;
      armed = false;
      clockSmJt = clockGe;
      }
    else if (retroModuleDryWeight > 0) {
      retroModuleDryWeight = 0;
      armed = false;
      clockRmJt = clockGe;
      }
    }
  if (launchVehicleJettisoned) {
    if (key == 'E' && docked && lmExtracted == 0) {
      lmExtracted = -1;
      velocity += faceUp.Norm().Neg().Scale(0.1);
      clockLExt = clockGe;
      }
    if (key == 'P' && parachuteDeployment == 0 &&
        Radius() <= Orbiting()->Radius()+5000) {
      parachuteDeployment = 0.01;
      clockPara = clockGe;
      }
    if (key == 'I' && armed) {
       if (serviceModuleDryWeight > 0 && serviceModuleIsp > 0) {
         throttle = 100;
         clockBu = 0;
         armed = false;
         burn[numBurns].start = clockGe;
         burn[numBurns].engine = 'S';
         burn[numBurns].fuelUsed = Fuel();
         numBurns++;
         ignitionTime = clockGe;
         ignitionApoapsis = ins->Apoapsis();
         ignitionPeriapsis = ins->Periapsis();
         ignitionEccentricity = ins->Eccentricity();
         deltaV = 0;
         }
       else if (retroModuleDryWeight > 0) {
         throttle = 100;
         clockBu = 0;
         armed = false;
         burn[numBurns].start = clockGe;
         burn[numBurns].engine = 'R';
         burn[numBurns].fuelUsed = Fuel();
         numBurns++;
         ignitionTime = clockGe;
         ignitionApoapsis = ins->Apoapsis();
         ignitionPeriapsis = ins->Periapsis();
         ignitionEccentricity = ins->Eccentricity();
         }
      }
    if (key == 'M' && docked && lm != NULL) {
      seq->MoveLm();
      }
    if (key == 'U' && docked && lm != NULL && armed) {
      seq->CmUndock();
      armed = 0;
      clockLmJt = clockGe;
      }
    if (key == 'i' && throttle > 0) {
      Cutoff();
//      if (serviceModuleDryWeight > 0) throttle = 0;
//      if (Orbiting() == Moon) {
//        if (ignitionEccentricity >= 1 && ins->Eccentricity() <1) clockLoi = ignitionTime;
//        if (ignitionEccentricity <1 && ins->Eccentricity() >= 1) clockTei = ignitionTime;
//        }
//      if (Orbiting() == Earth) {
//        if (ignitionApoapsis < 200000000 && ins->Apoapsis() > 350000000) clockTli = ignitionTime;
//        }
      }
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
    if (key == KEY_KP_HOME) {
      rf = rcsRotationFuelUsage();
      rcsFuel = (serviceModuleDryWeight > 0) ? &serviceModuleRcsFuel : &commandModuleRcsFuel;
      if (*rcsFuel >= rf) {
        rollRate += (rcsRotThrottle / 100.0);
        *rcsFuel -= rf;
        }
      }
    if (key == KEY_HOME) {
      rf = rcsRotationFuelUsage();
      rcsFuel = (serviceModuleDryWeight > 0) ? &serviceModuleRcsFuel : &commandModuleRcsFuel;
      if (*rcsFuel >= rf) {
        rollRate += (rcsRotThrottle / 100.0);
        *rcsFuel -= rf;
        }
      }
    if (key == KEY_PGUP) {
      rf = rcsRotationFuelUsage();
      rcsFuel = (serviceModuleDryWeight > 0) ? &serviceModuleRcsFuel : &commandModuleRcsFuel;
      if (*rcsFuel >= rf) {
        rollRate -= (rcsRotThrottle / 100.0);
        *rcsFuel -= rf;
        }
      }
    if (key == KEY_UP_ARROW) {
      rf = rcsRotationFuelUsage();
      rcsFuel = (serviceModuleDryWeight > 0) ? &serviceModuleRcsFuel : &commandModuleRcsFuel;
      if (*rcsFuel >= rf) {
        pitchRate += (rcsRotThrottle / 100.0);
        *rcsFuel -= rf;
        }
      }
    if (key == KEY_DOWN_ARROW) {
      rf = rcsRotationFuelUsage();
      rcsFuel = (serviceModuleDryWeight > 0) ? &serviceModuleRcsFuel : &commandModuleRcsFuel;
      if (*rcsFuel >= rf) {
        pitchRate -= (rcsRotThrottle / 100.0);
        *rcsFuel -= rf;
        }
      }
    if (key == KEY_RIGHT_ARROW) {
      rf = rcsRotationFuelUsage();
      rcsFuel = (serviceModuleDryWeight > 0) ? &serviceModuleRcsFuel : &commandModuleRcsFuel;
      if (*rcsFuel >= rf) {
        yawRate += (rcsRotThrottle / 100.0);
        *rcsFuel -= rf;
        }
      }
    if (key == KEY_LEFT_ARROW) {
      rf = rcsRotationFuelUsage();
      rcsFuel = (serviceModuleDryWeight > 0) ? &serviceModuleRcsFuel : &commandModuleRcsFuel;
      if (*rcsFuel >= rf) {
        yawRate -= (rcsRotThrottle / 100.0);
        *rcsFuel -= rf;
        }
      }
    }
  }

void CommandModule::Save(FILE* file) {
  fprintf(file,"CommandModule {%s",LE);
  Spacecraft::Save(file);
  if (launchVehicleJettisoned)
    fprintf(file,"  LaunchVehicleJettisoned true%s",LE);
  else
    fprintf(file,"  LaunchVehicleJettisoned false%s",LE);
  fprintf(file,"  Area %.18f%s",area,LE);
  fprintf(file,"  ParachuteArea %.18f%s",parachuteArea,LE);
  fprintf(file,"  ParachuteDeployment %.18f%s",parachuteDeployment,LE);
  fprintf(file,"  ServiceModuleDryWeight %.18f%s",serviceModuleDryWeight,LE);
  fprintf(file,"  ServiceModuleFuel %.18f%s",serviceModuleFuel,LE);
  fprintf(file,"  ServiceModuleMaxFuel %.18f%s",serviceModuleMaxFuel,LE);
  fprintf(file,"  ServiceModuleIsp %.18f%s",serviceModuleIsp,LE);
  fprintf(file,"  ServiceModuleThrust %.18f%s",serviceModuleThrust,LE);
  fprintf(file,"  ServiceModuleRcsIsp %.18f%s",serviceModuleRcsIsp,LE);
  fprintf(file,"  ServiceModuleRcsFuel %.18f%s",serviceModuleRcsFuel,LE);
  fprintf(file,"  ServiceModuleRcsMaxFuel %.18f%s",serviceModuleRcsMaxFuel,LE);
  fprintf(file,"  ServiceModuleRcsUThrust %.18f%s",serviceModuleRcsUThrust,LE);
  fprintf(file,"  ServiceModuleRcsDThrust %.18f%s",serviceModuleRcsDThrust,LE);
  fprintf(file,"  ServiceModuleRcsLThrust %.18f%s",serviceModuleRcsLThrust,LE);
  fprintf(file,"  ServiceModuleRcsRThrust %.18f%s",serviceModuleRcsRThrust,LE);
  fprintf(file,"  ServiceModuleRcsFThrust %.18f%s",serviceModuleRcsFThrust,LE);
  fprintf(file,"  ServiceModuleRcsBThrust %.18f%s",serviceModuleRcsBThrust,LE);
  fprintf(file,"  RetroModuleDryWeight %.18f%s",retroModuleDryWeight,LE);
  fprintf(file,"  RetroModuleFuel %.18f%s",retroModuleFuel,LE);
  fprintf(file,"  RetroModuleMaxFuel %.18f%s",retroModuleMaxFuel,LE);
  fprintf(file,"  RetroModuleIsp %.18f%s",retroModuleIsp,LE);
  fprintf(file,"  RetroModuleThrust %.18f%s",retroModuleThrust,LE);
  fprintf(file,"  CommandModuleRcsIsp %.18f%s",commandModuleRcsIsp,LE);
  fprintf(file,"  CommandModuleRcsFuel %.18f%s",commandModuleRcsFuel,LE);
  fprintf(file,"  CommandModuleRcsMaxFuel %.18f%s",commandModuleRcsMaxFuel,LE);
  fprintf(file,"  CommandModuleRcsThrust %.18f%s",commandModuleRcsThrust,LE);
  computer->Save(file);
  fprintf(file,"  }%s",LE);
  }

Int8 CommandModule::SubLoad(FILE* file, char* pline) {
  if (startsWith(pline,"launchvehiclejettisoned true"))
    launchVehicleJettisoned = true;
  else if (startsWith(pline,"launchvehiclejettisoned false"))
    launchVehicleJettisoned = false;
  else if (startsWith(pline,"area ")) area = atof(nw(pline));
  else if (startsWith(pline,"parachutearea ")) parachuteArea = atof(nw(pline));
  else if (startsWith(pline,"parachutedeployment ")) parachuteDeployment = atof(nw(pline));
  else if (startsWith(pline,"servicemoduledryweight ")) serviceModuleDryWeight = atof(nw(pline));
  else if (startsWith(pline,"servicemodulefuel ")) serviceModuleFuel = atof(nw(pline));
  else if (startsWith(pline,"servicemodulemaxfuel ")) serviceModuleMaxFuel = atof(nw(pline));
  else if (startsWith(pline,"servicemoduleisp ")) serviceModuleIsp = atof(nw(pline));
  else if (startsWith(pline,"servicemodulethrust ")) serviceModuleThrust = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercsisp ")) serviceModuleRcsIsp = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercsfuel ")) serviceModuleRcsFuel = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercsmaxfuel ")) serviceModuleRcsMaxFuel = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercsuthrust ")) serviceModuleRcsUThrust = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercsdthrust ")) serviceModuleRcsDThrust = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercslthrust ")) serviceModuleRcsLThrust = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercsrthrust ")) serviceModuleRcsRThrust = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercsfthrust ")) serviceModuleRcsFThrust = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercsbthrust ")) serviceModuleRcsBThrust = atof(nw(pline));
  else if (startsWith(pline,"retromoduledryweight ")) retroModuleDryWeight = atof(nw(pline));
  else if (startsWith(pline,"retromodulefuel ")) retroModuleFuel = atof(nw(pline));
  else if (startsWith(pline,"retromodulemaxfuel ")) retroModuleMaxFuel = atof(nw(pline));
  else if (startsWith(pline,"retromoduleisp ")) retroModuleIsp = atof(nw(pline));
  else if (startsWith(pline,"retromodulethrust ")) retroModuleThrust = atof(nw(pline));
  else if (startsWith(pline,"commandmodulercsisp ")) commandModuleRcsIsp = atof(nw(pline));
  else if (startsWith(pline,"commandmodulercsfuel ")) commandModuleRcsFuel = atof(nw(pline));
  else if (startsWith(pline,"commandmodulercsmaxfuel ")) commandModuleRcsMaxFuel = atof(nw(pline));
  else if (startsWith(pline,"commandmodulercsthrust ")) commandModuleRcsThrust = atof(nw(pline));
  else if (startsWith(pline,"computer ")) return computer->Load(file);
  else return Spacecraft::SubLoad(file, pline);
  return -1;
  }

