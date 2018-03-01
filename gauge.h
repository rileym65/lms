#ifndef _GAUGE_H
#define _GAUGE_H

class Vehicle;

class Gauge {
  protected:
    Int8    x;
    Int8    y;
    Int8    width;
    Int8    height;
    Boolean framed;
    Vehicle* vehicle;
  public:
    Gauge(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~Gauge();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
  };
    
#endif
