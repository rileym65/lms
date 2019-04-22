#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "types.h"
#include "vector.h"
#include "computer.h"
#include "common.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "helpers.h"

#define MODE_INP_P_1     1
#define MODE_INP_P_2     2
#define MODE_INP_V_1     3
#define MODE_INP_V_2     4
#define MODE_INP_V_3     5
#define MODE_INP_N_1     6
#define MODE_INP_N_2     7
#define MODE_INP_N_3     8
#define MODE_INP_R_1     9
#define MODE_INP_R_2     10
#define MODE_INP_R_3     11

#define ERR_NO_PRGM      1001
#define ERR_STK_OVER     1002
#define ERR_STK_UNDER    1003
#define ERR_DIV0         1004
#define ERR_INV_INST     1005
#define ERR_OVERRUN      1006
#define ERR_RANGE        1007
#define ERR_INPUT        1008

char compOutput[128];

UInt32 defaultprog[] = {
  0x01000001,                     /* 0000  PROG P00V00N01 */
  0x02201101,                     /* 0000  MOV  ALT,R1 */
  0x02202104,                     /* 0001  MOV  AVEL,R4 */
  0x02203107,                     /* 0002  MOV  AACC,R7 */
  0x02204102,                     /* 0003  MOV  EAST,R2 */
  0x02205105,                     /* 0004  MOV  EVEL,R5 */
  0x02206108,                     /* 0005  MOV  EACC,R8 */
  0x02207103,                     /* 0006  MOV  NRTH,R3 */
  0x02208106,                     /* 0007  MOV  NVEL,R6 */
  0x02209109,                     /* 0008  MOV  NACC,R9 */
  0x04000000,                     /* 0009  JMP  0      */
  0xffffffff,
  };

Computer::Computer(Vehicle* v,const char* core) {
  vehicle = v;
  strcpy(corefile,core);
  ins = vehicle->GetIns();
  rom = NULL;
  romLength = 0;
  Reset();
  if (!loadCoreFile()) loadDefaultProgram();
  }

Computer::~Computer() {
  if (rom != NULL) free(rom);
  romLength = 0;
  }

UInt32 Computer::Check() {
  UInt32 i;
  UInt32 ret;
  ret = 0xffffffff;
  for (i=0; i<romLength; i++)
    ret ^= rom[i];
  ret = (ret & 0xffffff) ^ ((ret >> 8) & 0xffffff);
  return ret;
  }

void Computer::Load(FILE* file) {
  int i;
  char* pline;
  Boolean run;
  UInt32 check;
  check = 0;
  run = false;
  for (i=0; i<256; i++) regs[i] = 0;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) {
      if (check != Check()) {
        run = false;
        }
      p_running = run;
      return;
      }
    else if (startsWith(pline,"program ")) prog = atoi(nw(pline));
    else if (startsWith(pline,"verb ")) verb = atoi(nw(pline));
    else if (startsWith(pline,"noun ")) noun = atoi(nw(pline));
    else if (startsWith(pline,"sp ")) p_sp = atoi(nw(pline));
    else if (startsWith(pline,"pc ")) p_pc = atoi(nw(pline));
    else if (startsWith(pline,"vnsp ")) vn_sp = atoi(nw(pline));
    else if (startsWith(pline,"vnpc ")) vn_pc = atoi(nw(pline));
    else if (startsWith(pline,"check ")) check = atoi(nw(pline));
    else if (startsWith(pline,"running true")) {
      p_running = true;
      run = true;
      }
    else if (startsWith(pline,"running false")) {
      p_running = false;
      run = false;
      }
    else if (startsWith(pline,"vnrunning true")) vn_running = true;
    else if (startsWith(pline,"vnrunning false")) vn_running = false;
    else if (startsWith(pline,"register ")) {
      pline = nw(pline);
      i = atoi(pline);
      pline = nw(pline);
      regs[i] = atof(pline);
      }
    else if (startsWith(pline,"stack ")) {
      pline = nw(pline);
      i = atoi(pline);
      pline = nw(pline);
      p_stack[i] = atoi(pline);
      }
    else if (startsWith(pline,"vnstack ")) {
      pline = nw(pline);
      i = atoi(pline);
      pline = nw(pline);
      vn_stack[i] = atoi(pline);
      }
    else {
      Write("Unknown line found in save file: ");
      WriteLn(pline);
      exit(1);
      }
    }
  }

