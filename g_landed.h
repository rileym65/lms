#ifndef _GLANDED_H
#define _GLANDED_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Landed : public Gauge {
  protected:
    Int16 lastLanded;
  public:
    G_Landed(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Landed();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
