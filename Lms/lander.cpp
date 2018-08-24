#include <math.h>
#include "lander.h"

Lander::Lander(Byte b) {
  vehicle = b;
  }

Lander::~Lander() {
  }

UInt32 Lander::AscentConsumables() {
  switch (vehicle) {
    case APOLLO: return APOLLO_ASCENT_CONSUMABLES;
    case APOLLO_J: return APOLLO_J_ASCENT_CONSUMABLES;
    case APOLLO_MKII: return APOLLO_MKII_ASCENT_CONSUMABLES;
    case APOLLO_MKIII: return APOLLO_MKIII_ASCENT_CONSUMABLES;
    }
  return 0;
  }

Double Lander::AscentDeltaV() {
  Double full;
  Double empty;
  full = AscentFullWeight();
  empty = AscentEmptyWeight() + RcsFuel();
  return (AscentIsp() * 9.80665) * log(full / empty);
  }

UInt32 Lander::AscentEConsumables() {
  switch (vehicle) {
    case APOLLO: return APOLLO_ASCENT_ECONSUMABLES;
    case APOLLO_J: return APOLLO_J_ASCENT_ECONSUMABLES;
    case APOLLO_MKII: return APOLLO_MKII_ASCENT_ECONSUMABLES;
    case APOLLO_MKIII: return APOLLO_MKIII_ASCENT_ECONSUMABLES;
    }
  return 0;
  }

Double Lander::AscentEmptyWeight() {
  switch (vehicle) {
    case APOLLO: return APOLLO_ASCENT_EMPTY_WEIGHT;
    case APOLLO_J: return APOLLO_J_ASCENT_EMPTY_WEIGHT;
    case APOLLO_MKII: return APOLLO_MKII_ASCENT_EMPTY_WEIGHT;
    case APOLLO_MKIII: return APOLLO_MKIII_ASCENT_EMPTY_WEIGHT;
    }
  return 0;
  }

Double Lander::AscentFuel() {
  switch (vehicle) {
    case APOLLO: return APOLLO_ASCENT_FUEL;
    case APOLLO_J: return APOLLO_J_ASCENT_FUEL;
    case APOLLO_MKII: return APOLLO_MKII_ASCENT_FUEL;
    case APOLLO_MKIII: return APOLLO_MKIII_ASCENT_FUEL;
    }
  return 0;
  }

Double Lander::AscentFullWeight() {
  return AscentEmptyWeight() + AscentFuel() + RcsFuel();
  }

Double Lander::AscentIsp() {
  switch (vehicle) {
    case APOLLO: return APOLLO_ASCENT_ISP;
    case APOLLO_J: return APOLLO_J_ASCENT_ISP;
    case APOLLO_MKII: return APOLLO_MKII_ASCENT_ISP;
    case APOLLO_MKIII: return APOLLO_MKIII_ASCENT_ISP;
    }
  return 0;
  }

Double Lander::AscentThrust() {
  switch (vehicle) {
    case APOLLO: return APOLLO_ASCENT_THRUST;
    case APOLLO_J: return APOLLO_J_ASCENT_THRUST;
    case APOLLO_MKII: return APOLLO_MKII_ASCENT_THRUST;
    case APOLLO_MKIII: return APOLLO_MKIII_ASCENT_THRUST;
    }
  return 0;
  }

UInt32 Lander::Consumables() {
  switch (vehicle) {
    case APOLLO: return APOLLO_CONSUMABLES;
    case APOLLO_J: return APOLLO_J_CONSUMABLES;
    case APOLLO_MKII: return APOLLO_MKII_CONSUMABLES;
    case APOLLO_MKIII: return APOLLO_MKIII_CONSUMABLES;
    }
  return 0;
  }

Double Lander::DescentDeltaV() {
  Double full;
  Double empty;
  full = DescentFullWeight() + AscentFullWeight();
  empty = full - DescentFuel();
  return (DescentIsp() * 9.80665) * log(full / empty);
  }

