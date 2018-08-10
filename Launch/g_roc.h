#ifndef _GROC_H
#define _GROC_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Roc : public Gauge {
  protected:
    Double lastAltitude;
  public:
    G_Roc(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Roc();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
