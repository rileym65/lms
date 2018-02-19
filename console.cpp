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
  lastDockingRadarPosX = 5;
  lastDockingRadarPosY = 3;
  lastDockingRadarAngX = 5;
  lastDockingRadarAngY = 3;
  lastDockingRadarRolX = 5;
  lastDsnOn = 2;
  lastEfficiency = 0;
  lastFr = -999;
  lastInjury = -1;
  lastLanded = 0;
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

void Console::displayDockingRadar() {
  Int8 ax,ay;
  Int8 px,py;
  Int8 rx;
  char nsVel;
  char lVel;
  char rVel;
  char fVel;
  char bVel;
  Vector relPos;
  Vector relVel;
  relPos = ins->RelPos();
  if (pilotLocation != PILOT_LM || !dockingRadarOn ||
      dsnOn || landingRadarOn || relPos.Length() > 200) {
    px = 5; py = 3;
    ax = 5; ay = 3;
    rx = 5;
    nsVel = '|';
    fVel = '-';
    bVel = '-';
    lVel = '|';
    rVel = '|';
    }
  else {
    relVel = ins->RelVel();
    py = 3 - relPos.X()+.5;
    if (py > 5) py = 5;
    if (py < 1) py = 1;
    px = 5 + relPos.Y()+.5;
    if (px < 1) px = 1;
    if (px > 9) px = 9;
    ax = 5 + asin(lm->FaceUp().Y()) * 180 / M_PI + 0.5;
    ay = 3 - asin(lm->FaceUp().X()) * 180 / M_PI + 0.5;
    if (ax < 1) ax = 1;
    if (ax > 9) ax = 9;
    if (ay < 1) ay = 1;
    if (ay > 5) ay = 5;
    rx = 5 + asin(lm->FaceLeft().X()) * 180 / M_PI + 0.5;
    if (rx < 1) rx = 1;
    if (rx > 9) rx = 9;
    if (relVel.Z() < -0.4) nsVel = '+';
    else if (relVel.Z() < 0 && relVel.Z() > -0.2) nsVel = '-';
    else nsVel = '|';
    rVel = (relVel.Y() > 0.02) ? '<' : '|';
    lVel = (relVel.Y() < -0.02) ? '>' : '|';
    bVel = (relVel.X() > 0.02) ? 'v' : '-';
    fVel = (relVel.X() < -0.02) ? '^' : '-';
    }
  GotoXY(INST_DR_X+lastDockingRadarPosX,INST_DR_Y+lastDockingRadarPosY);
  printf(" ");
  GotoXY(INST_DR_X+lastDockingRadarAngX,INST_DR_Y+lastDockingRadarAngY);
  printf(" ");
  GotoXY(INST_DR_X+lastDockingRadarRolX,INST_DR_Y+1); printf(" ");
  GotoXY(INST_DR_X+lastDockingRadarRolX,INST_DR_Y+5); printf(" ");
  GotoXY(INST_DR_X+rx,INST_DR_Y+1); printf("v");
  GotoXY(INST_DR_X+rx,INST_DR_Y+5); printf("^");
  if (ax == px && ay == py) {
    GotoXY(INST_DR_X+px,INST_DR_Y+py); printf("*");
    }
  else {
    GotoXY(INST_DR_X+px,INST_DR_Y+py); printf("+");
    GotoXY(INST_DR_X+ax,INST_DR_Y+ay); printf("X");
    }
  GotoXY(INST_DR_X,INST_DR_Y+1); printf("%c",nsVel);
  GotoXY(INST_DR_X+10,INST_DR_Y+1); printf("%c",nsVel);
  GotoXY(INST_DR_X+9,INST_DR_Y); printf("%c",fVel);
  GotoXY(INST_DR_X+9,INST_DR_Y+6); printf("%c",bVel);
  GotoXY(INST_DR_X,INST_DR_Y+5); printf("%c",rVel);
  GotoXY(INST_DR_X+10,INST_DR_Y+5); printf("%c",lVel);
  lastDockingRadarPosX = px;
  lastDockingRadarPosY = py;
  lastDockingRadarAngX = ax;
  lastDockingRadarAngY = ay;
  lastDockingRadarRolX = rx;
  }

