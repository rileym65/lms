#ifndef _GAMSCLOCKS_H
#define _GAMSCLOCKS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsClocks : public Gauge {
  protected:
    UInt32 lastClockUt;
    UInt32 lastClockMi;
    Int32 lastClockBu;
    Int32 lastClockEv;
    Int32 lastClockDk;
    Int32 lastClockOr;
  public:
    G_AmsClocks(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsClocks();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
