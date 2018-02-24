#ifndef _PLSS_H
#define _PLSS_H

#include <stdio.h>
#include "types.h"
#include "vehicle.h"
#include "groundvehicle.h"
#include "plss.h"

class Plss : public GroundVehicle {
  protected:
    Double oxygen;
    Double battery;
    char   carrying;
    Double value;
  public:
    Plss();
    virtual ~Plss();
    virtual void Init();
//    virtual void Cycle();
    virtual Double Battery();
    virtual Double Battery(Double d);
    virtual void   BeginEva(Vehicle* from);
    virtual char   Carrying();
    virtual char   Carrying(char c);
    virtual Double Oxygen();
    virtual Double Oxygen(Double d);
    virtual Int8   SubLoad(char* line);
    virtual void   Save(FILE* file);
    virtual void   ProcessKey(Int32 key);
  };

#endif
