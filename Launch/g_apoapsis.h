#ifndef _GAPOAPSIS_H
#define _GAPOAPSIS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Apoapsis : public Gauge {
  protected:
  public:
    G_Apoapsis(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Apoapsis();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
