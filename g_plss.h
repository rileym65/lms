#ifndef _GPLSS_H
#define _GPLSS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Plss : public Gauge {
  protected:
    Int16 lastOxygen;
    Int16 lastBattery;
    char  lastCarrying;
    Int16 lastEOxygen;
    Int16 lastEBattery;
  public:
    G_Plss(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Plss();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
  };

#endif
