#ifndef _GALTITUDE_H
#define _GALTITUDE_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Altitude : public Gauge {
  protected:
  public:
    G_Altitude(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Altitude();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
