#ifndef _GAMSLANDH
#define _GAMSLANDH

#include "types.h"
#include "gauge.h"

class G_AmsLand : public Gauge {
  protected:
  public:
    G_AmsLand(Int8 x,Int8 y,Boolean f);
    virtual ~G_AmsLand();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
