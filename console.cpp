#include "header.h"
#include "console.h"
#include "terminal.h"
#include "math.h"

Console::Console() {
  Reset();
  }

Console::~Console() {
  }

void Console::Reset() {
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

void Console::DisplayDockingRadar(Int8 x, Int8 y) {
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
  GotoXY(x+lastDockingRadarPosX,y+lastDockingRadarPosY);
  printf(" ");
  GotoXY(x+lastDockingRadarAngX,y+lastDockingRadarAngY);
  printf(" ");
  GotoXY(x+lastDockingRadarRolX,y+1); printf(" ");
  GotoXY(x+lastDockingRadarRolX,y+5); printf(" ");
  GotoXY(x+rx,y+1); printf("v");
  GotoXY(x+rx,y+5); printf("^");
  if (ax == px && ay == py) {
    GotoXY(x+px,y+py); printf("*");
    }
  else {
    GotoXY(x+px,y+py); printf("+");
    GotoXY(x+ax,y+ay); printf("X");
    }
  GotoXY(x,y+1); printf("%c",nsVel);
  GotoXY(x+10,y+1); printf("%c",nsVel);
  GotoXY(x+9,y); printf("%c",fVel);
  GotoXY(x+9,y+6); printf("%c",bVel);
  GotoXY(x,y+5); printf("%c",rVel);
  GotoXY(x+10,y+5); printf("%c",lVel);
  lastDockingRadarPosX = px;
  lastDockingRadarPosY = py;
  lastDockingRadarAngX = ax;
  lastDockingRadarAngY = ay;
  lastDockingRadarRolX = rx;
  }

void Console::displayFaces(Int8 x, Int8 y, char side) {
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
    GotoXY(x+dx[i], y+dy[i]);
    printf("%c",c[i]);
    }
  }

void Console::DisplayWestAxis(Int8 x, Int8 y, Vehicle *vehicle) {
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
  GotoXY(x+leftFaceX, y+leftFaceY); printf(" ");
  GotoXY(x+leftLeftX, y+leftLeftY); printf(" ");
  GotoXY(x+leftUpX, y+leftUpY); printf(" ");
  /* ***** Face ***** */
  leftFaceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  leftFaceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = vehicle->FaceFront().Dot(zVec);
  /* ***** Left ***** */
  leftLeftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  leftLeftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = vehicle->FaceLeft().Dot(zVec);
  /* ***** Up ***** */
  leftUpX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  leftUpY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = vehicle->FaceUp().Dot(zVec);
  displayFaces(x, y, 'L');
  }

void Console::DisplayDownAxis(Int8 x, Int8 y, Vehicle *vehicle) {
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
  GotoXY(x+rightFaceX, y+rightFaceY); printf(" ");
  GotoXY(x+rightLeftX, y+rightLeftY); printf(" ");
  GotoXY(x+rightUpX, y+rightUpY); printf(" ");
  /* ***** Face ***** */
  rightFaceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  rightFaceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = -vehicle->FaceFront().Dot(zVec);
  /* ***** Left ***** */
  rightLeftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  rightLeftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = -vehicle->FaceLeft().Dot(zVec);
  /* ***** Up ***** */
  rightUpX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  rightUpY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = -vehicle->FaceUp().Dot(zVec);
  displayFaces(x, y, 'R');
  }

void Console::DisplayIns(Int8 x,Int8 y) {
  if (ins->Mode() < 4) {
    GotoXY(x+4,y+1); printf("%7s",ins->DisplayPosAltitude());
    GotoXY(x+12,y+1); printf("%7s",ins->DisplayPosEast());
    GotoXY(x+20,y+1); printf("%7s",ins->DisplayPosNorth());
    GotoXY(x+4,y+2); printf("%7s",ins->DisplayVelAltitude());
    GotoXY(x+12,y+2); printf("%7s",ins->DisplayVelEast());
    GotoXY(x+20,y+2); printf("%7s",ins->DisplayVelNorth());
    GotoXY(x+4,y+3); printf("%7s",ins->DisplayAccAltitude());
    GotoXY(x+12,y+3); printf("%7s",ins->DisplayAccEast());
    GotoXY(x+20,y+3); printf("%7s",ins->DisplayAccNorth());
    }
  else {
    GotoXY(x+12,y+4); printf("%7s",ins->DisplayMomEast());
    GotoXY(x+20,y+4); printf("%7s",ins->DisplayMomNorth());
    GotoXY(x+4,y+5); printf("%7s",ins->DisplayPerilune());
    GotoXY(x+4,y+6); printf("%7s",ins->DisplayApolune());
    }
  if (insMode != lastInsMode) {
    GotoXY(x+4, y+4);
    switch (insMode) {
      case INS_MODE_POS_ABS: printf("POS^ABS"); break;
      case INS_MODE_POS_TAR: printf("POS^TAR"); break;
      case INS_MODE_POS_REL: printf("POS^REL"); break;
      case INS_MODE_ORB_ABS: printf("ORBvABS"); break;
      case INS_MODE_ORB_TAR: printf("ORBvTAR"); break;
      }
    lastInsMode = insMode;
    }
  }

