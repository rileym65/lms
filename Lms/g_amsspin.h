#ifndef _GAMSSPIN_H
#define _GAMSSPIN_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsSpin : public Gauge {
  protected:
    Int16 lastPitchRate;
    Int16 lastRollRate;
    Int16 lastYawRate;
  public:
    G_AmsSpin(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsSpin();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
  };

#endif
