#ifndef _GAUGE_H
#define _GAUGE_H

class Gauge {
  protected:
    Int8    x;
    Int8    y;
    Int8    width;
    Int8    height;
    Boolean framed;
  public:
    Gauge(Int8 x,Int8 y,Boolean f);
    virtual ~Gauge();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
  };
    
#endif
