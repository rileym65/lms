#ifndef _GPROPELLANT_H
#define _GPROPELLANT_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Propellant : public Gauge {
  protected:
  public:
    G_Propellant(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Propellant();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
