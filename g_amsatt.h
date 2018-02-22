#ifndef _GAMSATT_H
#define _GAMSATT_H

#include "types.h"
#include "gauge.h"

class G_AmsAtt : public Gauge {
  protected:
    Int16 lastUr;
    Int16 lastFr;
    Int16 lastLs;
  public:
    G_AmsAtt(Int8 x,Int8 y,Boolean f);
    virtual ~G_AmsAtt();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
