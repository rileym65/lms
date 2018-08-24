#ifndef _GOXYBAT_H
#define _GOXYBAT_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_OxyBat : public Gauge {
  protected:
    Int16 lastOxygen;
    Int16 lastBattery;
  public:
    G_OxyBat(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_OxyBat();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
