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



