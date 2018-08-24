#ifndef _GYAWRATE_H
#define _GYAWRATE_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_YawRate : public Gauge {
  protected:
  public:
    G_YawRate(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_YawRate();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
