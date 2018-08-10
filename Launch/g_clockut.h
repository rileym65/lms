#ifndef _GCLOCKUT_H
#define _GCLOCKUT_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_ClockUT : public Gauge {
  protected:
    UInt32 lastClock;
  public:
    G_ClockUT(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockUT();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
