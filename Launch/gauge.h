#ifndef _GAUGE_H
#define _GAUGE_H
#include <stdio.h>
#include "terminal.h"

class Vehicle;

class Gauge {
  protected:
    Int8    x;
    Int8    y;
    Int8    width;
    Int8    height;
    Boolean framed;
    Vehicle* vehicle;
    void displayClock(Int32 cx, Int32 cy, Int32 clock);
  public:
    Gauge(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~Gauge();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
    virtual void ProcessKey(Int32 key);
    virtual void Load(FILE* file,char* firstLine);
    virtual void Save(FILE* file);
  };
    
#endif
