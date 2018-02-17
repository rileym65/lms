#include "header.h"
#include "console.h"
#include "terminal.h"
#include "math.h"

Console::Console() {
  lastAltitude = -1;
  lastAscentFuel = 0;
  lastCabinPressurized = 2;
  lastClockBu = (999 * 3600);
  lastClockDk = (999 * 3600);
  lastClockEv = (999 * 3600);
  lastClockMi = (999 * 3600);
  lastClockOr = (999 * 3600);
  lastClockUt = (999 * 3600);
  lastDocked = 2;
  lastDockingRadarOn = 2;
  lastDsnOn = 2;
  lastEfficiency = 0;
  lastFr = -999;
  lastInjury = -1;
  lastLandingRadarOn = 2;
  lastLmBattery = 0;
  lastLmOxygen = 0;
  lastLmRock = -1;
  lastLrvBattery = 0;
  lastLrvRock = -1;
  lastLs = -999;
  strcpy(lastMessage,"");
  lastMetabolicRate = 0;
  lastPilotLocation = ' ';
  lastPitchRate = 99;
  lastPlssOn = 2;
  lastPlssBattery = 0;
  lastPlssPacks = 0;
  lastPlssOxygen = 0;
  lastRcsFbMode = 'x';
  lastRcsLrMode = 'x';
  lastRcsUdMode = 'x';
  lastRcsFuel = 0;
  lastRcsThrottle = 0;
  lastRollRate = 99;
  lastSeqTime = 0;
  lastThrottle = -99;
  lastUr = -999;
  lastSampleBoxes = 0;
  lastSpaceSuitOn = 1;
  lastYawRate = 99;
  priorAltitude = -1;
  priorVelAltitude = 0;
  priorVelEast = 0;
  priorVelNorth = 0;
  leftFaceX = 10;
  leftFaceY = 10;
  leftLeftX = 10;
  leftLeftY = 10;
  leftUpX = 10;
  leftUpY = 10;
  rightFaceX = 67;
  rightFaceY = 10;
  rightLeftX = 67;
  rightLeftY = 10;
  rightUpX = 67;
  rightUpY = 10;
  }

Console::~Console() {
  }

Double sgn(Double d) {
  if (d < 0) return -1;
  if (d > 0) return 1;
  return 0;
  }

void Console::displayClock(Int32 x, Int32 y, Int32 clock) {
  Int32 hours, minutes, seconds;
  hours = clock / 3600;
  clock -= (hours * 3600);
  minutes = clock / 60;
  seconds = clock - (minutes * 60);
  GotoXY(x, y);
  printf("%3d:%2d:%2d",hours,minutes,seconds);
  }

void Console::displayLeftAxis(Vehicle *vehicle) {
  Int8   i;
  Boolean flag;
  Double du,dl,df;
  Vector pos;
  Vector vel;
  Int32  dx[3], dy[3];
  Double d[3];
  char   c[3];
  char   tc;
  Int32  ti;
  Double td;
  pos = vehicle->Position().Norm();
  vel = vehicle->Velocity().Norm();
  GotoXY(leftFaceX, leftFaceY); printf(" ");
  GotoXY(leftLeftX, leftLeftY); printf(" ");
  GotoXY(leftUpX, leftUpY); printf(" ");
  /* ***** Face ***** */
  leftFaceX = 14 + ((vehicle->FaceFront().Dot(Vector(0,0,1))) * 10 + 0.5);
  leftFaceY = 10 - ((vehicle->FaceFront().Dot(pos)) * 5 + 0.5);
  df = vehicle->FaceFront().Dot(vel);
  /* ***** Left ***** */
  leftLeftX = 14 + ((vehicle->FaceLeft().Dot(Vector(0,0,1))) * 10 + 0.5);
  leftLeftY = 10 - ((vehicle->FaceLeft().Dot(pos)) * 5 + 0.5);
  dl = vehicle->FaceLeft().Dot(vel);
  /* ***** Up ***** */
  leftUpX = 14 + ((vehicle->FaceUp().Dot(Vector(0,0,1))) * 10 + 0.5);
  leftUpY = 10 - ((vehicle->FaceUp().Dot(pos)) * 5 + 0.5);
  du = vehicle->FaceUp().Dot(vel);
  dx[0] = leftFaceX; dy[0] = leftFaceY; d[0] = df;
  c[0] = (df <= 0) ? 'F' : 'f';
  dx[1] = leftLeftX; dy[1] = leftLeftY; d[1] = dl;
  c[1] = (dl <= 0) ? 'L' : 'l';
  dx[2] = leftUpX; dy[2] = leftUpY; d[2] = du;
  c[2] = (du <= 0) ? 'U' : 'u';
  flag = true;
  while (flag) {
    flag = false;
    for (i=0; i<2; i++)
      if (d[i] < d[i+1]) {
        ti = dx[i]; dx[i] = dx[i+1]; dx[i+1] = ti;
        ti = dy[i]; dy[i] = dy[i+1]; dy[i+1] = ti;
        tc = c[i]; c[i] = c[i+1]; c[i+1] = tc;
        td = d[i]; d[i] = d[i+1]; d[i+1] = td;
        flag = true;
        }
    }
  for (i=0; i<3; i++) {
    GotoXY(dx[i], dy[i]);
    printf("%c",c[i]);
    }
  }

