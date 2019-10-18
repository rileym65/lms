#ifndef _LRV_H
#define _LRV_H

#include <stdio.h>
#include "types.h"
#include "groundvehicle.h"

class Lrv : public GroundVehicle {
  protected:
    Boolean isSetup;
    Int8    boxes;
    Int8    rock;
    Double  driven;
    Int8    damageReportStep;
    SAMPLE  samples[30];
  public:
    Lrv();
    virtual ~Lrv();
    virtual void Init();
    virtual void Cycle();
    virtual Boolean IsSetup();
    virtual void   Setup();
    virtual void   AddSample(SAMPLE s);
    virtual SAMPLE TakeSample();
    virtual Boolean DuplicateSample(SAMPLE s);
    virtual Int8   Boxes();
    virtual Int8   Boxes(Int8 i);
    virtual void   Damage(Double dmg);
    virtual Double Driven();
    virtual Int8   Rock();
    virtual Int8   SubLoad(FILE* file, char* line);
    virtual void   Save(FILE* file);
    virtual void   ProcessKey(Int32 key);
    virtual Double Value();
  };

#endif