void Console::displayFaces(char side) {
  Boolean flag;
  Int8 i;
  Int32  dx[3], dy[3];
  Double d[3];
  char   c[3];
  char   tc;
  Int32  ti;
  Double td;
  if (side == 'L') {
    dx[0] = leftFaceX; dy[0] = leftFaceY; d[0] = faceD;
    c[0] = (faceD <= 0) ? 'F' : 'f';
    dx[1] = leftLeftX; dy[1] = leftLeftY; d[1] = leftD;
    c[1] = (leftD <= 0) ? 'L' : 'l';
    dx[2] = leftUpX; dy[2] = leftUpY; d[2] = upD;
    c[2] = (upD <= 0) ? 'U' : 'u';
    }
  else {
    dx[0] = rightFaceX; dy[0] = rightFaceY; d[0] = faceD;
    c[0] = (faceD <= 0) ? 'F' : 'f';
    dx[1] = rightLeftX; dy[1] = rightLeftY; d[1] = leftD;
    c[1] = (leftD <= 0) ? 'L' : 'l';
    dx[2] = rightUpX; dy[2] = rightUpY; d[2] = upD;
    c[2] = (upD <= 0) ? 'U' : 'u';
    }
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

void Console::displayLeftAxis(Vehicle *vehicle) {
  Vector pos;
  Vector vel;
  Vector xVec;
  Vector yVec;
  Vector zVec;
  vel = vehicle->Velocity().Norm();
  xVec = Vector(0,0,1);
  yVec = vehicle->Position().Norm();
//GotoXY(1,27); printf("%f %f %f\n",yVec.X(),yVec.Y(),yVec.Z());
//  xVec = Vector(yVec.Z(),-yVec.Z(),1-fabs(yVec.Z()));
  zVec = Vector(yVec.Y(), -yVec.X(), yVec.Z()).Norm();
  GotoXY(leftFaceX, leftFaceY); printf(" ");
  GotoXY(leftLeftX, leftLeftY); printf(" ");
  GotoXY(leftUpX, leftUpY); printf(" ");
  /* ***** Face ***** */
  leftFaceX = 14.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  leftFaceY = 9.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = vehicle->FaceFront().Dot(zVec);
  /* ***** Left ***** */
  leftLeftX = 14.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  leftLeftY = 9.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = vehicle->FaceLeft().Dot(zVec);
  /* ***** Up ***** */
  leftUpX = 14.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  leftUpY = 9.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = vehicle->FaceUp().Dot(zVec);
  displayFaces('L');
  }

void Console::displayRightAxis(Vehicle *vehicle) {
  Vector pos;
  Vector vel;
  pos = vehicle->Position().Norm();
  vel = vehicle->Velocity().Norm();
  Vector xVec;
  Vector yVec;
  Vector zVec;
  xVec = Vector(0,0,1);
  yVec = vehicle->Velocity().Norm();
//  xVec = Vector(-pos.Z(),pos.Z(),1-fabs(pos.Z()));
  yVec = Vector(pos.Y(),-pos.X(),0);
  zVec = vehicle->Position().Norm();
  GotoXY(rightFaceX, rightFaceY); printf(" ");
  GotoXY(rightLeftX, rightLeftY); printf(" ");
  GotoXY(rightUpX, rightUpY); printf(" ");
  /* ***** Face ***** */
  rightFaceX = 67.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  rightFaceY = 9.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = -vehicle->FaceFront().Dot(zVec);
  /* ***** Left ***** */
  rightLeftX = 67.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  rightLeftY = 9.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = -vehicle->FaceLeft().Dot(zVec);
  /* ***** Up ***** */
  rightUpX = 67.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  rightUpY = 9.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = -vehicle->FaceUp().Dot(zVec);
  displayFaces('R');
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
  if (lm->Landed() != lastLanded) {
    GotoXY(58,23);
    printf("%c",(lm->Landed() == 0) ? ' ' : '^');
    lastLanded = lm->Landed();
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
      case INS_MODE_POS_TAR: printf("POS^TAR"); break;
      case INS_MODE_POS_REL: printf("POS^REL"); break;
      case INS_MODE_ORB_ABS: printf("ORBvABS"); break;
      }
    lastInsMode = insMode;
    }

  if (pilotLocation == PILOT_CSM) displayIns(csm, lm);
  if (pilotLocation == PILOT_LM)  displayIns(lm, csm);
  displayDockingRadar();
  fflush(stdout);
  }