void Computer::Save(FILE* file) {
  int i;
  fprintf(file,"Computer {%s",LE);
  fprintf(file,"  Program %d%s",prog,LE);
  fprintf(file,"  Verb %d%s",verb,LE);
  fprintf(file,"  Noun %d%s",noun,LE);
  fprintf(file,"  SP %d%s",p_sp,LE);
  fprintf(file,"  PC %d%s",p_pc,LE);
  fprintf(file,"  VNSP %d%s",vn_sp,LE);
  fprintf(file,"  VNPC %d%s",vn_pc,LE);
  if (p_running) fprintf(file,"  Running True%s",LE);
    else fprintf(file,"  Running False%s",LE);
  if (vn_running) fprintf(file,"  VNRunning True%s",LE);
    else fprintf(file,"  VNRunning False%s",LE);
  for (i=0; i<p_sp; i++)
    fprintf(file,"  Stack %d %d%s",i,p_stack[i],LE);
  for (i=0; i<p_sp; i++)
    fprintf(file,"  VNStack %d %d%s",i,vn_stack[i],LE);
  for (i=0; i<256; i++)
    if (regs[i] != 0.0)
      fprintf(file,"  Register %d %.18f%s",i,regs[i],LE);
  fprintf(file,"  Check %u%s",Check(),LE);
  fprintf(file,"  }%s",LE);
  }

void Computer::Reset() {
  Int16 i;
  prog = 0;
  verb = 0;
  noun = 1;
  event = 0;
  eventMode = 'U';
  eventRunning = false;
  p_running = false;
  vn_running = false;
  input = false;
  inputMode = 0;
  err = false;
  p_pc = 0;
  p_sp = 0;
  for (i=0; i<256; i++) regs[i] = 0;
  vn_pc = 0;
  vn_sp = 0;
  vn_running = false;
  }

Boolean Computer::loadCoreFile() {
  UInt32 i;
  UInt32 addr;
  UInt32 opcode;
  Boolean valid;
  FILE *file;
  char line[1024];
//  file = fopen("core.bin","r");
  file = fopen(corefile,"r");
  if (file == NULL) {
    printf("Could not open core file: %s\n",corefile);
    exit(1);
    return false;
    }
  addr = 0;
  while (fgets(line, 1023, file) != NULL) {
    opcode = 0;
    valid = false;
    for (i=0; i<strlen(line); i++) {
      if (line[i] >= '0' && line[i] <= '9') {
        opcode = (opcode << 4) | (line[i] - '0');
        valid = true;
        }
      if (line[i] >= 'a' && line[i] <= 'f') {
        opcode = (opcode << 4) | (line[i] - 'a' + 10);
        valid = true;
        }
      if (line[i] >= 'A' && line[i] <= 'F') {
        opcode = (opcode << 4) | (line[i] - 'A' + 10);
        valid = true;
        }
      }
    if (valid) {
      addOpcode(addr, opcode);
      addr++;
      }
    }
  return true;
  }

void Computer::loadDefaultProgram() {
  Int16 addr;
  addr = 0;
  while (defaultprog[addr] != 0xffffffff) {
    addOpcode(addr, defaultprog[addr]);
    addr++;
    }
  }

void Computer::addOpcode(UInt16 addr,UInt32 opcode) {
  if (addr >= romLength) {
    if (rom == NULL) rom = (UInt32*)malloc(sizeof(UInt32) * (addr+1));
      else rom = (UInt32*)realloc(rom,sizeof(UInt32) * (addr + 1));
    romLength = addr+1;
    }
  rom[addr] = opcode;
  }

char* Computer::Reg(UInt8 n) {
  if (n == 1 && input && inputMode == MODE_INP_R_1) return inputBuffer;
  if (n == 2 && input && inputMode == MODE_INP_R_2) return inputBuffer;
  if (n == 3 && input && inputMode == MODE_INP_R_3) return inputBuffer;
  if (n > 0 && n < 16) {
    if (fabs(regs[n]) > 9999999) sprintf(compOutput,"99999999");
    else if (fabs(regs[n]) > 99999) sprintf(compOutput,"%8.0f",regs[n]);
    else if (fabs(regs[n]) > 9999) sprintf(compOutput,"%8.1f",regs[n]);
    else if (fabs(regs[n]) > 999) sprintf(compOutput,"%8.2f",regs[n]);
    else if (fabs(regs[n]) > 99) sprintf(compOutput,"%8.3f",regs[n]);
    else sprintf(compOutput,"%8.4f",regs[n]);

    }
  else strcpy(compOutput," 0000000");
  return compOutput;
  }

