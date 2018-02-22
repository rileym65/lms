#ifndef _GAMSLM_H
#define _GAMSLM_H

#include "types.h"
#include "gauge.h"

class G_AmsLm : public Gauge {
  protected:
    Int16 lastRock;
  public:
    G_AmsLm(Int8 x,Int8 y,Boolean f);
    virtual ~G_AmsLm();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
