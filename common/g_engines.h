#ifndef _GENGINES_H
#define _GENGINES_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Engines : public Gauge {
  protected:
    Byte lastEnginesLit;
  public:
    G_Engines(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Engines();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
