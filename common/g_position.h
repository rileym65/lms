#ifndef _GPOSITION_H
#define _GPOSITION_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Position : public Gauge {
  protected:
  public:
    G_Position(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Position();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
