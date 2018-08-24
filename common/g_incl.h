#ifndef _GINCL_H
#define _GINCL_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Incl : public Gauge {
  protected:
  public:
    G_Incl(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Incl();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
