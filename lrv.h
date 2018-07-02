#ifndef _LRV_H
#define _LRV_H

#include <stdio.h>
#include "types.h"
#include "groundvehicle.h"
#include "plss.h"

class Lrv : public GroundVehicle {
  protected:
    Boolean isSetup;
    Int8    boxes;
    Int8    rock;
    Double  value;
    Double  driven;
    Int8    damageReportStep;
  public:
    Lrv();
    virtual ~Lrv();
    virtual void Init();
    virtual void Cycle();
    virtual Boolean IsSetup();
    virtual void   Setup();
    virtual Int8   Boxes();
    virtual Int8   Boxes(Int8 i);
    virtual Double Driven();
    virtual Int8   Rock();
    virtual Int8   Rock(Int8 i);
    virtual Int8   SubLoad(char* line);
    virtual void   Save(FILE* file);
    virtual void   ProcessKey(Int32 key);
    virtual Double Value();
    virtual Double Value(Double d);
  };

#endif
