#ifndef _GDEC_H
#define _GDEC_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Declination : public Gauge {
  protected:
  public:
    G_Declination(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Declination();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
