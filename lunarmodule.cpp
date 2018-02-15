#include "header.h"
#include "lunarmodule.h"

LunarModule::LunarModule() {
  throttle = 0;
  pitchRate = 0;
  rcsFbMode = ' ';
  rcsLrMode = ' ';
  rcsUdMode = ' ';
  rollRate = 0;
  yawRate = 0;
  }

LunarModule::~LunarModule() {
  }

char   LunarModule::RcsFbMode() {
  return rcsFbMode;
  }

char   LunarModule::RcsFbMode(char c) {
  rcsFbMode = c;
  return rcsFbMode;
  }

char   LunarModule::RcsLrMode() {
  return rcsLrMode;
  }

char   LunarModule::RcsLrMode(char c) {
  rcsLrMode = c;
  return rcsLrMode;
  }

char   LunarModule::RcsUdMode() {
  return rcsUdMode;
  }

char   LunarModule::RcsUdMode(char c) {
  rcsUdMode = c;
  return rcsUdMode;
  }

Int8   LunarModule::RcsThrottle() {
  return rcsThrottle;
  }

Int8   LunarModule::RcsThrottle(Int8 i) {
  rcsThrottle = i;
  return rcsThrottle;
  }

Int8   LunarModule::Throttle() {
  return throttle;
  }

Int8   LunarModule::Throttle(Int8 i) {
  throttle = i;
  return throttle;
  }

Double LunarModule::AscentFuel() {
  return ascentFuel;
  }

Double LunarModule::AscentFuel(Double d) {
  ascentFuel = d;
  return ascentFuel;
  }

Double LunarModule::Battery() {
  return battery;
  }

Double LunarModule::Battery(Double d) {
  battery = d;
  return battery;
  }

Double LunarModule::DescentFuel() {
  return descentFuel;
  }

Double LunarModule::DescentFuel(Double d) {
  descentFuel = d;
  return descentFuel;
  }

Double LunarModule::Oxygen() {
  return oxygen;
  }

Double LunarModule::Oxygen(Double d) {
  oxygen = d;
  return oxygen;
  }

Double LunarModule::PitchRate() {
  return pitchRate;
  }

Double LunarModule::PitchRate(Double d) {
  pitchRate = d;
  return pitchRate;
  }

Double LunarModule::RcsFuel() {
  return rcsFuel;
  }

Double LunarModule::RcsFuel(Double d) {
  rcsFuel = d;
  return rcsFuel;
  }

Double LunarModule::RollRate() {
  return rollRate;
  }

Double LunarModule::RollRate(Double d) {
  rollRate = d;
  return rollRate;
  }

Double LunarModule::YawRate() {
  return yawRate;
  }

Double LunarModule::YawRate(Double d) {
  yawRate = d;
  return yawRate;
  }

void LunarModule::Save(FILE* file) {
  fprintf(file,"LunarModule {%s",LE);
  Vehicle::Save(file);
  fprintf(file,"  RcsFbMode %d%s",rcsFbMode,LE);
  fprintf(file,"  RcsLrMode %d%s",rcsLrMode,LE);
  fprintf(file,"  RcsUdMode %d%s",rcsUdMode,LE);
  fprintf(file,"  RcsThrottle %d%s",rcsThrottle,LE);
  fprintf(file,"  Throttle %d%s",throttle,LE);
  fprintf(file,"  AscentFuel %f%s",ascentFuel,LE);
  fprintf(file,"  Battery %f%s",battery,LE);
  fprintf(file,"  DescentFuel %f%s",descentFuel,LE);
  fprintf(file,"  Oxygen %f%s",oxygen,LE);
  fprintf(file,"  PitchRate %f%s",pitchRate,LE);
  fprintf(file,"  RcsFuel %f%s",rcsFuel,LE);
  fprintf(file,"  RollRate %f%s",rollRate,LE);
  fprintf(file,"  YawRate %f%s",yawRate,LE);
  fprintf(file,"  }%s",LE);
  }

Int8 LunarModule::SubLoad(char* pline) {
  if (startsWith(pline,"rcsfbmode ")) rcsFbMode = atoi(nw(pline));
  else if (startsWith(pline,"rcslrmode ")) rcsLrMode = atoi(nw(pline));
  else if (startsWith(pline,"rcsudmode ")) rcsUdMode = atoi(nw(pline));
  else if (startsWith(pline,"rcsthrottle ")) rcsThrottle = atoi(nw(pline));
  else if (startsWith(pline,"throttle ")) throttle = atoi(nw(pline));
  else if (startsWith(pline,"ascentfuel ")) ascentFuel = atof(nw(pline));
  else if (startsWith(pline,"battery ")) battery = atof(nw(pline));
  else if (startsWith(pline,"descentfuel ")) descentFuel = atof(nw(pline));
  else if (startsWith(pline,"oxygen ")) oxygen = atof(nw(pline));
  else if (startsWith(pline,"pitchrate ")) pitchRate = atof(nw(pline));
  else if (startsWith(pline,"rcsfuel ")) rcsFuel = atof(nw(pline));
  else if (startsWith(pline,"rollrate ")) rollRate = atof(nw(pline));
  else if (startsWith(pline,"yawrate ")) yawRate = atof(nw(pline));
  else return 0;
  return -1;
  }


