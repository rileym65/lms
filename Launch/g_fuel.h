#ifndef _GFUEL_H
#define _GFUEL_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Fuel : public Gauge {
  protected:
  public:
    G_Fuel(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Fuel();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
