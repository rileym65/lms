#ifndef _GRADIAL_H
#define _GRADIAL_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Radial : public Gauge {
  protected:
  public:
    G_Radial(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Radial();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