void Console::DisplayAtt(Int8 x, Int8 y) {
  Int32 i;
  i = (int)(ins->AttUr()+.4);
  if (lastUr != i) {
    GotoXY(x+4, y+1); printf("%3d",i);
    lastUr = i;
    }
  i = (int)(ins->AttFr()+.4);
  if (lastFr != i) {
    GotoXY(x+4, y+2); printf("%3d",i);
    lastFr = i;
    }
  i = (int)(ins->AttLs()+.4);
  if (lastLs != i) {
    GotoXY(x+4, y+3); printf("%3d",i);
    lastLs = i;
    }
  }

void Console::DisplayClocks(Int8 x, Int8 y) {
  if (clockUt != lastClockUt) {
    displayClock(x+3, y+1, clockUt);
    lastClockUt = clockUt;
    }
  if (clockMi != lastClockMi) {
    displayClock(x+3, y+2, clockMi);
    lastClockMi = clockMi;
    }
  if (clockBu != lastClockBu) {
    displayClock(x+3, y+3, clockBu);
    lastClockBu = clockBu;
    }
  if (clockEv != lastClockEv) {
    displayClock(x+3, y+4, clockEv);
    lastClockEv = clockEv;
    }
  if (clockDk != lastClockDk) {
    displayClock(x+3, y+5, clockDk);
    lastClockDk = clockDk;
    }
  if (clockOr != lastClockOr) {
    displayClock(x+3, y+6, clockOr);
    lastClockOr = clockOr;
    }
  }

void Console::DisplayCons(Int8 x, Int8 y) {
  Int32 i;
  i = (int)(lm->AscentFuel() / FUEL_ASC * 100);
  if (i>99) i = 99;
  if (i != lastAscentFuel) {
    GotoXY(x+5,y+1); printf("%2d",i);
    lastAscentFuel = i;
    }
  i = (int)(lm->RcsFuel() / FUEL_RCS * 100);
  if (i>99) i = 99;
  if (i != lastRcsFuel) {
    GotoXY(x+5,y+2); printf("%2d",i);
    lastRcsFuel = i;
    }
  i = (int)(lm->DescentFuel() / FUEL_DES * 100);
  if (i>99) i = 99;
  if (i != lastDescentFuel) {
    GotoXY(x+5,y+3); printf("%2d",i);
    lastDescentFuel = i;
    }
  i = lm->Throttle();
  if (i > 99) i = 99;
  if (i != lastThrottle) {
    GotoXY(x+5,y+4); printf("%2d",i);
    GotoXY(x,y+3);
    if (!lm->DescentJettisoned() && i > 0) printf("^"); else printf(" ");
    lastThrottle = i;
    }
  i = (int)(lm->Oxygen() / LM_OXYGEN * 100);
  if (i>99) i = 99;
  if (i != lastLmOxygen) {
    GotoXY(x+5,y+5); printf("%2d",i);
    lastLmOxygen = i;
    }
  i = (int)(lm->Battery() / LM_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastLmBattery) {
    GotoXY(x+5,y+6); printf("%2d",i);
    lastLmBattery = i;
    }
  if (lm->RcsThrottle() != lastRcsThrottle) {
    GotoXY(x,y+2);
    switch (lm->RcsThrottle()) {
      case   1: printf("v"); break;
      case  10: printf(" "); break;
      case 100: printf("^"); break;
      }
    lastRcsThrottle = lm->RcsThrottle();
    }
  }

void Console::DisplayLrv(Int8 x, Int8 y) {
  Int32 i;
  i = (int)(lrvBattery / LRV_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastLrvBattery) {
    GotoXY(x+4,y+1); printf("%2d",i);
    lastLrvBattery = i;
    }
  if (sampleBoxes != lastSampleBoxes) {
    GotoXY(x+4,y+2); printf("%2d",sampleBoxes);
    lastSampleBoxes = sampleBoxes;
    }
  if (lrvRock != lastLrvRock) {
    GotoXY(x+4,y+3); printf("%2d",lrvRock);
    lastLrvRock = lrvRock;
    }
  }

