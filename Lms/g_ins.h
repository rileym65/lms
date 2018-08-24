#ifndef _GINS_H
#define _GINS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Ins : public Gauge {
  protected:
    Int16 lastInsMode;
    void  displayClock(Int32 x, Int32 y, Int32 clock);
  public:
    G_Ins(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Ins();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
