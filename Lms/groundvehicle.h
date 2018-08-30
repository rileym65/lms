#ifndef _GROUNDVEHICLE_H
#define _GROUNDVEHICLE_H

#include <stdio.h>
#include "types.h"
#include "vehicle.h"

class GroundVehicle : public Vehicle {
  protected:
    Double altitude;
    Double heading;
    Double maxSpeed;
    Double radius;
    Int8   turnRate;
    Double  motorEfficiency;
    Double  batteryLeakage;
  public:
    GroundVehicle();
    virtual ~GroundVehicle();
    virtual void Init();
    virtual void Cycle();
    virtual Double Heading();
    virtual Double Heading(Double d);
    virtual Double MaxSpeed();
    virtual Double MaxSpeed(Double d);
    virtual void Place(Vector pos);
    virtual Double Radius();
    virtual Double Radius(Double d);
    virtual Int8 SubLoad(FILE* file, char* line);
    virtual void Save(FILE* file);
    virtual Int8 TurnRate();
    virtual Int8 TurnRate(Int8 i);
  };

#endif
