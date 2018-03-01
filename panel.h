#ifndef _PANEL_H
#define _PANEL_H

#include "gauge.h"

class Vehicle;

class Panel {
  protected:
    char   screen[24][81];
    Gauge* gauges[100];
    Int8   numGauges;
    Vehicle* vehicle;
    void   addGauge(Gauge* g);
    Int8   loadFile(const char* filename);
    void   useDefault(const char* filename);
  public:
    Panel(const char* filename,Vehicle* v);
    ~Panel();
    void Box(Int8 x1,Int8 y1,Int8 x2,Int8 y2);
    void HLine(Int8 x1,Int8 y1,Int8 x2);
    void Label(Int8 x,Int8 y,const char* label);
    void VLine(Int8 x1,Int8 y1,Int8 y2);
    void Display();
    void Update();
    void Reset();
  };

#endif

