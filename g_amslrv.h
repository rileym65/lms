#ifndef _GAMSLRV_H
#define _GAMSLRV_H

#include "types.h"
#include "gauge.h"

class G_AmsLrv : public Gauge {
  protected:
    Int16 lastBattery;
    Int16 lastSampleBoxes;
    Int16 lastRock;
  public:
    G_AmsLrv(Int8 x,Int8 y,Boolean f);
    virtual ~G_AmsLrv();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