char* Computer::Prog() {
  if (input && inputMode == MODE_INP_P_1) {
    strcpy(compOutput,"__");
    }
  else if (input && inputMode == MODE_INP_P_2) {
    sprintf(compOutput,"%d_",prog / 10);
    }
  else {
    sprintf(compOutput,"%02d",prog);
    }
  return compOutput;
  }

char* Computer::Verb() {
  if (input && inputMode == MODE_INP_V_1) {
    strcpy(compOutput,"__");
    }
  else if (input && inputMode == MODE_INP_V_2) {
    sprintf(compOutput,"%d_",verbIn / 10);
    }
  else if (input && inputMode == MODE_INP_V_3) {
    sprintf(compOutput,"%02d",verbIn);
    }
  else {
    sprintf(compOutput,"%02d",verb);
    }
  return compOutput;
  }

char* Computer::Noun() {
  if (input && inputMode == MODE_INP_N_1) {
    strcpy(compOutput,"__");
    }
  else if (input && inputMode == MODE_INP_N_2) {
    sprintf(compOutput,"%d_",nounIn / 10);
    }
  else if (input && inputMode == MODE_INP_N_3) {
    sprintf(compOutput,"%02d",nounIn);
    }
  else {
    sprintf(compOutput,"%02d",noun);
    }
  return compOutput;
  }

Boolean Computer::Input() {
  return input;
  }

Boolean Computer::Running() {
  return p_running;
  }

Boolean Computer::Err() {
  return err;
  }

Double Computer::read(UInt16 addr) {
  Spacecraft* sc;
  sc = (Spacecraft*)vehicle;
  if ((addr & 0xf00) == 0x100) return regs[addr & 0xff];
  if ((addr & 0xf00) == 0x200) {
    switch (addr & 0xff) {
      case 0x00: return 0;
      case 0x01: return ins->Altitude();
      case 0x02: return vehicle->VelocityAltitude();
      case 0x03: return vehicle->AccelAltitude();
      case 0x04: return ins->Longitude();
      case 0x05: return vehicle->VelocityEast();
      case 0x06: return vehicle->AccelEast();
      case 0x07: return ins->Latitude();
      case 0x08: return vehicle->VelocityNorth();
      case 0x09: return vehicle->AccelNorth();
      case 0x0a: return ins->Periapsis();
      case 0x0b: return ins->Apoapsis();
      case 0x0c: return ins->Orbiting()->Radius();
      case 0x0d: return ins->AscendingNode();
      case 0x0e: return ins->Inclination();
      case 0x0f: return sc->RelAltitude();
      case 0x10: return ins->TarLongitude();
      case 0x11: return ins->TarLatitude();
      case 0x12: return sc->RelLongitude();
      case 0x13: return sc->RelLatitude();
      case 0x14: return sc->RelAltitude();
      case 0x15: return sc->RelVel().X();
      case 0x16: return sc->RelVel().Y();
      case 0x17: return sc->RelVel().Z();
      case 0x18: return M_PI;
      case 0x19: return 1;
      case 0x1a: return 10;
      case 0x1b: return 100;
      case 0x1c: return 1000;
      case 0x1d: return clockMi;
      case 0x1e: return clockBu;
      case 0x1f: return vehicle->Mass();
      case 0x20: return 30339.05838741743;
      case 0x21: return verb;
      case 0x22: return noun;
      case 0x23: return lm->DescentFuel();
      case 0x24: return lm->AscentFuel();
      case 0x25: return lm->RcsFuel();
      case 0x26: return sc->TargetMomEast();
      case 0x27: return sc->TargetMomNorth();
      case 0x28: return sc->RelMomEast();
      case 0x29: return sc->RelMomNorth();
      case 0x2a: return vehicle->Roll();
      case 0x2b: return vehicle->Pitch();
      case 0x2c: return vehicle->Yaw();
      case 0x2d: return ins->OrbitTime();
      case 0x2e: return vehicle->LatitudeVelocity();
      case 0x2f: return vehicle->LatitudeAcceleration();
      case 0x30: return sc->RelOrbitTime();
      case 0x31: return clockUt;
      case 0x32: return clockGe;
      case 0x33: return ins->ClockAp();
      case 0x34: return ins->ClockPe();
      case 0x35: return sc->Fuel();
      case 0x36: return ins->TrueAnomaly();
      case 0x37: return ins->MeanAnomaly();
      case 0x38: return ins->EccentricAnomaly();
      case 0x39: return 9.80665;
      case 0x3a: return sc->Isp();
      case 0x3b: return sc->RcsIsp();
      case 0x3c: return sc->FuelUsed();
      case 0x3d: return ins->ArgOfPeriapsis();
      case 0x3e: return event;
      }
    }
  if ((addr & 0xf00) == 0x600) {
    switch (addr & 0xff) {
      case 0x00: return vehicle->Throttle();
      case 0x01: return vehicle->RollRate();
      case 0x02: return vehicle->PitchRate();
      case 0x03: return vehicle->YawRate();
      case 0x04: return ((Spacecraft*)vehicle)->RcsThrottle();
      case 0x05: return ((Spacecraft*)vehicle)->RcsRotThrottle();
      case 0x0c: return prog;
      }
    }
  return 0;
  }

