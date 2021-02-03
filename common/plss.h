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
    Double walked;
    Int8    damageReportStep;
    Double  oxygenLeakage;
    UInt32  cart;
    SAMPLE  samples[10];
    SAMPLE  sample;
  public:
    Plss();
    virtual ~Plss();
    virtual void Init();
    virtual void Cycle();
    virtual Boolean AddToCart(SAMPLE s);
    virtual SAMPLE  TakeFromCart();
    virtual void   BeginEva(Vehicle* from);
    virtual char   Carrying();
    virtual char   Carrying(char c);
    virtual UInt32 Cart();
    virtual UInt32 Cart(UInt32 i);
    virtual Double CartValue();
    virtual void   Damage(Double dmg);
    virtual Boolean DuplicateSample(SAMPLE s);
    virtual Int8   SubLoad(FILE* file, char* line);
    virtual SAMPLE Sample();
    virtual SAMPLE Sample(SAMPLE s);
    virtual void   Save(FILE* file);
    virtual void   ProcessKey(Int32 key);
    virtual Double Walked();
    virtual Double Walked(Double d);
    virtual Boolean   UseOxygen(Double units);
  };

#endif
