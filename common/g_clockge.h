#ifndef _GCLOCKGE_H
#define _GCLOCKGE_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_ClockGE : public Gauge {
  protected:
    Int32 lastClock;
  public:
    G_ClockGE(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockGE();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