void Computer::write(UInt16 addr,Double value) {
  if ((addr & 0xf00) == 0x100) regs[addr & 0xff] = value;
  if ((addr & 0xf00) == 0x600) {
    switch (addr & 0xff) {
      case 0x00: vehicle->Throttle(value); break;
      case 0x01: vehicle->RollRate(value); break;
      case 0x02: vehicle->PitchRate(value); break;
      case 0x03: vehicle->YawRate(value); break;
      case 0x04: ((Spacecraft*)vehicle)->RcsThrottle(value); break;
      case 0x05: ((Spacecraft*)vehicle)->RcsRotThrottle(value); break;
      case 0x06: ((Spacecraft*)vehicle)->RcsFbMode((value == 0) ? ' ' : 'F'); break;
      case 0x07: ((Spacecraft*)vehicle)->RcsFbMode((value == 0) ? ' ' : 'B'); break;
      case 0x08: ((Spacecraft*)vehicle)->RcsUdMode((value == 0) ? ' ' : 'U'); break;
      case 0x09: ((Spacecraft*)vehicle)->RcsUdMode((value == 0) ? ' ' : 'D'); break;
      case 0x0a: ((Spacecraft*)vehicle)->RcsLrMode((value == 0) ? ' ' : 'L'); break;
      case 0x0b: ((Spacecraft*)vehicle)->RcsLrMode((value == 0) ? ' ' : 'R'); break;
      case 0x0c: prog = (int)value;
      }
    }
  }

Vector Computer::readVector(UInt16 addr) {
  Vector v;
  Double x,y,z;
  Spacecraft* sc;
  sc = (Spacecraft*)vehicle;
  if ((addr & 0xf00) == 0x300) {
    switch (addr & 0xff) {
      case 0x00: return vehicle->Velocity();
      case 0x01: return vehicle->Position();
      case 0x02: return vehicle->FaceUp();
      case 0x03: return vehicle->FaceUp().Neg();
      case 0x04: return vehicle->FaceFront();
      case 0x05: return vehicle->FaceFront().Neg();
      case 0x06: return vehicle->FaceLeft();
      case 0x07: return vehicle->FaceLeft().Neg();
      case 0x08: return vres;
      case 0x09: return sc->RelVel();
      case 0x0a: return sc->RelPos();
      case 0x0b:
                 z = cos(mission->TargetLatitude() * DR) * GROUND;
                 x = sin(mission->TargetLongitude() * DR) * z;
                 y = -cos(mission->TargetLongitude() * DR) * z;
                 z = sin(mission->TargetLatitude() * DR) * GROUND;
                 v = Vector(x,y,z);
                 v += Moon->Position();
                 return v;
      case 0x0c: return vehicle->Position() - vehicle->Orbiting()->Position();
      case 0x0d: return vehicle->Velocity() - vehicle->Orbiting()->Velocity();
      }
    }
  if ((addr & 0xf00) == 0x100) {
    addr = addr & 0xff;
    return Vector(regs[addr], regs[addr+1], regs[addr+2]);
    }
  return Vector(0,0,0);
  }

