#ifndef _GVELOCITY_H
#define _GVELOCITY_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Velocity : public Gauge {
  protected:
  public:
    G_Velocity(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Velocity();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
