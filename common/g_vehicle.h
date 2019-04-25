#ifndef _GVEHICLE_H
#define _GVEHICLE_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Vehicle : public Gauge {
  protected:
    Boolean displayed;
  public:
    G_Vehicle(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Vehicle();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
