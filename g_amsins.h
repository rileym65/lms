#ifndef _GAMSINS_H
#define _GAMSINS_H

#include "types.h"
#include "gauge.h"

class G_AmsIns : public Gauge {
  protected:
    Int16 lastInsMode;
  public:
    G_AmsIns(Int8 x,Int8 y,Boolean f);
    virtual ~G_AmsIns();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
