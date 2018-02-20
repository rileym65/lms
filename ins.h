#ifndef _INS_H
#define _INS_H

class INS {
  protected:
    Double accAltitude;
    Double accEast;
    Double accNorth;
    Double apolune;
    Double attUr;
    Double attFr;
    Double attLs;
    char   displayAccAltitude[16];
    char   displayAccEast[16];
    char   displayAccNorth[16];
    char   displayPosAltitude[16];
    char   displayPosEast[16];
    char   displayPosNorth[16];
    char   displayVelAltitude[16];
    char   displayVelEast[16];
    char   displayVelNorth[16];
    char   displayApolune[16];
    char   displayPerilune[16];
    char   displayMomEast[16];
    char   displayMomNorth[16];
    Double lastVelAltitude;
    Double lastVelEast;
    Double lastVelNorth;
    Int8     mode;
    Double   momEast;
    Double   momNorth;
    Double   orbitTime;
    Double   perilune;
    Double   relAccAltitude;
    Double   relAccEast;
    Double   relAccNorth;
    Double   relAltitude;
    Vector   relPos;
    Vector   relVel;
    Double   relLongitude;
    Double   relLatitude;
    Double   tarLongitude;
    Double   tarLatitude;
    Vehicle* spacecraft;
    Vehicle* target;
    Boolean  hasSignal();
    void     noData();
    void     populatePosAbs();
    void     populatePosTar();
    void     populatePosRel();
    void     populateOrbAbs();
    void     populateOrbTar();
    void     printVelocity(Double v,char* buffer);
  public:
    INS();
    ~INS();
    void     Cycle();
    Double   AttUr();
    Double   AttFr();
    Double   AttLs();
    char*    DisplayAccAltitude();
    char*    DisplayAccEast();
    char*    DisplayAccNorth();
    char*    DisplayPosAltitude();
    char*    DisplayPosEast();
    char*    DisplayPosNorth();
    char*    DisplayVelAltitude();
    char*    DisplayVelEast();
    char*    DisplayVelNorth();
    char*    DisplayApolune();
    char*    DisplayPerilune();
    char*    DisplayMomEast();
    char*    DisplayMomNorth();
    Int8     Mode();
    Int8     Mode(Int8 i);
    Vector   RelPos();
    Vector   RelVel();
    void     Reset();
    Vehicle* Spacecraft();
    Vehicle* Spacecraft(Vehicle* v);
    Vehicle* Target();
    Vehicle* Target(Vehicle* v);
  };

#endif

