#ifndef _GAMSLRV_H
#define _GAMSLRV_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsLrv : public Gauge {
  protected:
    Int16 lastBattery;
    Int16 lastSampleBoxes;
    Int16 lastRock;
    Boolean lastSetup;
  public:
    G_AmsLrv(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsLrv();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