void Computer::writeVector(UInt16 addr, Vector v) {
  if ((addr & 0xf00) == 0x100) {
    addr = addr & 0xff;
    regs[addr] = v.X();
    regs[addr+1] = v.Y();
    regs[addr+2] = v.Z();
    }
  }

void Computer::Push(UInt32 v) {
  if (*sp >= 255) {
    *running = false;
    err = true;
    regs[13] = ERR_STK_OVER;
    return;
    }
  stack[*sp++] = v;
  }

Boolean Computer::exec(UInt32 cmd) {
  UInt16 arg1;
  UInt16 arg2;
  Double d1;
  Double a1,a2;
  FILE  *logfile;
  Int32 i1,i2;
  Vector v1,v2,v3;
  arg1 = (cmd >> 12) & 0xfff;
  arg2 = cmd & 0xfff;
  if (plog && &p_pc == pc) {
    logfile = fopen("plog.txt", "a");
    fprintf(logfile,"%8x  %8x\n",(*pc)-1,cmd);
    fclose(logfile);
    }
  if (vnlog && &vn_pc == pc) {
    logfile = fopen("vnlog.txt", "a");
    fprintf(logfile,"%8x  %8x\n",(*pc)-1,cmd);
    fclose(logfile);
    }
  switch (cmd & 0xff000000) {
    case 0x01000000:                                         /* PROG */
         return true;
    case 0x02000000:                                         /* MOV */
         write(cmd & 0xfff, read((cmd >> 12) & 0xfff));
         return true;
    case 0x03000000:                                         /* WAIT */
         return false;
    case 0x04000000:                                         /* JMP */
         *pc = cmd & 0xffffff;
         return true;
    case 0x05000000:                                         /* END */
         *running = false;
         return false;
    case 0x06000000:                                         /* SUB */
         d1 = read(arg1) - read(arg2);
         write(arg1, d1);
         return true;
    case 0x07000000:                                         /* CALP */
         i1 = findProgram(cmd & 0xffffff);
         if (i1 == -1) {
           *running = false;
           err = true;
           regs[13] = ERR_NO_PRGM;
           return false;
           }
         i1++;
         if (*sp >= 255) {
           *running = false;
           err = true;
           regs[13] = ERR_STK_OVER;
           return false;
           }
         stack[*sp] = *pc;
         *sp = *sp + 1;
         *pc = i1;
         return true;
    case 0x08000000:                                        /* RET */
         if (*sp == 0) {
           *running = false;
           err = true;
           regs[13] = ERR_STK_UNDER;
           return false;
           }
         *sp = *sp - 1;
         *pc = stack[*sp];
         return true;
    case 0x09000000:                                       /* END */
         *running = false;
         return false;
    case 0x0a000000:                                       /* ADD */
         d1 = read(arg1) + read(arg2);
         write(arg1, d1);
         return true;
    case 0x0b000000:                                       /* MUL */
         d1 = read(arg1) * read(arg2);
         write(arg1, d1);
         return true;
    case 0x0c000000:                                       /* DIV */
         a1 = read(arg1);
         a2 = read(arg2);
         if (a2 == 0) {
           err = true;
           *running = false;
           regs[13] = ERR_DIV0;
           return false;
           }
         else {
           d1 = a1 / a2;
           write(arg1, d1);
           return true;
           }
    case 0x0d000000:                                       /* LDI */
         a1 = rom[(*pc)++];
         write(arg1, a1);
         return true;
    case 0x0e000000:                                       /* NEG */
         a1 = read(arg1);
         a1 = -a1;
         write(arg2, a1);
         return true;
    case 0x0f000000:                                       /* JEQ */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[(*pc)++];
         if (a1 == a2) *pc = i1;
         return true;
    case 0x10000000:                                       /* JNE */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[(*pc)++];
         if (a1 != a2) *pc = i1;
         return true;
    case 0x11000000:                                       /* JG  */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[(*pc)++];
         if (a1 > a2) *pc = i1;
         return true;
    case 0x12000000:                                       /* JGE */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[(*pc)++];
         if (a1 >= a2) *pc = i1;
         return true;
    case 0x13000000:                                       /* JL  */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[(*pc)++];
         if (a1 < a2) *pc = i1;
         return true;
    case 0x14000000:                                       /* JLE */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[(*pc)++];
         if (a1 <= a2) *pc = i1;
         return true;
    case 0x15000000:                                       /* COS */
         a1 = read(arg1) * DR;
         a1 = cos(a1);
         write(arg2,a1);
         return true;
    case 0x16000000:                                       /* SIN */
         a1 = read(arg1) * DR;
         a1 = sin(a1);
         write(arg2,a1);
         return true;
    case 0x17000000:                                       /* SQR */
         a1 = read(arg1);
         a1 = a1 * a1;
         write(arg2,a1);
         return true;
    case 0x18000000:                                       /* SQRT */
         a1 = read(arg1);
         a1 = sqrt(a1);
         write(arg2,a1);
         return true;
    case 0x19000000:                                       /* INV */
         a1 = read(arg1);
         a1 = 1 / a1;
         write(arg2,a1);
         return true;
    case 0x1a000000:                                       /* ACOS */
         a1 = read(arg1);
         a1 = acos(a1) / DR;
         write(arg2,a1);
         return true;
    case 0x1b000000:                                       /* ASIN */
         a1 = read(arg1);
         a1 = asin(a1) / DR;
         write(arg2,a1);
         return true;
    case 0x1c000000:                                       /* TAN */
         a1 = read(arg1) * DR;
         a1 = tan(a1);
         write(arg2,a1);
         return true;
    case 0x1d000000:                                       /* ATAN */
         a1 = read(arg1);
         a1 = atan(a1) / DR;
         write(arg2,a1);
         return true;
    case 0x1e000000:                                       /* DOT */
         v1 = readVector(arg1);
         v2 = readVector(arg2);
         regs[0] = v1.Dot(v2);
         return true;
    case 0x1f000000:                                       /* NORM */
         v1 = readVector(arg1);
         writeVector(arg2,v1.Norm());
         return true;
    case 0x20000000:                                       /* CRS */
         v1 = readVector(arg1);
         v2 = readVector(arg2);
         vres = v1.Cross(v2);
         return true;
    case 0x21000000:                                       /* VMOV */
         v1 = readVector(arg1);
         writeVector(arg2,v1);
         return true;
    case 0x22000000:                                       /* VADD */
         v1 = readVector(arg1);
         v2 = readVector(arg2);
         v1 = v1 + v2;
         writeVector(arg1,v1);
         return true;
    case 0x23000000:                                       /* VSUB */
         v1 = readVector(arg1);
         v2 = readVector(arg2);
         v1 = v1 - v2;
         writeVector(arg1,v1);
         return true;
    case 0x24000000:                                       /* VLEN */
         v1 = readVector(arg1);
         a1 = v1.Length();
         write(arg2, a1);
         return true;
    case 0x25000000:                                       /* VNEG */
         v1 = readVector(arg1);
         writeVector(arg2, v1.Neg());
         return true;
    case 0x26000000:                                       /* VSCL */
         v1 = readVector(arg1);
         a1 = read(arg2);
         vres = v1.Scale(a1);
         return true;
    case 0x27000000:                                         /* CALL */
         if (*sp >= 255) {
           *running = false;
           err = true;
           regs[13] = ERR_STK_OVER;
           return false;
           }
         stack[*sp] = *pc;
         *sp = *sp + 1;
         *pc = cmd & 0xffffff;
         return true;
    case 0x28000000:                                         /* INT */
         a1 = read(arg1);
         a1 = floor(a1);
         write(arg2,a1);
         return true;
    case 0x29000000:                                         /* MOD */
         i1 = floor(read(arg1));
         i2 = floor(read(arg2));
         if (i2 == 0) {
           err = true;
           *running = false;
           regs[13] = ERR_DIV0;
           return false;
           }
         else {
           d1 = i1 % i2;
           write(arg1, d1);
           return true;
           }
    case 0x2a000000:                                         /* LOG */
         a1 = read(arg1);
         d1 = log(a1);
         write(arg1, d1);
         return true;
    case 0x2b000000:                                         /* ORNT */
         if (arg2 == 1) ((Spacecraft*)(vehicle))->Prograde(3);
         if (arg2 == 2) ((Spacecraft*)(vehicle))->Retrograde(3);
         if (arg2 == 3) ((Spacecraft*)(vehicle))->Norm(3);
         if (arg2 == 4) ((Spacecraft*)(vehicle))->Anorm(3);
         if (arg2 == 5) ((Spacecraft*)(vehicle))->Inside(3);
         if (arg2 == 6) ((Spacecraft*)(vehicle))->Outside(3);
         return true;
    case 0x2c000000:                                         /* RUN */
         if (pc == &p_pc) return true;
         i1 = findProgram(cmd & 0xffffff);
         if (i1 == -1) {
           *running = false;
           err = true;
           regs[13] = ERR_NO_PRGM;
           return false;
           }
         p_pc = i1;
         p_sp = 0;
         prog = (cmd & 0xff0000) >> 16;
         p_running = true;
         return true;
    case 0x2d000000:                                         /* INP */
         if (input) {
           *running = false;
           err = true;
           regs[13] = ERR_INPUT;
           return false;
           }
         inputMode = 0;
         if (arg2 == 0x101) inputMode = MODE_INP_R_1;
         if (arg2 == 0x102) inputMode = MODE_INP_R_2;
         if (arg2 == 0x103) inputMode = MODE_INP_R_3;
         if (inputMode == 0) {
           *running = false;
           err = true;
           regs[13] = ERR_RANGE;
           regs[14] = arg1 - 0x100;
           return false;
           }
         strcpy(inputBuffer,"+_____");
         input = true;
         return true;
    case 0x2e000000:                                         /* EVSTP */
         eventRunning = false;
         return true;
    case 0x2f000000:                                         /* EVUP */
         eventMode = 'U';
         eventRunning = true;
         return true;
    case 0x30000000:                                         /* EVDN */
         eventMode = 'D';
         eventRunning = true;
         return true;
    case 0x31000000:                                         /* EVCNT */
         eventRunning = true;
         return true;
    case 0x32000000:                                         /* EVSET */
         event = (regs[1] * 3600) + (regs[2] * 60) + regs[3];
         return true;
    case 0x33000000:                                         /* EVCLR */
         event = 0;
         return true;
    default:
         *running = false;
         err = true;
         regs[13] = ERR_INV_INST;
         regs[14] = (cmd & 0xff000000) >> 24;
         regs[15] = *pc-1;
         return false;
    }
  }

