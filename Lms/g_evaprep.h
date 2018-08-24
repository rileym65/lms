#ifndef _GEVAPREP_H
#define _GEVAPREP_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_EvaPrep : public Gauge {
  protected:
    Int16 lastSpaceSuitOn;
    Int16 lastPlssOn;
    Int16 lastCabinPressurized;
    Int16 lastPacks;
  public:
    G_EvaPrep(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_EvaPrep();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
