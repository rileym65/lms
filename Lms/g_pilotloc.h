#ifndef _GPILOTLOCATION_H
#define _GPILOTLOCATION_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_PilotLocation : public Gauge {
  protected:
    char lastLocation;
  public:
    G_PilotLocation(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_PilotLocation();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
