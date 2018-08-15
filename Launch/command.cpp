#include "command.h"
#include "header.h"

CommandModule::CommandModule() {
  launchVehicle = NULL;
  launchVehicleJettisoned = true;
  panel = new Panel("csm.pnl",this);
  parachuteArea = 0;
  parachuteDeployment = 0;
  serviceModuleDryWeight = 0;
  serviceModuleFuel = 0;
  serviceModuleIsp = 0;
  serviceModuleThrust = 0;
  serviceModuleRcsIsp = 0;
  serviceModuleRcsThrust = 0;
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
Vector vel;
Vector vl;
Vector vu;
vu = position.Norm();
vl = Vector(vu.Y(),-vu.X(), 0).Norm().Scale(408);
vel = velocity + vl;
GotoXY(1,25); printf("vel: %.4f\n",vel.Length());
  alt = position.Length() - GROUND;
  thrust = Vector(0,0,0);
  drag = Vector(0,0,0);
  air = AirDensity(alt);
  if (air > 0) {
    cd = 0.8;
    if (faceUp.Dot(vel) < 0) cd = 1.1;
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
  if (throttle > 0) {
    th = serviceModuleThrust / Mass();
    f = th / (9.80665 * serviceModuleIsp) / GRAN;
    if (f <= serviceModuleFuel) {
      serviceModuleFuel -= f;
      thrust = faceUp.Scale(th);
GotoXY(1,27); printf("OMS Fuel: %.2f\n",serviceModuleFuel);
GotoXY(1,28); printf("OMS Thrust: %.2f\n",th);
GotoXY(1,29); printf("Mass: %.2f\n",Mass());
      }
    }
  Spacecraft::Cycle();
  }

Double CommandModule::Apoapsis() {
  if (!launchVehicleJettisoned) return booster->Apoapsis();
  return apoapsis;
  }

Double CommandModule::AscendingNode() {
  if (!launchVehicleJettisoned) return booster->AscendingNode();
  return ascendingNode;
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
  if (serviceModuleDryWeight != 0) {
    ret += serviceModuleDryWeight;
    ret += serviceModuleFuel;
    }

  return ret;
  }

Double CommandModule::MaxFuel() {
  if (!launchVehicleJettisoned) return booster->MaxFuel();
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

Double CommandModule::RollRate() {
  if (!launchVehicleJettisoned) return booster->RollRate();
  return rollRate;
  }

Double CommandModule::ServiceModuleDryWeight(Double d) {
  serviceModuleDryWeight = d;
  return serviceModuleDryWeight;
  }

Double CommandModule::ServiceModuleFuel(Double d) {
  serviceModuleFuel = d;
  return serviceModuleFuel;
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

Double CommandModule::ServiceModuleRcsThrust(Double d) {
  serviceModuleRcsThrust = d;
  return serviceModuleRcsThrust;
  }

Byte CommandModule::Stage() {
  if (!launchVehicleJettisoned) return booster->Stage();
  return 1;
  }

Double CommandModule::YawRate() {
  if (!launchVehicleJettisoned) return booster->YawRate();
  return yawRate;
  }
  
void CommandModule::ProcessKey(Int32 key) {
  if (!launchVehicleJettisoned) booster->ProcessKey(key);
  if (key == 'J' && !launchVehicleJettisoned) capsuleSep();
  if (launchVehicleJettisoned) {
    if (key == KEY_KP_HOME) rollRate++;
    if (key == KEY_PGUP) rollRate--;
    if (key == KEY_LEFT_ARROW) yawRate++;
    if (key == KEY_RIGHT_ARROW) yawRate--;
    if (key == KEY_UP_ARROW) pitchRate++;
    if (key == KEY_DOWN_ARROW) pitchRate--;
    if (key == 'P' && parachuteDeployment == 0 &&
        radius <= GROUND+5000) parachuteDeployment = 0.01;
    if (key == 'I') throttle = 100;
    if (key == 'i') throttle = 0;
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
  fprintf(file,"  ServiceModuleIsp %.18f%s",serviceModuleIsp,LE);
  fprintf(file,"  ServiceModuleThrust %.18f%s",serviceModuleThrust,LE);
  fprintf(file,"  ServiceModuleRcsIsp %.18f%s",serviceModuleRcsIsp,LE);
  fprintf(file,"  ServiceModuleRcsThrust %.18f%s",serviceModuleRcsThrust,LE);
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
  else if (startsWith(pline,"servicemoduleisp ")) serviceModuleIsp = atof(nw(pline));
  else if (startsWith(pline,"servicemodulethrust ")) serviceModuleThrust = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercsisp ")) serviceModuleRcsIsp = atof(nw(pline));
  else if (startsWith(pline,"servicemodulercsthrust ")) serviceModuleRcsThrust = atof(nw(pline));
  else return Spacecraft::SubLoad(file, pline);
  return -1;
  }

