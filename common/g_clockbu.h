#ifndef _GCLOCKBU_H
#define _GCLOCKBU_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_ClockBU : public Gauge {
  protected:
    Int32 lastClock;
  public:
    G_ClockBU(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockBU();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
