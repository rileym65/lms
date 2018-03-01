#ifndef _GCLOCKS_H
#define _GCLOCKS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Clocks : public Gauge {
  protected:
    Int32 lastClockUt;
    Int32 lastClockMi;
    Int32 lastClockBu;
    Int32 lastClockEv;
    Int32 lastClockDk;
    void displayClock(Int32 x, Int32 y, Int32 clock);
  public:
    G_Clocks(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Clocks();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
