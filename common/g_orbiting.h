#ifndef _GORBITING_H
#define _GORBITING_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Orbiting : public Gauge {
  protected:
  public:
    G_Orbiting(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Orbiting();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
