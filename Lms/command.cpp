#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "common.h"
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
  return NULL;
  }

void CommandModule::capsuleSep() {
  }

void CommandModule::Cycle() {
  Spacecraft::Cycle();
  }

void CommandModule::Cutoff() {
  }

Double CommandModule::Apoapsis() {
  return apoapsis;
  }

Boolean CommandModule::Armed() {
  return armed;
  }

Double CommandModule::AscendingNode() {
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
  return NULL;
  }

void CommandModule::Diameter(Double d) {
  d /= 2;
  area = d * d * M_PI;
  }

Byte CommandModule::EnginesLit() {
  return 0;
  }

Double CommandModule::Fuel() {
  return 0;
  }

Double CommandModule::Inclination() {
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
  return commandModuleRcsMaxFuel;
  }

Double CommandModule::MaxFuel() {
  return 0;
  }

Byte CommandModule::NumEngines() {
  return 1;
  }

Byte CommandModule::NumEngines(Byte stage) {
  return 1;
  }

Byte CommandModule::NumEngines(Byte stage, Byte b) {
  return 1;
  }

Byte CommandModule::NumStages() {
  return 1;
  }

Double CommandModule::OrbitTime() {
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
  return periapsis;
  }

Double CommandModule::PitchRate() {
  return pitchRate;
  }

Double CommandModule::RcsFuel() {
  return commandModuleRcsFuel;
  }

Double CommandModule::Radius() {
  return radius;
  }

Double CommandModule::Radius(Double d) {
  radius = d;
  return radius;
  }

Double CommandModule::RateOfClimb() {
  return rateOfClimb;
  }

Double CommandModule::RateOfClimb(Double d) {
  rateOfClimb = d;
  return rateOfClimb;
  }

Double CommandModule::RollRate() {
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
  return 1;
  }

Int8 CommandModule::Throttle() {
  return throttle;
  }

void CommandModule::Undock() {
  }

Double CommandModule::YawRate() {
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
  if (key == 'M') seq->MoveLm();
  panel->ProcessKey(key);
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

