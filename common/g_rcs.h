#ifndef _GRCS_H
#define _GRCS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Rcs : public Gauge {
  protected:
    char  lastRcsFbMode;
    char  lastRcsLrMode;
    char  lastRcsUdMode;
    Int32 lastPitch;
    Int32 lastRoll;
    Int32 lastYaw;
    Int8  lastRotationThrottle;
    Int8  lastTranslationThrottle;
    Int16 lastRcsFuel;
  public:
    G_Rcs(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Rcs();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
