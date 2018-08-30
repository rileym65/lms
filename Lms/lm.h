#ifndef _LUNARMODULE_H
#define _LUNARMODULE_H

#include "vector.h"
#include "vehicle.h"
#include "spacecraft.h"

class LunarModule : public Spacecraft {
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
    Double ascentDryWeight;
    Double descentDryWeight;
    Double ascentIsp;
    Double descentIsp;
    Double rcsIsp;
    Double ascentNewtons;
    Double descentNewtons;
    Double rcsNewtons;
    Double ascentFuelRate;
    Double descentFuelRate;
    Double rcsFuelRate;
    Double maxAscentFuel;
    Double maxDescentFuel;
    Double maxRcsFuel;
    Double maxAscentBattery;
    Double maxAscentEBattery;
    Double maxAscentOxygen;
    Double maxAscentEOxygen;
    Double maxDescentBattery;
    Double maxDescentEBattery;
    Double maxDescentOxygen;
    Double maxDescentEOxygen;
  public:
    LunarModule();
    virtual ~LunarModule();
    virtual void   Abort();
    virtual Double AscentFuel();
    virtual Double AscentFuel(Double d);
    virtual Double AscentOxygen();
    virtual Double AscentOxygen(Double d);
    virtual Double AscentBattery();
    virtual Double AscentBattery(Double d);
    virtual Double AscentDryWeight(Double d);
    virtual Double AscentIsp(Double d);
    virtual Double AscentNewtons(Double d);
    virtual Double DescentOxygen();
    virtual Double DescentOxygen(Double d);
    virtual Double DescentBattery();
    virtual Double DescentBattery(Double d);
    virtual Double AscentEOxygen();
    virtual Double AscentEOxygen(Double d);
    virtual Double AscentEBattery();
    virtual Double AscentEBattery(Double d);
    virtual Double DescentEOxygen();
    virtual Double DescentEOxygen(Double d);
    virtual Double DescentEBattery();
    virtual Double DescentEBattery(Double d);
    virtual Double DescentDryWeight(Double d);
    virtual Double DescentIsp(Double d);
    virtual Double DescentNewtons(Double d);
    virtual Double RcsIsp(Double d);
    virtual Double RcsNewtons(Double d);
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
    virtual Double MaxAscentFuel();
    virtual Double MaxAscentFuel(Double d);
    virtual Double MaxDescentFuel();
    virtual Double MaxDescentFuel(Double d);
    virtual Double MaxRcsFuel();
    virtual Double MaxRcsFuel(Double d);
    virtual Double MaxAscentBattery();
    virtual Double MaxAscentBattery(Double d);
    virtual Double MaxAscentEBattery();
    virtual Double MaxAscentEBattery(Double d);
    virtual Double MaxAscentOxygen();
    virtual Double MaxAscentOxygen(Double d);
    virtual Double MaxAscentEOxygen();
    virtual Double MaxAscentEOxygen(Double d);
    virtual Double MaxDescentBattery();
    virtual Double MaxDescentBattery(Double d);
    virtual Double MaxDescentEBattery();
    virtual Double MaxDescentEBattery(Double d);
    virtual Double MaxDescentOxygen();
    virtual Double MaxDescentOxygen(Double d);
    virtual Double MaxDescentEOxygen();
    virtual Double MaxDescentEOxygen(Double d);
    virtual Double Oxygen();
    virtual void   ProcessKey(Int32 key);
    virtual Double RcsFuel();
    virtual Double RcsFuel(Double d);
    virtual Int16  Rock();
    virtual Int16  Rock(Int16 i);
    virtual void   Save(FILE* file);
    virtual Int8   SubLoad(FILE* file, char* line);
    virtual Boolean UseBattery(Double units);
    virtual Boolean UseOxygen(Double units);
    virtual Double Value();
    virtual Double Value(Double d);
  };

#endif

