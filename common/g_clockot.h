#ifndef _GCLOCKOT_H
#define _GCLOCKOT_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_ClockOT : public Gauge {
  protected:
    Int32 lastClock;
  public:
    G_ClockOT(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockOT();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
