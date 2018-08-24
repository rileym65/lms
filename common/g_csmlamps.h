#ifndef _GCSMLAMPS_H
#define _GCSMLAMPS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_CsmLamps : public Gauge {
  protected:
  public:
    G_CsmLamps(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_CsmLamps();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
