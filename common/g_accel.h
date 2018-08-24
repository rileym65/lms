#ifndef _GACCEL_H
#define _GACCEL_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Accel : public Gauge {
  protected:
    Double lastVelocity;
  public:
    G_Accel(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Accel();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
