#ifndef _GCLOCKTE_H
#define _GCLOCKTE_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_ClockTE : public Gauge {
  protected:
    Int32 lastClock;
  public:
    G_ClockTE(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_ClockTE();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
