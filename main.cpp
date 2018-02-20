#define MAIN

#include "header.h"
#include "terminal.h"

Boolean run;

void setup() {
Vector t;
  pilotLocation = PILOT_CSM;
  csm->Position(Vector(99810+1738300,0,100));
  csm->Velocity(Vector(0,-1634,0.0));
  csm->FaceFront(Vector(0,0,1));
  csm->FaceLeft(Vector(0,-1,0));
  csm->FaceUp(Vector(1,0,0));
  lm->AscentFuel(FUEL_ASC);
  lm->DescentFuel(FUEL_DES);
  lm->Battery(432000.0);
  lm->Oxygen(432000.0);
  lm->RcsFbMode(' ');
  lm->RcsLrMode(' ');
  lm->RcsUdMode(' ');
  lm->RcsFuel(FUEL_RCS);
  lm->RcsThrottle(1);
  lm->FaceFront(Vector(1,0,0));
  lm->FaceLeft(Vector(0,-1,0));
  lm->FaceUp(Vector(0,0,-1));
  cabinPressurized = -1;
  clockBu = 0;
  clockDk = 0;
  clockEv = 0;
  clockMi = 0;
  clockOr = 0;
  clockUt = (8 * 3600) + (30 * 60);
  docked = -1;
  dockingRadarOn = 0;
  dsnOn = 0;
  efficiency = 75;
  injury = 0;
  insMode = INS_MODE_POS_ABS;
  landingRadarOn = 0;
  lmRock = 0;
  lrvBattery = LRV_BATTERY;
  lrvRock = 0;
  metabolicRate = 30.0;
  strcpy(message,"----------");
  targetLatitude = 0.0;
  targetLongitude = 0.0;
  plssOn = 0;
  plssOxygen = PLSS_OXYGEN;
  plssBattery = PLSS_BATTERY;
  plssPacks = 4;
  sampleBoxes = 8;
  seqTime = 0;
  spaceSuitOn = 0;
  }

Boolean alignedForDocking() {
  Vector v;
  Double ax,ay,rx;
  v = ins->RelVel();
  if (v.Z() > -0.2) return false;
  if (v.Z() < -0.4) return false;
  ax = asin(lm->FaceUp().Y()) * 180 / M_PI;
  ay = asin(lm->FaceUp().X()) * 180 / M_PI;
  rx = asin(lm->FaceLeft().X()) * 180 / M_PI;
  if (fabs(ax) <= 0.5 && fabs(ay) <= 0.5 && fabs(rx) <= 0.5) return true;
  return false;
  }

void cycle() {
  Vector v,v1;
  csm->Cycle();
  if (docked) {
    lm->Position(csm->Position() + Vector(0,0,19));
    lm->Velocity(csm->Velocity());
    lm->Altitude(csm->Altitude());
    lm->Latitude(csm->Latitude());
    lm->Longitude(csm->Longitude());
    lm->Radius(csm->Radius());
    }
  else lm->Cycle();
  ins->Cycle();
  if (!docked) {
    if (ins->RelPos().Length() < 19) {
      if (alignedForDocking()) {
        lm->Velocity(csm->Velocity());
        docked = -1;
        seqTime = 60;
        strcpy(message,"   DOCKING");
        seqFunction = SEQ_DOCKING;
        }
      else {
        v = ins->RelVel();
        if (v.Length() > 2) {
          ClrScr();
          printf("Collision with the CSM destroyed both vehicles!!!\n");
          ShowCursor();
          CloseTerminal();
          exit(0);
          }
        else {
          lm->Position(lm->Position() - v);
          lm->Velocity(lm->Velocity() - v);
          v = v.Scale(0.5);
          csm->Velocity(csm->Velocity() + v);
          lm->Velocity(lm->Velocity() - v);
          }
        }
      }
    }
  currentVehicle->UpdatePanel();
  }

void csmCommands(int key) {
  if (key == 'M') {
    seqTime = 2400;
    strcpy(message,"  MOVE->LM");
    seqFunction = SEQ_MOVE_LM;
    }
  }

