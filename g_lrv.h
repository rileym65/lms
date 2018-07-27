#ifndef _GLRV_H
#define _GLRV_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Lrv : public Gauge {
  protected:
    Int16 lastOxygen;
    Int16 lastBattery;
    Int16 lastSampleBoxes;
    Int16 lastRock;
    Boolean lastSetup;
  public:
    G_Lrv(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Lrv();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
