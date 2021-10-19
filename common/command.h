#ifndef _COMMAND_H
#define _COMMAND_H

#include "vehicle.h"
#include "spacecraft.h"
#include "booster.h"

class CsmComputer;

class CommandModule : public Spacecraft {
  protected:
    Double   area;
    Double   heat;
    Double   maxHeat;
    Boolean  armed;
    Booster* launchVehicle;
    Boolean  launchVehicleJettisoned;
    Double   parachuteArea;
    Double   parachuteDeployment;
    Double   commandModuleRcsIsp;
    Double   commandModuleRcsThrust;
    Double   commandModuleRcsFuel;
    Double   commandModuleRcsMaxFuel;
    Double   serviceModuleDryWeight;
    Double   serviceModuleFuel;
    Double   serviceModuleMaxFuel;
    Double   serviceModuleIsp;
    Double   serviceModuleThrust;
    Double   serviceModuleRcsIsp;
    Double   serviceModuleRcsUThrust;
    Double   serviceModuleRcsDThrust;
    Double   serviceModuleRcsLThrust;
    Double   serviceModuleRcsRThrust;
    Double   serviceModuleRcsFThrust;
    Double   serviceModuleRcsBThrust;
    Double   serviceModuleRcsFuel;
    Double   serviceModuleRcsMaxFuel;
    Double   retroModuleDryWeight;
    Double   retroModuleFuel;
    Double   retroModuleMaxFuel;
    Double   retroModuleIsp;
    Double   retroModuleThrust;
    CsmComputer* computer;
    void     capsuleSep();
  public:
    CommandModule();
    ~CommandModule();
    void Cycle();
    virtual Double AscendingNode();
    virtual Double Apoapsis();
    virtual Boolean Armed();
    virtual Double CommandModuleRcsIsp(Double d);
    virtual Double CommandModuleRcsThrust(Double d);
    virtual Double CommandModuleRcsFuel();
    virtual Double CommandModuleRcsFuel(Double d);
    virtual Double CommandModuleRcsMaxFuel();
    virtual Double CommandModuleRcsMaxFuel(Double d);
    virtual CsmComputer* Computer();
    virtual void   Cutoff();
    virtual Double DeltaV();
    virtual void   Diameter(Double d);
    virtual Byte   EnginesLit();
    virtual Double FuelUsed();
    virtual Double Heat();
    virtual void   Ignition();
    virtual Double Inclination();
    virtual void   Ins();
    virtual Double Isp();
    virtual void   Launch();
    virtual Double Mass();
    virtual Double MaxHeat();
    virtual Double MaxRcsFuel();
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
    virtual void   Prograde(Double maxRate);
    virtual Double Radius();
    virtual Double Radius(Double d);
    virtual Double RateOfClimb();
    virtual Double RateOfClimb(Double d);
    virtual Double RcsFuel();
    virtual Double RcsIsp();
    virtual void   Retrograde(Double maxRate);
    virtual Double RollRate();
    virtual Double RetroModuleDryWeight();
    virtual Double RetroModuleDryWeight(Double d);
    virtual Double RetroModuleFuel();
    virtual Double RetroModuleFuel(Double d);
    virtual Double RetroModuleMaxFuel();
    virtual Double RetroModuleMaxFuel(Double d);
    virtual Double RetroModuleIsp();
    virtual Double RetroModuleIsp(Double d);
    virtual Double RetroModuleThrust(Double d);
    virtual Double ServiceModuleDryWeight();
    virtual Double ServiceModuleDryWeight(Double d);
    virtual Double ServiceModuleFuel();
    virtual Double ServiceModuleFuel(Double d);
    virtual Double ServiceModuleMaxFuel();
    virtual Double ServiceModuleMaxFuel(Double d);
    virtual Double ServiceModuleIsp();
    virtual Double ServiceModuleIsp(Double d);
    virtual Double ServiceModuleThrust(Double d);
    virtual Double ServiceModuleRcsIsp(Double d);
    virtual Double ServiceModuleRcsThrust(Double d);
    virtual Double ServiceModuleRcsUThrust(Double d);
    virtual Double ServiceModuleRcsDThrust(Double d);
    virtual Double ServiceModuleRcsLThrust(Double d);
    virtual Double ServiceModuleRcsRThrust(Double d);
    virtual Double ServiceModuleRcsFThrust(Double d);
    virtual Double ServiceModuleRcsBThrust(Double d);
    virtual Double ServiceModuleRcsFuel();
    virtual Double ServiceModuleRcsFuel(Double d);
    virtual Double ServiceModuleRcsMaxFuel();
    virtual Double ServiceModuleRcsMaxFuel(Double d);
    virtual Int8   Throttle();
    virtual Double YawRate();

    virtual Booster* LaunchVehicle();
    virtual Booster* LaunchVehicle(Booster* lv);
    virtual Boolean  LaunchVehicleJettisoned();
    virtual Boolean  LaunchVehicleJettisoned(Boolean b);
    virtual void   ProcessKey(Int32 key);
    virtual Double rcsRotationFuelUsage();
    virtual void   Undock();
    virtual Byte   Stage();
    virtual void     Save(FILE* file);
    virtual Int8   SubLoad(FILE* file, char* pline);
  };

#endif