void Computer::PCycle() {
  Boolean flag;
  Int16 count;
  flag = true;
  count = 100;
  running = &p_running;
  if (!*running) flag = false;
  stack = p_stack;
  sp = &p_sp;
  pc = &p_pc;
  while (flag) {
    if ((UInt32)p_pc >= romLength) {
      *running = false;
      flag = false;
      err = true;
      regs[13] = ERR_OVERRUN;
      regs[14] = 1;
      }
    else {
      flag = exec(rom[(*pc)++]);
      if (--count <= 0) flag = false;
      }
    }
  }

void Computer::VnCycle() {
  Boolean flag;
  Int16 count;
  count = 50;
  flag = true;
  stack = vn_stack;
  sp = &vn_sp;
  pc = &vn_pc;
  running = &vn_running;
  if (!*running) flag = false;
  while (flag) {
    if ((UInt32)vn_pc >= romLength) {
      *running = false;
      flag = false;
      regs[13] = ERR_OVERRUN;
      regs[14] = 2;
      }
    else {
      flag = exec(rom[vn_pc++]);
      if (--count <= 0) flag = false;
      }
    }
  }

void Computer::SCycle() {
  if (eventRunning) {
    if (eventMode == 'U') {
      event++;
      }
    else {
      if (event > 0) {
        event--;
        if (event == 0) eventRunning = false;
        }
      }
    }
  }

