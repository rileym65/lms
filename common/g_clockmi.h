#ifndef _GCLOCKMI_H
#define _GCLOCKMI_H

#include "types.h"
#include "gauge.h"

#ifdef MAIN
UInt32 clockMi;
#else
extern UInt32 clockMi;
#endif

class Vehicle;

class G_ClockMI : public Gauge {
  protected:
    UInt32 lastClock;
  public:
    G_ClockMI(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockMI();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
