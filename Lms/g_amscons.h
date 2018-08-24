#ifndef _GAMSCONS_H
#define _GAMSCONS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsCons : public Gauge {
  protected:
    Int16 lastAscentFuel;
    Int16 lastDescentFuel;
    Int16 lastRcsFuel;
    Int16 lastOxygen;
    Int16 lastBattery;
    Int16 lastThrottle;
    Int16 lastRcsThrottle;
  public:
    G_AmsCons(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsCons();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
