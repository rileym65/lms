#ifndef _GCLOCKTB_H
#define _GCLOCKTB_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_ClockTB : public Gauge {
  protected:
    Int32 lastClock;
  public:
    G_ClockTB(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockTB();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
