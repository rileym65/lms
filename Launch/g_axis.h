#ifndef _GAMSAXIS_H
#define _GAMSAXIS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Axis : public Gauge {
  protected:
    Int16 faceX, faceY;
    Int16 leftX, leftY;
    Int16 upX,   upY;
    Double faceD, leftD, upD;
    void  draw(Int32 fx,Int32 fy,Double fd,
               Int32 lx,Int32 ly,Double ld,
               Int32 ux,Int32 uy,Double ud);
  public:
    G_Axis(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Axis();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
  };

#endif
