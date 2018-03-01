#ifndef _GRADARS_H
#define _GRADARS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Radars : public Gauge {
  protected:
    Int16 lastLandingRadarOn;
    Int16 lastDockingRadarOn;
    Int16 lastDsnOn;
  public:
    G_Radars(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Radars();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