void Console::DisplayPlss(Int8 x, Int8 y) {
  Int32 i;
  i = (int)(plssOxygen / PLSS_OXYGEN * 100);
  if (i>99) i = 99;
  if (i != lastPlssOxygen) {
    GotoXY(x+4,y+1); printf("%2d",i);
    lastPlssOxygen = i;
    }
  i = (int)(plssBattery / PLSS_BATTERY * 100);
  if (i>99) i = 99;
  if (i != lastPlssBattery) {
    GotoXY(x+4,y+2); printf("%2d",i);
    lastPlssBattery = i;
    }
  if (plssPacks != lastPlssPacks) {
    GotoXY(x+4,y+3);
    printf("%2d", plssPacks);
    lastPlssPacks = plssPacks;
    }
  }

void Console::DisplaySpin(Int8 x, Int8 y) {
  int i;
  i = (int)(lm->PitchRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastPitchRate) {
    GotoXY(x+4, y+1);
    printf("%2d",i);
    lastPitchRate = i;
    }
  i = (int)(lm->RollRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastRollRate) {
    GotoXY(x+4, y+2);
    printf("%2d",i);
    lastRollRate = i;
    }
  i = (int)(lm->YawRate());
  if (i > 9) i = 9;
  if (i < -9) i = -9;
  if (i != lastYawRate) {
    GotoXY(x+4, y+3);
    printf("%2d",i);
    lastYawRate = i;
    }
  }

void Console::DisplayStatus(Int8 x, Int8 y) {
  Int32 i;
  if (spaceSuitOn != lastSpaceSuitOn) {
    GotoXY(x+5,y+1);
    printf("%c",(spaceSuitOn == 0) ? 'v' : '^');
    lastSpaceSuitOn = spaceSuitOn;
    }
  if (plssOn != lastPlssOn) {
    GotoXY(x+5,y+2);
    printf("%c",(plssOn == 0) ? 'v' : '^');
    lastPlssOn = plssOn;
    }
  if (cabinPressurized != lastCabinPressurized) {
    GotoXY(x+5,y+3);
    printf("%c",(cabinPressurized == 0) ? 'v' : '^');
    lastCabinPressurized = cabinPressurized;
    }
  if (docked != lastDocked) {
    GotoXY(x+5,y+5);
    printf("%c",(docked == 0) ? ' ' : '^');
    lastDocked = docked;
    }
  if (lm->Landed() != lastLanded) {
    GotoXY(x+5,y+6);
    printf("%c",(lm->Landed() == 0) ? ' ' : '^');
    lastLanded = lm->Landed();
    }
  if (landingRadarOn != lastLandingRadarOn) {
    GotoXY(x,y+4);
    printf("%c",(landingRadarOn == 0) ? ' ' : '^');
    lastLandingRadarOn = landingRadarOn;
    }
  if (dockingRadarOn != lastDockingRadarOn) {
    GotoXY(x,y+5);
    printf("%c",(dockingRadarOn == 0) ? ' ' : '^');
    lastDockingRadarOn = dockingRadarOn;
    }
  if (dsnOn != lastDsnOn) {
    GotoXY(x,y+6);
    printf("%c",(dsnOn == 0) ? ' ' : '^');
    lastDsnOn = dsnOn;
    }
  i = (int)metabolicRate;
  if (i != lastMetabolicRate) {
    GotoXY(x+12,y+1);
    printf("%2d",i);
    lastDsnOn = i;
    }
  i = (int)efficiency;
  if (i != lastEfficiency) {
    GotoXY(x+12,y+2);
    printf("%2d",i);
    lastEfficiency = i;
    }
  i = (int)injury;
  if (i != lastInjury) {
    GotoXY(x+12,y+3);
    printf("%2d",i);
    lastInjury = i;
    }
  if (lm->RcsFbMode() != lastRcsFbMode) {
    GotoXY(x,y+1);
    lastRcsFbMode = lm->RcsFbMode();
    if (lastRcsFbMode == ' ') printf(" ");
    if (lastRcsFbMode == 'F') printf("^");
    if (lastRcsFbMode == 'B') printf("v");
    }
  if (lm->RcsLrMode() != lastRcsLrMode) {
    GotoXY(x,y+2);
    lastRcsLrMode = lm->RcsLrMode();
    if (lastRcsLrMode == ' ') printf(" ");
    if (lastRcsLrMode == 'L') printf("^");
    if (lastRcsLrMode == 'R') printf("v");
    }
  if (lm->RcsUdMode() != lastRcsUdMode) {
    GotoXY(x,y+3);
    lastRcsUdMode = lm->RcsUdMode();
    if (lastRcsUdMode == ' ') printf(" ");
    if (lastRcsUdMode == 'U') printf("^");
    if (lastRcsUdMode == 'D') printf("v");
    }
  }

