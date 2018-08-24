#ifndef _GCLOCKS_H
#define _GCLOCKS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Clocks : public Gauge {
  protected:
    UInt32 lastClockUt;
    UInt32 lastClockMi;
    Int32 lastClockBu;
    Int32 lastClockEv;
    Int32 lastClockDk;
  public:
    G_Clocks(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Clocks();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
