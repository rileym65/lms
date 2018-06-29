#ifndef _GAMSMULTIAXIS_H
#define _GAMSMULTIAXIS_H

#include "types.h"
#include "gauge.h"
#include "g_axis.h"

class Vehicle;

class G_MultiAxis : public G_Axis {
  protected:
    Int8 mode;
    void modeAbs();
    void modeDown();
    void modePrograde();
    void modeWest();
  public:
    G_MultiAxis(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_MultiAxis();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
    virtual void ProcessKey(Int32 key);
    virtual void Load(FILE* file,char* firstLine);
    virtual void Save(FILE* file);
  };

#endif