Double Lander::DescentEmptyWeight() {
  switch (vehicle) {
    case APOLLO: return APOLLO_DESCENT_EMPTY_WEIGHT;
    case APOLLO_J: return APOLLO_J_DESCENT_EMPTY_WEIGHT;
    case APOLLO_MKII: return APOLLO_MKII_DESCENT_EMPTY_WEIGHT;
    case APOLLO_MKIII: return APOLLO_MKIII_DESCENT_EMPTY_WEIGHT;
    }
  return 0;
  }

Double Lander::DescentFuel() {
  switch (vehicle) {
    case APOLLO: return APOLLO_DESCENT_FUEL;
    case APOLLO_J: return APOLLO_J_DESCENT_FUEL;
    case APOLLO_MKII: return APOLLO_MKII_DESCENT_FUEL;
    case APOLLO_MKIII: return APOLLO_MKIII_DESCENT_FUEL;
    }
  return 0;
  }

Double Lander::DescentFullWeight() {
  Double ret;
  ret = DescentEmptyWeight() + DescentFuel();
  ret += (Consumables() / 3600.0 * 0.060666);
  ret += (Consumables() / 3600.0 * 0.308333);
  ret += (Consumables() / 3600.0 * 0.205833);
  ret += (vehicle == APOLLO) ? ELSEP_WEIGHT : ALSEP_WEIGHT;
  ret += LASER_WEIGHT;
  if (vehicle == APOLLO_J) ret += ROVER_MKI_WEIGHT;
  if (vehicle == APOLLO_MKII) ret += ROVER_MKII_WEIGHT;
  if (vehicle == APOLLO_MKIII) ret += ROVER_MKIII_WEIGHT;
  return ret;
  }

Double Lander::DescentIsp() {
  switch (vehicle) {
    case APOLLO: return APOLLO_DESCENT_ISP;
    case APOLLO_J: return APOLLO_J_DESCENT_ISP;
    case APOLLO_MKII: return APOLLO_MKII_DESCENT_ISP;
    case APOLLO_MKIII: return APOLLO_MKIII_DESCENT_ISP;
    }
  return 0;
  }

Double Lander::DescentThrust() {
  switch (vehicle) {
    case APOLLO: return APOLLO_DESCENT_THRUST;
    case APOLLO_J: return APOLLO_J_DESCENT_THRUST;
    case APOLLO_MKII: return APOLLO_MKII_DESCENT_THRUST;
    case APOLLO_MKIII: return APOLLO_MKIII_DESCENT_THRUST;
    }
  return 0;
  }

UInt32 Lander::EConsumables() {
  switch (vehicle) {
    case APOLLO: return APOLLO_ECONSUMABLES;
    case APOLLO_J: return APOLLO_J_ECONSUMABLES;
    case APOLLO_MKII: return APOLLO_MKII_ECONSUMABLES;
    case APOLLO_MKIII: return APOLLO_MKIII_ECONSUMABLES;
    }
  return 0;
  }

Double Lander::RcsFuel() {
  switch (vehicle) {
    case APOLLO: return APOLLO_RCS_FUEL;
    case APOLLO_J: return APOLLO_J_RCS_FUEL;
    case APOLLO_MKII: return APOLLO_MKII_RCS_FUEL;
    case APOLLO_MKIII: return APOLLO_MKIII_RCS_FUEL;
    }
  return 0;
  }

Double Lander::RcsIsp() {
  switch (vehicle) {
    case APOLLO: return APOLLO_RCS_ISP;
    case APOLLO_J: return APOLLO_J_RCS_ISP;
    case APOLLO_MKII: return APOLLO_MKII_RCS_ISP;
    case APOLLO_MKIII: return APOLLO_MKIII_RCS_ISP;
    }
  return 0;
  }

Double Lander::RcsThrust() {
  switch (vehicle) {
    case APOLLO: return APOLLO_RCS_THRUST;
    case APOLLO_J: return APOLLO_J_RCS_THRUST;
    case APOLLO_MKII: return APOLLO_MKII_RCS_THRUST;
    case APOLLO_MKIII: return APOLLO_MKIII_RCS_THRUST;
    }
  return 0;
  }

Byte Lander::Vehicle() {
  return vehicle;
  }

