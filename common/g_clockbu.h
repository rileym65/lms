#ifndef _GCLOCKBU_H
#define _GCLOCKBU_H

#include "types.h"
#include "gauge.h"

#ifdef MAIN
UInt32 clockBu;
#else
extern UInt32 clockBu;
#endif

class Vehicle;

class G_ClockBU : public Gauge {
  protected:
    UInt32 lastClock;
  public:
    G_ClockBU(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockBU();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