void Console::DisplaySeq(Int8 x, Int8 y) {
  if (strcmp(message,lastMessage) != 0) {
    GotoXY(x,y); printf("%s",message);
    strcpy(lastMessage,message);
    }
  if (seqTime != lastSeqTime) {
    GotoXY(x+11,y);
    if (seqTime == 0) {
      printf("    ");
      }
    else {
      printf("%4d",seqTime);
      }
    lastSeqTime = seqTime;
    }
  }

void Console::UpdateConsole() {
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


  /* ************** */
  /* ***** LM ***** */
  /* ************** */
  if (lmRock != lastLmRock) {
    GotoXY(51,15); printf("%3d",lmRock);
    lastLmRock = lmRock;
    }




  DisplayAtt(INST_ATT_X, INST_ATT_Y);
  DisplayClocks(INST_CLCK_X, INST_CLCK_Y);
  DisplayCons(INST_CONS_X, INST_CONS_Y);
  DisplayLrv(INST_LRV_X, INST_LRV_Y);
  DisplayPlss(INST_PLSS_X, INST_PLSS_Y);
  DisplaySeq(INST_SEQ_X, INST_SEQ_Y);
  DisplaySpin(INST_SPIN_X, INST_SPIN_Y);
  DisplayStatus(INST_STAT_X, INST_STAT_Y);
  DisplayIns(INST_INS_X, INST_INS_Y);
  DisplayDockingRadar(INST_DR_X, INST_DR_Y);
  if (pilotLocation == PILOT_CSM) {
    DisplayWestAxis(INST_WEST_X, INST_WEST_Y, csm);
    DisplayDownAxis(INST_DOWN_X, INST_DOWN_Y, csm);
    }
  if (pilotLocation == PILOT_LM) {
    DisplayWestAxis(INST_WEST_X, INST_WEST_Y, lm);
    DisplayDownAxis(INST_DOWN_X, INST_DOWN_Y, lm);
    }
  fflush(stdout);
  }

void Console::DrawAtt(Int8 x,Int8 y) {
  GotoXY(x,y+0); printf("    att");
  GotoXY(x,y+1); printf("u/r:   ");
  GotoXY(x,y+2); printf("f/r:   ");
  GotoXY(x,y+3); printf("l/s:   ");
  }

void Console::DrawClocks(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf("      clocks");
  GotoXY(x,y+1); printf("UT:   :  :  ");
  GotoXY(x,y+2); printf("MI:   :  :  ");
  GotoXY(x,y+3); printf("BU:   :  :  ");
  GotoXY(x,y+4); printf("EV:   :  :  ");
  GotoXY(x,y+5); printf("DK:   :  :  ");
  GotoXY(x,y+6); printf("OR:   :  :  ");
  }

void Console::DrawCons(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf(" consum");
  GotoXY(x,y+1); printf(" ASC:  ");
  GotoXY(x,y+2); printf(" RCS:  ");
  GotoXY(x,y+3); printf(" DES:  ");
  GotoXY(x,y+4); printf(" THR:  ");
  GotoXY(x,y+5); printf(" OXY:  ");
  GotoXY(x,y+6); printf(" BAT:  ");
  }

void Console::DrawDockingRadar(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf("    dock     ");
  GotoXY(x,y+1); printf(" +---f|----+ ");
  GotoXY(x,y+2); printf(" |         | ");
  GotoXY(x,y+3); printf(" |         |l");
  GotoXY(x,y+4); printf("--         --");
  GotoXY(x,y+5); printf("r|         | ");
  GotoXY(x,y+6); printf(" |         | ");
  GotoXY(x,y+7); printf(" +----|b---+ ");
  }