void lmCommands(int key) {
  if (key == 'M') {
    if (docked) {
      seqTime = 900;
      strcpy(message," MOVE->CSM");
      seqFunction = SEQ_MOVE_CSM;
      }
    }
  if (key == 'U' && docked) {
    seqTime = 60;
    strcpy(message,"    UNDOCK");
    seqFunction = SEQ_UNDOCK;
    }
  if (key == 'S') {
    if (!spaceSuitOn) {
      seqTime = 20 * 60;
      strcpy(message,"  SUIT->ON");
      seqFunction = SEQ_SUITON;
      }
    else {
      if (cabinPressurized && ! plssOn) {
        seqTime = 35 * 60;
        strcpy(message," SUIT->OFF");
        seqFunction = SEQ_SUITOFF;
        }
      }
    }
  if (key == 'P') {
    if (!plssOn) {
      if (spaceSuitOn && plssPacks > 0) {
        seqTime = 35 * 60;
        strcpy(message,"  PLSS->ON");
        seqFunction = SEQ_PLSSON;
        }
      }
    else {
      if (cabinPressurized) {
        seqTime = 45 * 60;
        strcpy(message," PLSS->OFF");
        seqFunction = SEQ_PLSSOFF;
        }
      }
    }
  if (key == 'C') {
    if (!cabinPressurized) {
      seqTime = 2 * 60;
      strcpy(message," CAB->PRES");
      seqFunction = SEQ_CABINPRESS;
      }
    else {
      if (spaceSuitOn) {
        seqTime = 5 * 60;
        strcpy(message," CAB->EVAC");
        seqFunction = SEQ_CABINEVAC;
        }
      }
    }
  if (key == '?') dsnOn = (dsnOn) ? 0 : -1;
  if (key == '>') dockingRadarOn = (dockingRadarOn) ? 0 : -1;
  if (key == '<') landingRadarOn = (landingRadarOn) ? 0 : -1;
  if (!docked) {
    if (key == 'f' && lm->RcsFbMode() == ' ') lm->RcsFbMode('F');
    if (key == 'f' && lm->RcsFbMode() == 'B') lm->RcsFbMode(' ');
    if (key == 'b' && lm->RcsFbMode() == ' ') lm->RcsFbMode('B');
    if (key == 'b' && lm->RcsFbMode() == 'F') lm->RcsFbMode(' ');
    if (key == 'l' && lm->RcsLrMode() == ' ') lm->RcsLrMode('L');
    if (key == 'l' && lm->RcsLrMode() == 'R') lm->RcsLrMode(' ');
    if (key == 'r' && lm->RcsLrMode() == ' ') lm->RcsLrMode('R');
    if (key == 'r' && lm->RcsLrMode() == 'L') lm->RcsLrMode(' ');
    if (key == 'd' && lm->RcsUdMode() == ' ') lm->RcsUdMode('D');
    if (key == 'd' && lm->RcsUdMode() == 'U') lm->RcsUdMode(' ');
    if (key == 'u' && lm->RcsUdMode() == ' ') lm->RcsUdMode('U');
    if (key == 'u' && lm->RcsUdMode() == 'D') lm->RcsUdMode(' ');
    if (key == '=' && lm->RcsThrottle() == 10) lm->RcsThrottle(100);
    if (key == '=' && lm->RcsThrottle() == 1) lm->RcsThrottle(10);
    if (key == '-' && lm->RcsThrottle() == 10) lm->RcsThrottle(1);
    if (key == '-' && lm->RcsThrottle() == 100) lm->RcsThrottle(10);
    if (key == 'I' && lm->Throttle() == 0) {
      lm->Throttle(10);
      clockBu = 0;
      }
    if (key == 'i') lm->Throttle(0);
    if (key == KEY_KP_HOME) lm->RollRate(lm->RollRate()+1);
    if (key == KEY_HOME) lm->RollRate(lm->RollRate()+1);
    if (key == KEY_PGUP) lm->RollRate(lm->RollRate()-1);
    if (key == KEY_UP_ARROW) lm->PitchRate(lm->PitchRate()+1);
    if (key == KEY_DOWN_ARROW) lm->PitchRate(lm->PitchRate()-1);
    if (key == KEY_RIGHT_ARROW) lm->YawRate(lm->YawRate()+1);
    if (key == KEY_LEFT_ARROW) lm->YawRate(lm->YawRate()-1);
    if (lm->Throttle() > 0) {
      if (key == KEY_PGDN) lm->Throttle(lm->Throttle()+2);
      if (key == KEY_END) lm->Throttle(lm->Throttle()-2);
      if (key == KEY_KP_END) lm->Throttle(lm->Throttle()-2);
      if (key == KEY_F1) lm->Throttle(10);
      if (key == KEY_F2) lm->Throttle(20);
      if (key == KEY_F3) lm->Throttle(30);
      if (key == KEY_F4) lm->Throttle(40);
      if (key == KEY_F5) lm->Throttle(50);
      if (key == KEY_F6) lm->Throttle(60);
      if (key == KEY_F7) lm->Throttle(70);
      if (key == KEY_F8) lm->Throttle(80);
      if (key == KEY_F9) lm->Throttle(90);
      if (key == KEY_F10) lm->Throttle(100);
      }
    }
  }

