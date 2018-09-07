#ifndef _BOOSTER_H
#define _BOOSTER_H

#include "vehicle.h"
#include "spacecraft.h"

class Booster : public Spacecraft {
  protected:
    Double area[10];
    Double cmOffset;
    Double dryWeight[10];
    Byte   enginesLit;
    Double fuel[10];
    Double height;
    Double ispSl[10][10];
    Double ispVac[10][10];
    Double maxFuel[10];
    Byte   starts[10];
    Double payload;
    Byte   numEngines[10];
    Byte   numStages;
    Byte   stage;
    Double thrustSl[10][10];
    Double thrustVac[10][10];
    Int8   loadEngine(FILE* file, char* line, Byte e);
    Int8   loadStage(FILE* file, char* line);
  public:
    Booster();
    ~Booster();
    virtual Double CmOffset();
    virtual Double CmOffset(Double d);
    virtual void   Cutoff();
    virtual void   Cycle();
    virtual void   Diameter(Byte stage, Double d);
    virtual Double DryWeight(Byte stage);
    virtual Double DryWeight(Byte stage, Double d);
    virtual Byte   EnginesLit();
    virtual Double Fuel();
    virtual Double Fuel(Byte stage);
    virtual Double Fuel(Byte stage, Double d);
    virtual Double Height();
    virtual Double Height(Double d);
    virtual void   Ignition();
    virtual Double IspSl(Byte stage, Byte engine);
    virtual Double IspSl(Byte stage, Byte engine, Double d);
    virtual Double IspVac(Byte stage, Byte engine);
    virtual Double IspVac(Byte stage, Byte engine, Double d);
    virtual Double Mass();
    virtual Double MaxFuel();
    virtual Double MaxFuel(Byte stage);
    virtual Double MaxFuel(Byte stage, Double d);
    virtual void   NextStage();
    virtual Byte   NumEngines();
    virtual Byte   NumEngines(Byte stage);
    virtual Byte   NumEngines(Byte stage, Byte b);
    virtual Byte   NumStages();
    virtual Byte   NumStages(Byte b);
    virtual Double Payload();
    virtual Double Payload(Double d);
    virtual Byte   Stage();
    virtual Byte   Stage(Byte b);
    virtual Byte   Starts();
    virtual Byte   Starts(Byte stage);
    virtual Byte   Starts(Byte stage, Byte b);
    virtual Double ThrustSl(Byte stage, Byte engine);
    virtual Double ThrustSl(Byte stage, Byte engine, Double d);
    virtual Double ThrustVac(Byte stage, Byte engine);
    virtual Double ThrustVac(Byte stage, Byte engine, Double d);
    virtual void   ProcessKey(Int32 key);
    virtual void   Save(FILE* file);
    virtual Int8   SubLoad(FILE* file, char* pline);
  };

#endif

