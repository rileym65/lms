#ifndef _GCSMDOCK_H
#define _GCSMDOCK_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_CsmDock : public Gauge {
  protected:
    Double lastPx;
    Double lastPy;
    Int16 lastPosX;
    Int16 lastPosY;
    Int16 lastDockingRadarRoll;
    Int16 lastDockingRadarPitch;
    Int16 lastDockingRadarYaw;
  public:
    G_CsmDock(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_CsmDock();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
