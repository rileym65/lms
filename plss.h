#ifndef _PLSS_H
#define _PLSS_H

#include <stdio.h>
#include "types.h"
#include "vehicle.h"
#include "groundvehicle.h"
#include "plss.h"

class Plss : public GroundVehicle {
  protected:
    char   carrying;
    Double value;
    Double walked;
  public:
    Plss();
    virtual ~Plss();
    virtual void Init();
    virtual void Cycle();
    virtual void   BeginEva(Vehicle* from);
    virtual char   Carrying();
    virtual char   Carrying(char c);
    virtual Int8   SubLoad(char* line);
    virtual void   Save(FILE* file);
    virtual void   ProcessKey(Int32 key);
    virtual Double Value();
    virtual Double Value(Double d);
    virtual Double Walked();
  };

#endif
