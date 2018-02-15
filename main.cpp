#define MAIN

#include "header.h"
#include "terminal.h"

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
  printf("| JET| LIF| ---| BAT:  |APO:       |----------:    | DSN| TD|--:  |OR:         |\n");
  printf("+------------------------------------------------------------------------------+\n");
  }

void setup() {
  pilotLocation = PILOT_LOL;
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
  plssOn = 0;
  plssOxygen = PLSS_OXYGEN;
  plssBattery = PLSS_BATTERY;
  plssPacks = 4;
  sampleBoxes = 8;
  spaceSuitOn = 0;
  }

void cycle() {
  csm->Cycle();
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

int main(int argc, char** argv) {
  int key;
  Boolean run;
//test();
//exit(1);
  OpenTerminal();
  HideCursor();
  simSpeed = 100000;
  csm = new CSM();
  lm = new LunarModule();
  setup();
  if (load((char*)"lms.sav") == 0) {
    }
  console = new Console();
  drawPanel();
  run = true;
  ticks = 10;
  console->UpdateConsole();
  while (run) {
    if (ticks >= 10) {
      clockUt++;
      cycle();
      ticks = 0;
      }
    else ticks++;
    usleep(simSpeed);
    if (KeyPressed()) {
      key = Inkey();
      if (key == '1') insMode = INS_MODE_POS_ABS;
      if (key == '4') insMode = INS_MODE_ORB_ABS;
      if (key == '!') simSpeed = 100000;
      if (key == '@') simSpeed = 10000;
      if (key == '#') simSpeed = 1000;
      if (key == '$') simSpeed = 100;
      if (key == 'Q') run = false;
      }
    }
  save();
  GotoXY(1,25);
  ShowCursor();
  CloseTerminal();
  return 0;
  }

