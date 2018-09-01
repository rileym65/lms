#ifndef _GAMSINS_H
#define _GAMSINS_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsIns : public Gauge {
  protected:
    Byte  mode;
    Int16 lastInsMode;
  public:
    G_AmsIns(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsIns();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
    virtual void ProcessKey(Int32 key);
    virtual void Load(FILE* file,char* firstLine);
    virtual void Save(FILE* file);
  };

#endif