void executeSequencer() {
  switch (seqFunction) {
    case SEQ_MOVE_LM:
         pilotLocation = PILOT_LM;
         ins->Spacecraft(lm);
         ins->Target(csm);
         currentVehicle = lm;
         currentVehicle->SetupPanel();
         break;
    case SEQ_MOVE_CSM:
         pilotLocation = PILOT_CSM;
         ins->Spacecraft(csm);
         ins->Target(lm);
         currentVehicle = csm;
         currentVehicle->SetupPanel();
         run = false;
         break;
    case SEQ_UNDOCK:
         lm->Position(csm->Position() + Vector(0,0,19));
         lm->Velocity(csm->Velocity() + Vector(0,0,0.1));
         lm->Altitude(csm->Altitude());
         lm->Latitude(csm->Latitude());
         lm->Longitude(csm->Longitude());
         lm->Radius(csm->Radius());
         docked = 0;
         break;
    case SEQ_SUITON:
         spaceSuitOn = -1;
         break;
    case SEQ_SUITOFF:
         spaceSuitOn = 0;
         break;
    case SEQ_PLSSON:
         plssOn = -1;
         plssOxygen = PLSS_OXYGEN;
         plssBattery = PLSS_BATTERY;
         plssPacks--;
         break;
    case SEQ_PLSSOFF:
         plssOn = 0;
         break;
    case SEQ_CABINEVAC:
         cabinPressurized = 0;
         break;
    case SEQ_CABINPRESS:
         cabinPressurized = -1;
         break;
    }
  }

void setupTargetData() {
  Vector L;
  Double hyp;
  Double x,y,z;
  Double c,s;
  c = -1680.226342 * cos(targetLongitude*M_PI/180);
  s = -1680.226342 * sin(targetLongitude*M_PI/180);
  z = sin(targetLatitude*M_PI/180);
  x = sin(targetLongitude*M_PI/180) * cos(targetLatitude*M_PI/180);
  y = -cos(targetLongitude*M_PI/180) * cos(targetLatitude*M_PI/180);
  targetPos = Vector(x*GROUND,y*GROUND,z*GROUND);
  targetVel = Vector(c,s,0);
  L = targetVel.Cross(targetPos).Norm();
  hyp = sqrt(L.X() * L.X() + L.Y() * L.Y());
  targetMomEast = L.X() / hyp;
  targetMomEast = acos(targetMomEast) * 180 / M_PI;
  if (targetMomEast <= -180) targetMomEast += 360;
  if (targetMomEast >= 180) targetMomEast -= 360;
  targetMomNorth = asin(L.Z()) * 180 / M_PI;
  }

int main(int argc, char** argv) {
  int key;
  char buffer[64];
  simSpeed = 100000;
  csm = new CSM();
  lm = new LunarModule();
  ins = new INS();
  setup();
  if (load((char*)"lms.sav") == 0) {
    targetLatitude = -9999.99;
    while (targetLatitude <-90 || targetLatitude > 90) {
      printf("Target latitude: ");
      fgets(buffer,64,stdin);
      sscanf(buffer,"%lf",&targetLatitude);
      }
    targetLongitude = -9999.99;
    while (targetLongitude <-180 || targetLongitude > 180) {
      printf("Target longitude: ");
      fgets(buffer,64,stdin);
      sscanf(buffer,"%lf",&targetLongitude);
      }
    }
  setupTargetData();
  OpenTerminal();
  HideCursor();
  console = new Console();
  if (pilotLocation == PILOT_CSM) {
    ins->Spacecraft(csm);
    ins->Target(lm);
    currentVehicle = csm;
    }
  if (pilotLocation == PILOT_LM) {
    ins->Spacecraft(lm);
    ins->Target(csm);
    currentVehicle = lm;
    }
  currentVehicle->SetupPanel();
//  drawPanel();
  run = true;
  ticks = 10;
  currentVehicle->UpdatePanel();
  while (run) {
    if (ticks >= 10) {
      clockUt++;
      if (lm->Throttle() != 0) clockBu++;
      if (!docked) {
        clockMi++;
        lm->Battery(lm->Battery() - 1);
        if (pilotLocation == PILOT_LM) {
          lm->Oxygen(lm->Oxygen() - 1);
          }
        }
      cycle();
      ticks = 0;
      if (seqTime > 0) {
        seqTime--;
        if (seqTime == 0) {
          strcpy(message,"----------");
          simSpeed = 100000;
          executeSequencer();
          currentVehicle->UpdatePanel();
          }
        }
      }
    else ticks++;
    usleep(simSpeed);
    if (KeyPressed()) {
      key = Inkey();
      if (key == '!') simSpeed = 100000;
      if (key == '@') simSpeed = 10000;
      if (key == '#') simSpeed = 1000;
      if (key == '$') simSpeed = 100;
      if (key == '%') simSpeed = 10;
      if (seqTime == 0) {
        if (key == '1') { insMode = INS_MODE_POS_ABS; ins->Mode(insMode); }
        if (key == '2') { insMode = INS_MODE_POS_TAR; ins->Mode(insMode); }
        if (key == '3') { insMode = INS_MODE_POS_REL; ins->Mode(insMode); }
        if (key == '4') { insMode = INS_MODE_ORB_ABS; ins->Mode(insMode); }
        if (key == '5') { insMode = INS_MODE_ORB_TAR; ins->Mode(insMode); }
        if (key == 'Q') run = false;
        if (pilotLocation == PILOT_CSM) csmCommands(key);
        if (pilotLocation == PILOT_LM)  lmCommands(key);
        }
      }
    }
  save();
  GotoXY(1,25);
  ShowCursor();
  CloseTerminal();
  return 0;
  }