void Console::DrawDownAxis(Int8 x, Int8 y) {
  GotoXY(x,y+ 0); printf("    LOOKING   DOWN       ");
  GotoXY(x,y+ 1); printf(" +------west|----------+ ");
  GotoXY(x,y+ 2); printf(" |                     |n");
  GotoXY(x,y+ 3); printf(" |                     |o");
  GotoXY(x,y+ 4); printf(" |                     |r");
  GotoXY(x,y+ 5); printf(" |                     |t");
  GotoXY(x,y+ 6); printf(" |                     |h");
  GotoXY(x,y+ 7); printf("--                     --");
  GotoXY(x,y+ 8); printf("s|                     | ");
  GotoXY(x,y+ 9); printf("o|                     | ");
  GotoXY(x,y+10); printf("u|                     | ");
  GotoXY(x,y+11); printf("t|                     | ");
  GotoXY(x,y+12); printf("h|                     | ");
  GotoXY(x,y+13); printf(" +----------|east------+ ");
  }

void Console::DrawInd(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf(" ABO| KIL| PIL");
  GotoXY(x,y+1); printf(" JET| LIF| ---");
  }

void Console::DrawIns(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf("   altitude    east   north");
  GotoXY(x,y+1); printf("POS:       :       :       ");
  GotoXY(x,y+2); printf("VEL:       :       :       ");
  GotoXY(x,y+3); printf("ACC:       :       :       ");
  GotoXY(x,y+4); printf("MOM:       :       :       ");
  GotoXY(x,y+5); printf("PER:       ");
  GotoXY(x,y+6); printf("APO:       ");
  }

void Console::DrawLandingRadar(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf("    land     ");
  GotoXY(x,y+1); printf(" +---w|----+ ");
  GotoXY(x,y+2); printf(" |         | ");
  GotoXY(x,y+3); printf(" |         |n");
  GotoXY(x,y+4); printf("--         --");
  GotoXY(x,y+5); printf("s|         | ");
  GotoXY(x,y+6); printf(" |         | ");
  GotoXY(x,y+7); printf(" +----|e---+ ");
  }

void Console::DrawLm(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf("    lm");
  GotoXY(x,y+1); printf("--:   ");
  GotoXY(x,y+2); printf("--:   ");
  GotoXY(x,y+3); printf("RK:   ");
  }

void Console::DrawLrv(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf("   lrv");
  GotoXY(x,y+1); printf("BAT:  ");
  GotoXY(x,y+2); printf("BOX:  ");
  GotoXY(x,y+3); printf("ROK:  ");
  }

void Console::DrawPilot(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf(" CSM| LM | LRV| EVA");
  }

void Console::DrawPlss(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf("  plss");
  GotoXY(x,y+1); printf("OXY:  ");
  GotoXY(x,y+2); printf("BAT:  ");
  GotoXY(x,y+3); printf("PAK:  ");
  }

void Console::DrawSpin(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf("  spin");
  GotoXY(x,y+1); printf("PIT:  ");
  GotoXY(x,y+2); printf("ROL:  ");
  GotoXY(x,y+3); printf("YAW:  ");
  }

void Console::DrawStatus(Int8 x, Int8 y) {
  GotoXY(x,y+0); printf("        status");
  GotoXY(x,y+1); printf(" F/B| SS|MB:  ");
  GotoXY(x,y+2); printf(" L/R| PL|EF:  ");
  GotoXY(x,y+3); printf(" U/D| CB|IN:  ");
  GotoXY(x,y+4); printf(" RAD| --|--:  ");
  GotoXY(x,y+5); printf(" DOK| DK|--:  ");
  GotoXY(x,y+6); printf(" DSN| TD|--:  ");
  }

void Console::DrawWestAxis(Int8 x, Int8 y) {
  GotoXY(x,y+ 0); printf("    LOOKING   WEST       ");
  GotoXY(x,y+ 1); printf(" +--------up|----------+ ");
  GotoXY(x,y+ 2); printf(" |                     |n");
  GotoXY(x,y+ 3); printf(" |                     |o");
  GotoXY(x,y+ 4); printf(" |                     |r");
  GotoXY(x,y+ 5); printf(" |                     |t");
  GotoXY(x,y+ 6); printf(" |                     |h");
  GotoXY(x,y+ 7); printf("--                     --");
  GotoXY(x,y+ 8); printf("s|                     | ");
  GotoXY(x,y+ 9); printf("o|                     | ");
  GotoXY(x,y+10); printf("u|                     | ");
  GotoXY(x,y+11); printf("t|                     | ");
  GotoXY(x,y+12); printf("h|                     | ");
  GotoXY(x,y+13); printf(" +----------|down------+ ");
  }

