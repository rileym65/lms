#ifndef _GAMSWEST_H
#define _GAMSWEST_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsWest : public Gauge {
  protected:
    Int16 leftFaceX, leftFaceY;
    Int16 leftLeftX, leftLeftY;
    Int16 leftUpX, leftUpY;
    Double faceD, leftD, upD;
  public:
    G_AmsWest(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsWest();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
