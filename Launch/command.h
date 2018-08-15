#ifndef _COMMAND_H
#define _COMMAND_H

#include "vehicle.h"
#include "spacecraft.h"
#include "booster.h"

class CommandModule : public Spacecraft {
  protected:
    Double   area;
    Booster* launchVehicle;
    Boolean  launchVehicleJettisoned;
    Double   parachuteArea;
    Double   parachuteDeployment;
    Double   serviceModuleDryWeight;
    Double   serviceModuleFuel;
    Double   serviceModuleIsp;
    Double   serviceModuleThrust;
    Double   serviceModuleRcsIsp;
    Double   serviceModuleRcsThrust;
    void     capsuleSep();
  public:
    CommandModule();
    ~CommandModule();
    void Cycle();
    virtual Double AscendingNode();
    virtual Double Apoapsis();
    virtual void   Diameter(Double d);
    virtual Byte   EnginesLit();
    virtual Double Inclination();
    virtual Double Mass();
    virtual Byte   NumEngines();
    virtual Byte   NumEngines(Byte stage);
    virtual Byte   NumEngines(Byte stage, Byte b);
    virtual Double Fuel();
    virtual Double MaxFuel();
    virtual Byte   NumStages();
    virtual Double OrbitTime();
    virtual Double ParachuteDeployment();
    virtual void   ParachuteDiameter(Double d);
    virtual Double PitchRate();
    virtual Double Periapsis();
    virtual Double Radius();
    virtual Double Radius(Double d);
    virtual Double RateOfClimb();
    virtual Double RollRate();
    virtual Double ServiceModuleDryWeight(Double d);
    virtual Double ServiceModuleFuel(Double d);
    virtual Double ServiceModuleIsp(Double d);
    virtual Double ServiceModuleThrust(Double d);
    virtual Double ServiceModuleRcsIsp(Double d);
    virtual Double ServiceModuleRcsThrust(Double d);
    virtual Double YawRate();

    virtual Booster* LaunchVehicle();
    virtual Booster* LaunchVehicle(Booster* lv);
    virtual Boolean  LaunchVehicleJettisoned();
    virtual Boolean  LaunchVehicleJettisoned(Boolean b);
    virtual void   ProcessKey(Int32 key);
    virtual Byte   Stage();
    virtual void     Save(FILE* file);
    virtual Int8   SubLoad(FILE* file, char* pline);
  };

#endif

