#ifndef _GAMSDOWN_H
#define _GAMSDOWN_H

#include "types.h"
#include "gauge.h"
#include "g_axis.h"

class Vehicle;

class G_AmsDown : public G_Axis {
  protected:
  public:
    G_AmsDown(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsDown();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
