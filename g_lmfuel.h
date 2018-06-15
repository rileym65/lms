#ifndef _GLMFUEL_H
#define _GLMFUEL_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_LmFuel : public Gauge {
  protected:
    Int16 lastAscentFuel;
    Int16 lastDescentFuel;
    Int8  lastDescentJettisoned;
  public:
    G_LmFuel(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_LmFuel();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
