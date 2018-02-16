#define MAIN

#include "header.h"
#include "terminal.h"

Boolean run;

void drawPanel() {
  ClrScr();
  printf("+-------------------------+--------------------------+-------------------------+\n");
  printf("|    LOOKING   WEST       |   | CSM| LM | LRV| EVA|  |    LOOKING   DOWN       |\n");
  printf("| +--------up|----------+ +--------------------------+ +------west|----------+ |\n");
  printf("| |                     |n|    land         dock     | |                     |n|\n");
  printf("| |                     |o| +---w|----+  +---f|----+ | |                     |o|\n");
  printf("| |                     |r| |         |  |         | | |                     |r|\n");
  printf("| |                     |t| |         |n |         |l| |                     |t|\n");
  printf("| |                     |h|--         ----         --| |                     |h|\n");
  printf("|--                     --|s|         | r|         | |--                     --|\n");
  printf("|s|                     | | |         |  |         | |s|                     | |\n");
  printf("|o|                     | | +----|e---+  +----|b---+ |o|                     | |\n");
  printf("|u|                     | |   plss|    lrv| --|    lm|u|                     | |\n");
  printf("|t|                     | | OXY:  | BAT:  | --|--:   |t|                     | |\n");
  printf("|h|                     | | BAT:  | BOX:  | --|--:   |h|                     | |\n");
  printf("| +----------|down------+ | PAK:  | ROK:  | --|RK:   | +----------|east------+ |\n");
  printf("+-------------------------+--------------------------+-------------------------+\n");
  printf("|    att|  spin| consum|   altitude    east   north|        status|      clocks|\n");
  printf("|u/r:   |PIT:  | ASC:  |POS:       :       :       | F/B| SS|MB:  |UT:         |\n");
  printf("|f/r:   |ROL:  | RCS:  |VEL:       :       :       | L/R| PL|EF:  |MI:         |\n");
  printf("|l/s:   |YAW:  | DES:  |ACC:       :       :       | U/D| CB|IN:  |BU:         |\n");
  printf("|--------------| THR:  |MOM:       :       :       | RAD| --|--:  |EV:         |\n");
  printf("| ABO| KIL| PIL| OXY:  |PER:       +---------------+ LOL| DK|--:  |DK:         |\n");
  printf("| JET| LIF| ---| BAT:  |APO:       |          :    | DSN| TD|--:  |OR:         |\n");
  printf("+------------------------------------------------------------------------------+\n");
  }

void setup() {
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
  plssOn = 0;
  plssOxygen = PLSS_OXYGEN;
  plssBattery = PLSS_BATTERY;
  plssPacks = 4;
  sampleBoxes = 8;
  seqTime = 0;
  spaceSuitOn = 0;
  }

void cycle() {
  Vector v;
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
  console->UpdateConsole();
  }

void test() {
  Vector v1;
  Vector v2;
  v1 = Vector(100,0,100);
  v1 = v1.Norm();
printf("%12.4f %12.4f %12.4f\n",v1.X(),v1.Y(),v1.Z());
  v2 = Vector(0,0,-1);
  printf("dot: %12.4f\n",v1.Dot(v2));
  printf("angle: %12.4f\n",acos(v1.Dot(v2))*180/M_PI);
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
    }
  }

void executeSequencer() {
  switch (seqFunction) {
    case SEQ_MOVE_LM:
         pilotLocation = PILOT_LM;
         ins->Spacecraft(lm);
         ins->Target(csm);
         break;
    case SEQ_MOVE_CSM:
         pilotLocation = PILOT_CSM;
         ins->Spacecraft(csm);
         ins->Target(lm);
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
    }
  }

int main(int argc, char** argv) {
  int key;
//test();
//exit(1);
  OpenTerminal();
  HideCursor();
  simSpeed = 100000;
  csm = new CSM();
  lm = new LunarModule();
  ins = new INS();
  setup();
  if (load((char*)"lms.sav") == 0) {
    }
  if (pilotLocation == PILOT_CSM) {
    ins->Spacecraft(csm);
    ins->Target(lm);
    }
  if (pilotLocation == PILOT_LM) {
    ins->Spacecraft(lm);
    ins->Target(csm);
    }
  console = new Console();
  drawPanel();
  run = true;
  ticks = 10;
  console->UpdateConsole();
  while (run) {
    if (ticks >= 10) {
      clockUt++;
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
          console->UpdateConsole();
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
      if (seqTime == 0) {
        if (key == '1') { insMode = INS_MODE_POS_ABS; ins->Mode(insMode); }
        if (key == '3') { insMode = INS_MODE_POS_REL; ins->Mode(insMode); }
        if (key == '4') { insMode = INS_MODE_ORB_ABS; ins->Mode(insMode); }
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

