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
    Double ascentOxygen;
    Double descentOxygen;
    Double ascentBattery;
    Double descentBattery;
    Double ascentEOxygen;
    Double descentEOxygen;
    Double ascentEBattery;
    Double descentEBattery;
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
    virtual Double AscentOxygen(Double d);
    virtual Double AscentBattery(Double d);
    virtual Double DescentOxygen(Double d);
    virtual Double DescentBattery(Double d);
    virtual Double AscentEOxygen(Double d);
    virtual Double AscentEBattery(Double d);
    virtual Double DescentEOxygen(Double d);
    virtual Double DescentEBattery(Double d);
    virtual Double Battery();
    virtual void   Cycle();
    virtual void   Damage(Double dmg);
    virtual Double DescentFuel();
    virtual Double DescentFuel(Double d);
    virtual Int8   DescentJettisoned();
    virtual Double EBattery();
    virtual Double EOxygen();
    virtual void   InitPanel();
    virtual Int8   Landed();
    virtual Double Mass();
    virtual Double Oxygen();
    virtual void   ProcessKey(Int32 key);
    virtual Double RcsFuel();
    virtual Double RcsFuel(Double d);
    virtual Int16  Rock();
    virtual Int16  Rock(Int16 i);
    virtual void   Save(FILE* file);
    virtual Int8   SubLoad(char* line);
    virtual Boolean UseBattery(Double units);
    virtual Boolean UseOxygen(Double units);
    virtual Double Value();
    virtual Double Value(Double d);
  };

#endif

