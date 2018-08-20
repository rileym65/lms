#ifndef _GRA_H
#define _GRA_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_RightAscension : public Gauge {
  protected:
  public:
    G_RightAscension(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_RightAscension();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
