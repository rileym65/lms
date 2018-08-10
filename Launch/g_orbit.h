#ifndef _GORBIT_H
#define _GORBIT_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Orbit : public Gauge {
  protected:
  public:
    G_Orbit(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Orbit();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