void Console::displayRightAxis(Vehicle *vehicle) {
  Int8   i;
  Boolean flag;
  Double du,dl,df;
  Vector pos;
  Vector vel;
  Int32  dx[3], dy[3];
  Double d[3];
  char   c[3];
  char   tc;
  Int32  ti;
  Double td;
  pos = vehicle->Position().Norm();
  vel = vehicle->Velocity().Norm();
  GotoXY(rightFaceX, rightFaceY); printf(" ");
  GotoXY(rightLeftX, rightLeftY); printf(" ");
  GotoXY(rightUpX, rightUpY); printf(" ");
  /* ***** Face ***** */
  rightFaceX = 67 + ((vehicle->FaceFront().Dot(Vector(0,0,1))) * 10 + 0.5);
  rightFaceY = 10 - ((vehicle->FaceFront().Dot(vel)) * 5 + 0.5);
  df = vehicle->FaceFront().Dot(pos);
  /* ***** Left ***** */
  rightLeftX = 67 + ((vehicle->FaceLeft().Dot(Vector(0,0,1))) * 10 + 0.5);
  rightLeftY = 10 - ((vehicle->FaceLeft().Dot(vel)) * 5 + 0.5);
  dl = vehicle->FaceLeft().Dot(pos);
  /* ***** Up ***** */
  rightUpX = 67 + ((vehicle->FaceUp().Dot(Vector(0,0,1))) * 10 + 0.5);
  rightUpY = 10 - ((vehicle->FaceUp().Dot(vel)) * 5 + 0.5);
  du = vehicle->FaceUp().Dot(pos);
  dx[0] = rightFaceX; dy[0] = rightFaceY; d[0] = df;
  c[0] = (df >= 0) ? 'F' : 'f';
  dx[1] = rightLeftX; dy[1] = rightLeftY; d[1] = dl;
  c[1] = (dl >= 0) ? 'L' : 'l';
  dx[2] = rightUpX; dy[2] = rightUpY; d[2] = du;
  c[2] = (du >= 0) ? 'U' : 'u';
  flag = true;
  while (flag) {
    flag = false;
    for (i=0; i<2; i++)
      if (d[i] > d[i+1]) {
        ti = dx[i]; dx[i] = dx[i+1]; dx[i+1] = ti;
        ti = dy[i]; dy[i] = dy[i+1]; dy[i+1] = ti;
        tc = c[i]; c[i] = c[i+1]; c[i+1] = tc;
        td = d[i]; d[i] = d[i+1]; d[i+1] = td;
        flag = true;
        }
    }
  for (i=0; i<3; i++) {
    GotoXY(dx[i], dy[i]);
    printf("%c",c[i]);
    }
  }

void Console::displayIns(Vehicle* vehicle,Vehicle* target) {
  Int32  i;
  displayLeftAxis(vehicle);
  displayRightAxis(vehicle);
  i = (int)(ins->AttUr()+.4);
  if (lastUr != i) {
    GotoXY(6, 18); printf("%3d",i);
    lastUr = i;
    }
  i = (int)(ins->AttFr()+.4);
  if (lastFr != i) {
    GotoXY(6, 19); printf("%3d",i);
    lastFr = i;
    }
  i = (int)(ins->AttLs()+.4);
  if (lastLs != i) {
    GotoXY(6, 20); printf("%3d",i);
    lastLs = i;
    }
  if (ins->Mode() < 4) {
    GotoXY(29,18); printf("%7s",ins->DisplayPosAltitude());
    GotoXY(37,18); printf("%7s",ins->DisplayPosEast());
    GotoXY(45,18); printf("%7s",ins->DisplayPosNorth());
    GotoXY(29,19); printf("%7s",ins->DisplayVelAltitude());
    GotoXY(37,19); printf("%7s",ins->DisplayVelEast());
    GotoXY(45,19); printf("%7s",ins->DisplayVelNorth());
    GotoXY(29,20); printf("%7s",ins->DisplayAccAltitude());
    GotoXY(37,20); printf("%7s",ins->DisplayAccEast());
    GotoXY(45,20); printf("%7s",ins->DisplayAccNorth());
    }
  else {
    GotoXY(29,22); printf("%7s",ins->DisplayPerilune());
    GotoXY(29,23); printf("%7s",ins->DisplayApolune());
    GotoXY(37,21); printf("%7s",ins->DisplayMomEast());
    GotoXY(45,21); printf("%7s",ins->DisplayMomNorth());
    }
  }

