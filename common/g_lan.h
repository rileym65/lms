#ifndef _GLAN_H
#define _GLAN_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Lan : public Gauge {
  protected:
  public:
    G_Lan(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Lan();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
