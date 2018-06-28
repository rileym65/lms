#ifndef _GGROUNDINS_H
#define _GGROUNDINS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_GroundIns : public Gauge {
  protected:
    Int16 lastGroundInsMode;
    Int8  mode;
  public:
    G_GroundIns(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_GroundIns();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
    virtual void ProcessKey(Int32 key);
  };

#endif
