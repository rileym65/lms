#ifndef _GROLLRATE_H
#define _GROLLRATE_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_RollRate : public Gauge {
  protected:
  public:
    G_RollRate(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_RollRate();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
