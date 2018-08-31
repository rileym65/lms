#ifndef _GCLOCKEV_H
#define _GCLOCKEV_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_ClockEV : public Gauge {
  protected:
    Int32 lastClock;
  public:
    G_ClockEV(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockEV();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
