#ifndef _GPILOT_H
#define _GPILOT_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Pilot : public Gauge {
  protected:
    Int16 lastMetabolicRate;
    Int16 lastEfficiency;
    Int16 lastInjury;
  public:
    G_Pilot(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Pilot();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
