#ifndef _GLMROCK_H
#define _GLMROCK_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_LmRock : public Gauge {
  protected:
    Int16 lastRock;
  public:
    G_LmRock(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_LmRock();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
