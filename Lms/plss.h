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
    Int8    damageReportStep;
    Double  oxygenLeakage;
    UInt32  cart;
    Double  cartValue;
  public:
    Plss();
    virtual ~Plss();
    virtual void Init();
    virtual void Cycle();
    virtual Boolean AddToCart(Double v);
    virtual void   BeginEva(Vehicle* from);
    virtual char   Carrying();
    virtual char   Carrying(char c);
    virtual UInt32 Cart();
    virtual UInt32 Cart(UInt32 i);
    virtual Double CartValue();
    virtual Double CartValue(Double d);
    virtual void   Damage(Double dmg);
    virtual Int8   SubLoad(FILE* file, char* line);
    virtual void   Save(FILE* file);
    virtual void   ProcessKey(Int32 key);
    virtual Double Value();
    virtual Double Value(Double d);
    virtual Double Walked();
    virtual Double Walked(Double d);
  };

#endif
