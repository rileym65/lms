#ifndef _GROUNDVEHICLE_H
#define _GROUNDVEHICLE_H

#include <stdio.h>
#include "types.h"
#include "vehicle.h"

class GroundVehicle : public Vehicle {
  protected:
    Double heading;
  public:
    GroundVehicle();
    virtual ~GroundVehicle();
    virtual void Init();
    virtual void Cycle();
    virtual Double Heading();
    virtual Double Heading(Double d);
    virtual void Place(Vector pos);
    virtual Int8 SubLoad(char* line);
    virtual void Save(FILE* file);
  };

#endif
