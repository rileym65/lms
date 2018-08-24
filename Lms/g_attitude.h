#ifndef _GATTITUDE_H
#define _GATTITUDE_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Attitude : public Gauge {
  protected:
    Int32 lastUr;
    Int32 lastFr;
    Int32 lastLs;
    Int32 lastUo;
    Int32 lastFo;
    Int32 lastLo;
  public:
    G_Attitude(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Attitude();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
