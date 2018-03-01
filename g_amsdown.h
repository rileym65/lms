#ifndef _GAMSDOWN_H
#define _GAMSDOWN_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsDown : public Gauge {
  protected:
    Int16 rightFaceX, rightFaceY;
    Int16 rightLeftX, rightLeftY;
    Int16 rightUpX, rightUpY;
    Double faceD, leftD, upD;
  public:
    G_AmsDown(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsDown();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
