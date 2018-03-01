#ifndef _GDOCKED_H
#define _GDOCKED_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Docked : public Gauge {
  protected:
    Int16 lastDocked;
  public:
    G_Docked(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Docked();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
