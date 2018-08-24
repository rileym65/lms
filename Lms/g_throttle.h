#ifndef _GTHROTTLE_H
#define _GTHROTTLE_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Throttle : public Gauge {
  protected:
    Int16 lastThrottle;
  public:
    G_Throttle(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Throttle();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
