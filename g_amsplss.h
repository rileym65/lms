#ifndef _GAMSPLSS_H
#define _GAMSPLSS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsPlss : public Gauge {
  protected:
    Int16 lastOxygen;
    Int16 lastBattery;
    Int16 lastPacks;
    char  lastCarrying;
  public:
    G_AmsPlss(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsPlss();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
  };

#endif
