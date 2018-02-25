#ifndef _GMAPMED_H
#define _GMAPMED_H

#include "types.h"
#include "gauge.h"

class G_MapMed : public Gauge {
  protected:
    Int32 lastCellX;
    Int32 lastCellY;
    char  data[11][22];
  public:
    G_MapMed(Int8 x,Int8 y,Boolean f);
    virtual ~G_MapMed();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
