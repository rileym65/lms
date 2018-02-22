#ifndef _GAMSCLOCKS_H
#define _GAMSCLOCKS_H

#include "types.h"
#include "gauge.h"

class G_AmsClocks : public Gauge {
  protected:
    Int32 lastClockUt;
    Int32 lastClockMi;
    Int32 lastClockBu;
    Int32 lastClockEv;
    Int32 lastClockDk;
    Int32 lastClockOr;
    void displayClock(Int32 x, Int32 y, Int32 clock);
  public:
    G_AmsClocks(Int8 x,Int8 y,Boolean f);
    virtual ~G_AmsClocks();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