void Console::UpdateConsole() {
  Int8 i;
  if (pilotLocation != lastPilotLocation) {
    GotoXY(32,2); printf(" ");
    GotoXY(37,2); printf(" ");
    GotoXY(42,2); printf(" ");
    GotoXY(47,2); printf(" ");
    switch (pilotLocation) {
      case PILOT_CSM:
           GotoXY(32,2); printf("*");
           break;
      case PILOT_LM:
           GotoXY(37,2); printf("*");
           break;
      case PILOT_LRV:
           GotoXY(42,2); printf("*");
           break;
      case PILOT_EVA:
           GotoXY(47,2); printf("*");
           break;
      }
    lastPilotLocation = pilotLocation;
    }

  /* *********************** */
  /* ***** Consumables ***** */
  /* *********************** */
  i = (int)(lm->AscentFuel() / FUEL_ASC * 100);
  if (i>99) i = 99;
  if (i != lastAscentFuel) {
    GotoXY(22,18); printf("%2d",i);
    lastAscentFuel = i;
    }
  i = (int)(lm->RcsFuel() / FUEL_RCS * 100);
  if (i>99) i = 99;
  if (i != lastRcsFuel) {
    GotoXY(22,19); printf("%2d",i);
    lastRcsFuel = i;
    }
  i = (int)(lm->DescentFuel() / FUEL_DES * 100);
  if (i>99) i = 99;
  if (i != lastDescentFuel) {
    GotoXY(22,20); printf("%2d",i);
    lastDescentFuel = i;
    }
  i = lm->Throttle();
  if (i > 99) i = 99;
  if (i != lastThrottle) {
    GotoXY(22,21); printf("%2d",i);
    GotoXY(17,20);
    if (!lm->DescentJettisoned() && i > 0) printf("^"); else printf(" ");
    lastThrottle = i;
    }
  i = (int)(lm->Oxygen() / LM_OXYGEN * 100);
  if (i>99) i = 99;
  if (i != lastLmOxygen) {
    GotoXY(22,22); printf("%2d",i);
    lastLmOxygen = i;
    }
  i = (int)(lm->Battery() / LM_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastLmBattery) {
    GotoXY(22,23); printf("%2d",i);
    lastLmBattery = i;
    }
  if (lm->RcsThrottle() != lastRcsThrottle) {
    GotoXY(17,19);
    switch (lm->RcsThrottle()) {
      case   1: printf("v"); break;
      case  10: printf(" "); break;
      case 100: printf("^"); break;
      }
    lastRcsThrottle = lm->RcsThrottle();
    }

  /* **************** */
  /* ***** Spin ***** */
  /* **************** */
  i = (int)(lm->PitchRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastPitchRate) {
    GotoXY(14, 18);
    printf("%2d",i);
    lastPitchRate = i;
    }
  i = (int)(lm->RollRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastRollRate) {
    GotoXY(14, 19);
    printf("%2d",i);
    lastRollRate = i;
    }
  i = (int)(lm->YawRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastYawRate) {
    GotoXY(14, 20);
    printf("%2d",i);
    lastYawRate = i;
    }

  /* ****************** */
  /* ***** Status ***** */
  /* ****************** */
  if (spaceSuitOn != lastSpaceSuitOn) {
    GotoXY(58,18);
    printf("%c",(spaceSuitOn == 0) ? 'v' : '^');
    lastSpaceSuitOn = spaceSuitOn;
    }
  if (plssOn != lastPlssOn) {
    GotoXY(58,19);
    printf("%c",(plssOn == 0) ? 'v' : '^');
    lastPlssOn = plssOn;
    }
  if (cabinPressurized != lastCabinPressurized) {
    GotoXY(58,20);
    printf("%c",(cabinPressurized == 0) ? 'v' : '^');
    lastCabinPressurized = cabinPressurized;
    }
  if (docked != lastDocked) {
    GotoXY(58,22);
    printf("%c",(docked == 0) ? ' ' : '^');
    lastDocked = docked;
    }
  if (landingRadarOn != lastLandingRadarOn) {
    GotoXY(53,21);
    printf("%c",(landingRadarOn == 0) ? ' ' : '^');
    lastLandingRadarOn = landingRadarOn;
    }
  if (dockingRadarOn != lastDockingRadarOn) {
    GotoXY(53,22);
    printf("%c",(dockingRadarOn == 0) ? ' ' : '^');
    lastDockingRadarOn = dockingRadarOn;
    }
  if (dsnOn != lastDsnOn) {
    GotoXY(53,23);
    printf("%c",(dsnOn == 0) ? ' ' : '^');
    lastDsnOn = dsnOn;
    }
  i = (int)metabolicRate;
  if (i != lastMetabolicRate) {
    GotoXY(65,18);
    printf("%2d",i);
    lastDsnOn = i;
    }
  i = (int)efficiency;
  if (i != lastEfficiency) {
    GotoXY(65,19);
    printf("%2d",i);
    lastEfficiency = i;
    }
  i = (int)injury;
  if (i != lastInjury) {
    GotoXY(65,20);
    printf("%2d",i);
    lastInjury = i;
    }
  if (lm->RcsFbMode() != lastRcsFbMode) {
    GotoXY(53,18);
    lastRcsFbMode = lm->RcsFbMode();
    if (lastRcsFbMode == ' ') printf(" ");
    if (lastRcsFbMode == 'F') printf("^");
    if (lastRcsFbMode == 'B') printf("v");
    }
  if (lm->RcsLrMode() != lastRcsLrMode) {
    GotoXY(53,19);
    lastRcsLrMode = lm->RcsLrMode();
    if (lastRcsLrMode == ' ') printf(" ");
    if (lastRcsLrMode == 'L') printf("^");
    if (lastRcsLrMode == 'R') printf("v");
    }
  if (lm->RcsUdMode() != lastRcsUdMode) {
    GotoXY(53,20);
    lastRcsUdMode = lm->RcsUdMode();
    if (lastRcsUdMode == ' ') printf(" ");
    if (lastRcsUdMode == 'U') printf("^");
    if (lastRcsUdMode == 'D') printf("v");
    }

  /* ****************** */
  /* ***** Clocks ***** */
  /* ****************** */
  if (clockUt != lastClockUt) {
    displayClock(71, 18, clockUt);
    lastClockUt = clockUt;
    }
  if (clockMi != lastClockMi) {
    displayClock(71, 19, clockMi);
    lastClockMi = clockMi;
    }
  if (clockBu != lastClockBu) {
    displayClock(71, 20, clockBu);
    lastClockBu = clockBu;
    }
  if (clockEv != lastClockEv) {
    displayClock(71, 21, clockEv);
    lastClockEv = clockEv;
    }
  if (clockDk != lastClockDk) {
    displayClock(71, 22, clockDk);
    lastClockDk = clockDk;
    }
  if (clockOr != lastClockOr) {
    displayClock(71, 23, clockOr);
    lastClockOr = clockOr;
    }

  /* ***** PLSS ***** */
  i = (int)(plssOxygen / PLSS_OXYGEN * 100);
  if (i>99) i = 99;
  if (i != lastPlssOxygen) {
    GotoXY(33,13); printf("%2d",i);
    lastPlssOxygen = i;
    }
  i = (int)(plssBattery / PLSS_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastPlssBattery) {
    GotoXY(33,14); printf("%2d",i);
    lastPlssBattery = i;
    }
  if (plssPacks != lastPlssPacks) {
    GotoXY(33,15);
    printf("%2d", plssPacks);
    lastPlssPacks = plssPacks;
    }

  if (strcmp(message,lastMessage) != 0) {
    GotoXY(37,23); printf("%s",message);
    strcpy(lastMessage,message);
    }
  if (seqTime != lastSeqTime) {
    GotoXY(48,23);
    if (seqTime == 0) {
      printf("    ");
      }
    else {
      printf("%4d",seqTime);
      }
    lastSeqTime = seqTime;
    }

  /* *************** */
  /* ***** LRV ***** */
  /* *************** */
  i = (int)(lrvBattery / LRV_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastLrvBattery) {
    GotoXY(41,13); printf("%2d",i);
    lastLrvBattery = i;
    }
  if (sampleBoxes != lastSampleBoxes) {
    GotoXY(41,14); printf("%2d",sampleBoxes);
    lastSampleBoxes = sampleBoxes;
    }
  if (lrvRock != lastLrvRock) {
    GotoXY(41,15); printf("%2d",lrvRock);
    lastLrvRock = lrvRock;
    }

  /* ************** */
  /* ***** LM ***** */
  /* ************** */
  if (lmRock != lastLmRock) {
    GotoXY(51,15); printf("%3d",lmRock);
    lastLmRock = lmRock;
    }

  if (insMode != lastInsMode) {
    GotoXY(29, 21);
    switch (insMode) {
      case INS_MODE_POS_ABS: printf("POS^ABS"); break;
      case INS_MODE_POS_REL: printf("POS^REL"); break;
      case INS_MODE_ORB_ABS: printf("ORBvABS"); break;
      }
    lastInsMode = insMode;
    }

  if (pilotLocation == PILOT_CSM) displayIns(csm, lm);
  if (pilotLocation == PILOT_LM)  displayIns(lm, csm);
  fflush(stdout);
  }

