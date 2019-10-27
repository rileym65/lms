#ifndef _PANEL_H
#define _PANEL_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class Panel {
  protected:
    char   screen[24][81];
    Gauge* gauges[100];
    UInt8  numGauges;
    Vehicle* vehicle;
    void   addGauge(Gauge* g);
    void   clearPanel();
    Int8   loadFile(const char* filename);
    void   useDefault(const char* filename);
  public:
    Panel(const char* filename,Vehicle* v);
    ~Panel();
    void Box(UInt8 x1,UInt8 y1,UInt8 x2,UInt8 y2);
    void HLine(UInt8 x1,UInt8 y1,UInt8 x2);
    void Label(UInt8 x,UInt8 y,const char* label);
    void ResetPanel(const char* filename);
    void VLine(UInt8 x1,UInt8 y1,UInt8 y2);
    void Display();
    void Update();
    void Reset();
    virtual void   ProcessKey(Int32 key);
    virtual void      Save(FILE* file);
    virtual void      Load(FILE* file);
  };

#endif

