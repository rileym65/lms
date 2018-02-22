#ifndef _GAMSSTAT_H
#define _GAMSSTAT_H

#include "types.h"
#include "gauge.h"

class G_AmsStatus : public Gauge {
  protected:
    Int16 lastSpaceSuitOn;
    Int16 lastPlssOn;
    Int16 lastCabinPressurized;
    Int16 lastLanded;
    Int16 lastDocked;
    Int16 lastLandingRadarOn;
    Int16 lastDockingRadarOn;
    Int16 lastDsnOn;
    Int16 lastMetabolicRate;
    Int16 lastEfficiency;
    Int16 lastInjury;
    char  lastRcsFbMode;
    char  lastRcsLrMode;
    char  lastRcsUdMode;
  public:
    G_AmsStatus(Int8 x,Int8 y,Boolean f);
    virtual ~G_AmsStatus();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