Int32 Computer::findProgram(UInt32 code) {
  Int32 ret;
  UInt32 i;
  code |= 0x01000000;
  ret = -1;
  for (i=0; i<romLength; i++)
    if (rom[i] == code) {
      ret = i;
      i = romLength;
      }
  return ret;
  }

void Computer::ProcessKey(Int32 key) {
  Int32 pos;
  UInt32 i;
  UInt32 code;
  if (key == 13 || key == 10 || key == 'e') {
    if (inputMode == MODE_INP_R_1) {
      regs[1] = atoi(inputBuffer);
      input = false;
      inputMode = 0;
      }
    if (inputMode == MODE_INP_R_2) {
      regs[2] = atoi(inputBuffer);
      input = false;
      inputMode = 0;
      }
    if (inputMode == MODE_INP_R_3) {
      regs[3] = atoi(inputBuffer);
      input = false;
      inputMode = 0;
      }
    if (inputMode == MODE_INP_V_3 || inputMode == MODE_INP_N_3) {
      if (inputMode == MODE_INP_V_3) verb = verbIn;
      if (inputMode == MODE_INP_N_3) noun = nounIn;
      inputMode = 0;
      input = false;
      err = false;
      code = 0x00000000;
      code |= (prog << 16);
      code |= (verb << 8);
      code |= noun;
      vn_pc = findProgram(code);
      if (vn_pc == -1) {
        code = 0x00000000;
        code |= (verb << 8);
        code |= noun;
        vn_pc = findProgram(code);
        if (vn_pc == -1) {
          code = 0x00000000;
          code |= (verb << 8);
          vn_pc = findProgram(code);
          if (vn_pc == 01) {
            vn_running = false;
            err = true;
            regs[13] = ERR_NO_PRGM;
            }
          else {
            vn_running = true;
            vn_sp = 0;
            }
          }
        else {
          vn_running = true;
          vn_sp = 0;
          }
        }
      else {
        vn_running = true;
        vn_sp = 0;
        }
      }
    }
  if (key == 'p') {
    p_running = !p_running;
    }
  if (key == 'v' && inputMode == 0) {
    verbIn = 0;
    vn_running = false;
    err = false;
    input = true;
    inputMode = MODE_INP_V_1;
    }
  if (key == 'n' && inputMode == 0) {
    nounIn = 0;
    vn_running = false;
    err = false;
    input = true;
    inputMode = MODE_INP_N_1;
    }
  if (key == 'n' && inputMode == MODE_INP_V_3) {
    verb = verbIn;
    nounIn = 0;
    vn_running = false;
    err = false;
    input = true;
    inputMode = MODE_INP_N_1;
    }
  if (key == 'c') {
    if (inputMode == MODE_INP_V_1 ||
        inputMode == MODE_INP_V_2 ||
        inputMode == MODE_INP_V_3) {
      verbIn = 0;
      inputMode = MODE_INP_V_1;
      }
    if (inputMode == MODE_INP_N_1 ||
        inputMode == MODE_INP_N_2 ||
        inputMode == MODE_INP_N_3) {
      nounIn = 0;
      inputMode = MODE_INP_N_1;
      }
    if (inputMode == MODE_INP_R_1 ||
        inputMode == MODE_INP_R_2 ||
        inputMode == MODE_INP_R_3) {
      strcpy(inputBuffer,"+_____");
      }
    }
  if (key == '+' && (inputMode == MODE_INP_R_1 ||
                     inputMode == MODE_INP_R_2 ||
                     inputMode == MODE_INP_R_3)) {
    if (inputBuffer[0] == '-') inputBuffer[0] = '+';
    }
  if (key == '-' && (inputMode == MODE_INP_R_1 ||
                     inputMode == MODE_INP_R_2 ||
                     inputMode == MODE_INP_R_3)) {
    if (inputBuffer[0] == '+') inputBuffer[0] = '-';
    }
  if (key >= '0' && key <= '9') {
    switch (inputMode) {
      case MODE_INP_P_1:
           prog = (key - '0') * 10;
           inputMode = MODE_INP_P_2;
           break;
      case MODE_INP_P_2:
           prog += (key - '0');
           inputMode = 0;
           input = false;
           break;
      case MODE_INP_V_1:
           verbIn = (key - '0') * 10;
           inputMode = MODE_INP_V_2;
           break;
      case MODE_INP_V_2:
           verbIn += (key - '0');
           inputMode = MODE_INP_V_3;
           break;
      case MODE_INP_N_1:
           nounIn = (key - '0') * 10;
           inputMode = MODE_INP_N_2;
           break;
      case MODE_INP_N_2:
           nounIn += (key - '0');
           inputMode = MODE_INP_N_3;
           break;
      case MODE_INP_R_1:
      case MODE_INP_R_2:
      case MODE_INP_R_3:
           pos = -1;
           for (i=0; i<strlen(inputBuffer); i++)
             if (pos < 0 && inputBuffer[i] == '_') pos = i;
           if (pos >= 0) {
             inputBuffer[pos] = key;
             }
           break;
      }
    }
  }



