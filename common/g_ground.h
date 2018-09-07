#ifndef _GGROUND_H
#define _GGROUND_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Ground : public Gauge {
  protected:
  public:
    G_Ground(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Ground();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
