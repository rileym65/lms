#ifndef _GPROGRADE_H
#define _GPROGRADE_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Prograde : public Gauge {
  protected:
  public:
    G_Prograde(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Prograde();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
