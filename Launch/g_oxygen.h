#ifndef _GOXYGEN_H
#define _GOXYGEN_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Oxygen : public Gauge {
  protected:
  public:
    G_Oxygen(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Oxygen();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
