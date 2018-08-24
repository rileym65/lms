#ifndef _GCLOCKOT_H
#define _GCLOCKOT_H

#include "types.h"
#include "gauge.h"

#ifdef MAIN
UInt32 clockOt;
#else
extern UInt32 clockOt;
#endif

class Vehicle;

class G_ClockOT : public Gauge {
  protected:
    UInt32 lastClock;
  public:
    G_ClockOT(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockOT();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
