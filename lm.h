#ifndef _LUNARMODULE_H
#define _LUNARMODULE_H

#include "vector.h"
#include "vehicle.h"

class LunarModule : public Vehicle {
  protected:
    Double ascentFuel;
    Double descentFuel;
    Int8   descentJettisoned;
    Int8   landed;
    Double rcsFuel;
    Int16  rock;
    Double value;
    Double rcsRotationFuelUsage();
    Double ascentBatteryLeakage;
    Double ascentOxygenLeakage;
    Double ascentFuelLeakage;
    Double rcsFuelLeakage;
    Double ascentEngineEfficiency;
    Double descentBatteryLeakage;
    Double descentOxygenLeakage;
    Double descentFuelLeakage;
    Double descentEngineEfficiency;
    Int8   damageReportStep;
  public:
    LunarModule();
    virtual ~LunarModule();
    virtual void   Abort();
    virtual Double AscentFuel();
    virtual Double AscentFuel(Double d);
    virtual void   Cycle();
    virtual Double DescentFuel();
    virtual Double DescentFuel(Double d);
    virtual Int8   DescentJettisoned();
    virtual void   InitPanel();
    virtual Int8   Landed();
    virtual Double Mass();
    virtual void   ProcessKey(Int32 key);
    virtual Double RcsFuel();
    virtual Double RcsFuel(Double d);
    virtual Int16  Rock();
    virtual Int16  Rock(Int16 i);
    virtual void   Save(FILE* file);
    virtual Int8   SubLoad(char* line);
    virtual Double Value();
    virtual Double Value(Double d);
  };

#endif

