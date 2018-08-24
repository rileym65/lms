#ifndef _GLAMPS_H
#define _GLAMPS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Lamps : public Gauge {
  protected:
  public:
    G_Lamps(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Lamps();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
