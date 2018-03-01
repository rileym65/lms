#ifndef _GAMSPILOT_H
#define _GAMSPILOT_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsPilot : public Gauge {
  protected:
    char lastPilotLocation;
  public:
    G_AmsPilot(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsPilot();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
  };

#endif
