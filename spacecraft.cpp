#include "spacecraft.h"

SpaceCraft::SpaceCraft() {
  throttle = 0;
  pitchRate = 0;
  rcsFbMode = ' ';
  rcsLrMode = ' ';
  rcsUdMode = ' ';
  rollRate = 0;
  yawRate = 0;
  }

SpaceCraft::~SpaceCraft() {
  }

char   SpaceCraft::RcsFbMode() {
  return rcsFbMode;
  }

char   SpaceCraft::RcsFbMode(char c) {
  rcsFbMode = c;
  return rcsFbMode;
  }

char   SpaceCraft::RcsLrMode() {
  return rcsLrMode;
  }

char   SpaceCraft::RcsLrMode(char c) {
  rcsLrMode = c;
  return rcsLrMode;
  }

char   SpaceCraft::RcsUdMode() {
  return rcsUdMode;
  }

char   SpaceCraft::RcsUdMode(char c) {
  rcsUdMode = c;
  return rcsUdMode;
  }

Int8   SpaceCraft::RcsThrottle() {
  return rcsThrottle;
  }

Int8   SpaceCraft::RcsThrottle(Int8 i) {
  rcsThrottle = i;
  return rcsThrottle;
  }

Int8   SpaceCraft::Throttle() {
  return throttle;
  }

Int8   SpaceCraft::Throttle(Int8 i) {
  throttle = i;
  return throttle;
  }

Double SpaceCraft::AscentFuel() {
  return ascentFuel;
  }

Double SpaceCraft::AscentFuel(Double d) {
  ascentFuel = d;
  return ascentFuel;
  }

Double SpaceCraft::Battery() {
  return battery;
  }

Double SpaceCraft::Battery(Double d) {
  battery = d;
  return battery;
  }

Double SpaceCraft::DescentFuel() {
  return descentFuel;
  }

Double SpaceCraft::DescentFuel(Double d) {
  descentFuel = d;
  return descentFuel;
  }

Double SpaceCraft::Oxygen() {
  return oxygen;
  }

Double SpaceCraft::Oxygen(Double d) {
  oxygen = d;
  return oxygen;
  }

Double SpaceCraft::PitchRate() {
  return pitchRate;
  }

Double SpaceCraft::PitchRate(Double d) {
  pitchRate = d;
  return pitchRate;
  }

Double SpaceCraft::RcsFuel() {
  return rcsFuel;
  }

Double SpaceCraft::RcsFuel(Double d) {
  rcsFuel = d;
  return rcsFuel;
  }

Double SpaceCraft::RollRate() {
  return rollRate;
  }

Double SpaceCraft::RollRate(Double d) {
  rollRate = d;
  return rollRate;
  }

Double SpaceCraft::YawRate() {
  return yawRate;
  }

Double SpaceCraft::YawRate(Double d) {
  yawRate = d;
  return yawRate;
  }



