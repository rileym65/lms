#ifndef _GPITCHRATE_H
#define _GPITCHRATE_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_PitchRate : public Gauge {
  protected:
  public:
    G_PitchRate(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_PitchRate();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
