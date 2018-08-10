#ifndef _GPERIAPSIS_H
#define _GPERIAPSIS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Periapsis : public Gauge {
  protected:
  public:
    G_Periapsis(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Periapsis();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
