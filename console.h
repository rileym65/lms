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
    Int8  lastDockingRadarPosX;
    Int8  lastDockingRadarPosY;
    Int8  lastDockingRadarAngX;
    Int8  lastDockingRadarAngY;
    Int8  lastDockingRadarRolX;
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
    Double faceD, leftD, upD;
    Int8  lastYawRate;
    Double priorAltitude;
    Double priorVelAltitude;
    Double priorVelEast;
    Double priorVelNorth;
    Int16 rightFaceX, rightFaceY;
    Int16 rightLeftX, rightLeftY;
    Int16 rightUpX, rightUpY;
    void displayClock(Int32 x, Int32 y, Int32 clock);
    void displayFaces(Int8 x, Int8 y, char side);
  public:
    Console();
    ~Console();
    void Reset();
    void DisplayAtt(Int8 x,Int8 y);
    void DisplayClocks(Int8 x,Int8 y);
    void DisplayCons(Int8 x, Int8 y);
    void DisplayDockingRadar(Int8 x, Int8 y);
    void DisplayIns(Int8 x,Int8 y);
    void DisplayWestAxis(Int8 x, Int8 y, Vehicle *vehicle);
    void DisplayLm(Int8 x, Int8 y);
    void DisplayLrv(Int8 x, Int8 y);
    void DisplayPilot(Int8 x, Int8 y);
    void DisplayPlss(Int8 x, Int8 y);
    void DisplayDownAxis(Int8 x, Int8 y, Vehicle * vehicle);
    void DisplaySeq(Int8 x,Int8 y);
    void DisplaySpin(Int8 x,Int8 y);
    void DisplayStatus(Int8, Int8 y);
    void DrawAtt(Int8 x,Int8 y);
    void DrawClocks(Int8 x, Int8 y);
    void DrawCons(Int8 x,Int8 y);
    void DrawDockingRadar(Int8 x, Int8 y);
    void DrawDownAxis(Int8 x, Int8 y);
    void DrawInd(Int8 x, Int8 y);
    void DrawIns(Int8 x, Int8 y);
    void DrawLandingRadar(Int8 x, Int8 y);
    void DrawLm(Int8 x, Int8 y);
    void DrawLrv(Int8 x, Int8 y);
    void DrawPilot(Int8 x, Int8 y);
    void DrawPlss(Int8 x, Int8 y);
    void DrawSpin(Int8 x,Int8 y);
    void DrawStatus(Int8 x,Int8 y);
    void DrawWestAxis(Int8 x, Int8 y);
  };

#endif
