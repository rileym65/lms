#ifndef _GMOON_H
#define _GMOON_H

#include "types.h"
#include "gauge.h"
#include "body.h"

class Vehicle;

class G_Moon : public Gauge {
  protected:
  public:
    G_Moon(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Moon();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
