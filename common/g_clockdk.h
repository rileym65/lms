#ifndef _GCLOCKDK_H
#define _GCLOCKDK_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_ClockDK : public Gauge {
  protected:
    Int32 lastClock;
  public:
    G_ClockDK(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockDK();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
