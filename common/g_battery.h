#ifndef _GBATTERY_H
#define _GBATTERY_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Battery : public Gauge {
  protected:
  public:
    G_Battery(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Battery();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
