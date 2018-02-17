#ifndef _CONSOLE_H
#define _CONSOLE_H

#include "types.h"

class Console {
  protected:
    Int32 lastAltitude;
    Int8  lastAscentFuel;
    Int8  lastCabinPressurized;
    Int32 lastClockBu;
    Int32 lastClockDk;
    Int32 lastClockEv;
    Int32 lastClockMi;
    Int32 lastClockOr;
    Int32 lastClockUt;
    Int8  lastDescentFuel;
    Int8  lastDocked;
    Int8  lastDockingRadarOn;
    Int8  lastDsnOn;
    Int8  lastEfficiency;
    Int16 lastFr;
    Int8  lastInjury;
    Int8  lastInsMode;
    Int8  lastLanded;
    Int8  lastLandingRadarOn;
    Int8  lastLmBattery;
    Int8  lastLmOxygen;
    Int16 lastLmRock;
    Int8  lastLrvBattery;
    Int8  lastLrvRock;
    Int16 lastLs;
    char  lastMessage[32];
    Int8  lastMetabolicRate;
    char  lastPilotLocation;
    Int8  lastPitchRate;
    Int8  lastPlssOn;
    Int8  lastPlssBattery;
    Int8  lastPlssOxygen;
    Int8  lastPlssPacks;
    char  lastRcsFbMode;
    char  lastRcsLrMode;
    char  lastRcsUdMode;
    Int8  lastRcsFuel;
    Int8  lastRcsThrottle;
    Int8  lastRollRate;
    Int8  lastSampleBoxes;
    Int32 lastSeqTime;
    Int8  lastSpaceSuitOn;
    Int8  lastThrottle;
    Int16 lastUr;
    Int16 leftFaceX, leftFaceY;
    Int16 leftLeftX, leftLeftY;
    Int16 leftUpX, leftUpY;
    Int8  lastYawRate;
    void  displayClock(Int32 x, Int32 y, Int32 clock);
    void  displayIns(Vehicle *vehicle,Vehicle* target);
    void  displayLeftAxis(Vehicle *vehicle);
    void  displayRightAxis(Vehicle * vehicle);
    Double priorAltitude;
    Double priorVelAltitude;
    Double priorVelEast;
    Double priorVelNorth;
    Int16 rightFaceX, rightFaceY;
    Int16 rightLeftX, rightLeftY;
    Int16 rightUpX, rightUpY;
  public:
    Console();
    ~Console();
    void UpdateConsole();
  };

#endif
