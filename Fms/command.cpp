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
  computer = new CsmComputer(this);
  }

CommandModule::~CommandModule() {
  }

Booster* CommandModule::LaunchVehicle() {
  return launchVehicle;
  }

void CommandModule::capsuleSep() {
  Position(booster->Position());
  Velocity(booster->Velocity());
  faceUp = booster->FaceUp();
  faceLeft = booster->FaceLeft();
  faceFront = booster->FaceFront();
  latitude = booster->Latitude();
  longitude = booster->Longitude();
  apoapsis = booster->Apoapsis();
  periapsis = booster->Periapsis();
  radius = booster->Radius();
  inclination = booster->Inclination();
  ascendingNode = booster->AscendingNode();
  launchVehicleJettisoned = true;
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
    alt = position.Length() - orbiting->Radius();
    thrust = Vector(0,0,0);
    drag = Vector(0,0,0);
    air = AirDensity(alt);
    if (air > 0) {
      cd = 0.8;
      if (faceUp.Dot(vel) < 0) cd = 1.1;
 
    dot = faceUp.Norm().Dot(vel.Norm());
    angle = 180 - acos(dot)*180/M_PI;
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
        rcsThrust = (rcsThrust * serviceModuleRcsDThrust) / Mass();
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceUp.Neg().Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsfuel;
          }
        }
      if (rcsUdMode == 'U') {
        rcsThrust = (rcsThrust * serviceModuleRcsUThrust) / Mass();
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceUp.Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsfuel;
          }
        }
      if (rcsLrMode == 'R') {
        rcsThrust = (rcsThrust * serviceModuleRcsRThrust) / Mass();
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceLeft.Neg().Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsFuel;
          }
        }
      if (rcsLrMode == 'L') {
        rcsThrust = (rcsThrust * serviceModuleRcsLThrust) / Mass();
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceLeft.Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsFuel;
          }
        }
      if (rcsFbMode == 'F') {
        rcsThrust = (rcsThrust * serviceModuleRcsFThrust) / Mass();
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceFront.Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsfuel;
          }
        }
      if (rcsFbMode == 'B') {
        rcsThrust = (rcsThrust * serviceModuleRcsBThrust) / Mass();
        rcsfuel = rcsThrust / (9.80665 * serviceModuleRcsIsp) / GRAN;
        if (rcsFuel <= serviceModuleRcsFuel) {
          thrust = thrust + (faceFront.Neg().Scale(rcsThrust));
          serviceModuleRcsFuel -= rcsfuel;
          }
        }
      }
    if (throttle > 0) {
      if (serviceModuleDryWeight > 0) {
        th = serviceModuleThrust / Mass();
        f = serviceModuleThrust / (9.80665 * serviceModuleIsp) / GRAN;
        if (f <= serviceModuleFuel) {
          serviceModuleFuel -= f;
          thrust = thrust + faceUp.Scale(th);
          }
        else throttle = 0;
        }
      else if (retroModuleDryWeight > 0) {
        th = retroModuleThrust / Mass();
        f = retroModuleThrust / (9.80665 * retroModuleIsp) / GRAN;
        if (f <= retroModuleFuel) {
          retroModuleFuel -= f;
          thrust = thrust + faceUp.Scale(th);
          }
        else throttle = 0;
        }
      }
    Spacecraft::Cycle();
    }
  else {
    position = booster->Position()+booster->FaceUp().Scale(95);
    velocity = booster->Velocity();
    faceUp = booster->FaceUp();
    faceLeft = booster->FaceLeft();
    faceFront = booster->FaceFront();
    latitude = booster->Latitude();
    booster->Longitude();
    }
  computer->Cycle();
  }

void CommandModule::Cutoff() {
  if (!launchVehicleJettisoned) booster->Cutoff();
  else throttle = 0;
  }

Double CommandModule::Apoapsis() {
  if (!launchVehicleJettisoned) return booster->Apoapsis();
  return apoapsis;
  }

Boolean CommandModule::Armed() {
  return armed;
  }

Double CommandModule::AscendingNode() {
  if (!launchVehicleJettisoned) return booster->AscendingNode();
  return ascendingNode;
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

void CommandModule::Diameter(Double d) {
  d /= 2;
  area = d * d * M_PI;
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

Double CommandModule::Inclination() {
  if (!launchVehicleJettisoned) return booster->Inclination();
  return inclination;
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

  return ret;
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
  if (!launchVehicleJettisoned) return booster->NumStages();
  return 1;
  }

Double CommandModule::OrbitTime() {
  if (!launchVehicleJettisoned) return booster->OrbitTime();
  return orbitTime;
  }

Double CommandModule::ParachuteDeployment() {
  return parachuteDeployment;
  }

void CommandModule::ParachuteDiameter(Double d) {
  d /= 2;
  parachuteArea = d * d * M_PI;
  }

Double CommandModule::Periapsis() {
  if (!launchVehicleJettisoned) return booster->Periapsis();
  return periapsis;
  }

Double CommandModule::PitchRate() {
  if (!launchVehicleJettisoned) return booster->PitchRate();
  return pitchRate;
  }

Double CommandModule::RcsFuel() {
  if (serviceModuleDryWeight > 0) return serviceModuleRcsFuel;
  return commandModuleRcsFuel;
  }

Double CommandModule::Radius() {
  if (!launchVehicleJettisoned) return booster->Radius();
  return radius;
  }

Double CommandModule::Radius(Double d) {
  if (!launchVehicleJettisoned) return booster->Radius(d);
  radius = d;
  return radius;
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
  
void CommandModule::ProcessKey(Int32 key) {
  Double *rcsFuel;
  Double rf;
  if (!launchVehicleJettisoned) booster->ProcessKey(key);
  if (panel != NULL) panel->ProcessKey(key);
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
      }
    else if (retroModuleDryWeight > 0) {
      retroModuleDryWeight = 0;
      armed = false;
      }
    }
  if (launchVehicleJettisoned) {
    if (key == 'P' && parachuteDeployment == 0 &&
//        radius <= GROUND+5000) parachuteDeployment = 0.01;
        radius <= orbiting->Radius()+5000) parachuteDeployment = 0.01;
    if (key == 'I' && armed) {
       if (serviceModuleDryWeight > 0 && serviceModuleIsp > 0) {
         throttle = 100;
         clockBu = 0;
         armed = false;
         }
       else if (retroModuleDryWeight > 0) {
         throttle = 100;
         clockBu = 0;
         armed = false;
         }
      }
    if (key == 'i') {
      if (serviceModuleDryWeight > 0) throttle = 0;
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

