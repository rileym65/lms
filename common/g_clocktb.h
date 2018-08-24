#ifndef _GCLOCKTB_H
#define _GCLOCKTB_H

#include "types.h"
#include "gauge.h"

#ifdef MAIN
UInt32 clockTb;
#else
extern UInt32 clockTb;
#endif

class Vehicle;

class G_ClockTB : public Gauge {
  protected:
    UInt32 lastClock;
  public:
    G_ClockTB(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockTB();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
