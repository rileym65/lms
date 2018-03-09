#ifndef _GPRECAXIS_H
#define _GPRECAXIS_H

#include "types.h"
#include "gauge.h"
#include "g_axis.h"

class Vehicle;

class G_PrecAxis : public G_Axis {
  protected:
    Int8 mode;
    void modeAbs();
    void modeDown();
    void modePrograde();
    void modeWest();
  public:
    G_PrecAxis(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_PrecAxis();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
    virtual void ProcessKey(Int32 key);
  };

#endif
