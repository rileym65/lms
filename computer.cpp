#include "header.h"
#include "types.h"
#include "computer.h"
#include "vehicle.h"

#define MODE_INP_P_1     1
#define MODE_INP_P_2     2
#define MODE_INP_V_1     3
#define MODE_INP_V_2     4
#define MODE_INP_N_1     5
#define MODE_INP_N_2     6

#define ERR_NO_PRGM      1001
#define ERR_STK_OVER     1002
#define ERR_STK_UNDER    1003
#define ERR_DIV0         1004

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

Computer::Computer(Vehicle* v) {
  vehicle = v;
  rom = NULL;
  romLength = 0;
  Reset();
  if (!loadCoreFile()) loadDefaultProgram();
  }

Computer::~Computer() {
  if (rom != NULL) free(rom);
  romLength = 0;
  }

void Computer::Reset() {
  Int16 i;
  prog = 0;
  verb = 0;
  noun = 1;
  running = false;
  input = false;
  inputMode = 0;
  err = false;
  pc = 0;
  for (i=0; i<256; i++) regs[i] = 0;
  }

Boolean Computer::loadCoreFile() {
  UInt32 i;
  UInt32 addr;
  UInt32 opcode;
  Boolean valid;
  FILE *file;
  char line[1024];
  file = fopen("core.bin","r");
  if (file == NULL) return false;
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

char* Computer::Reg(Int8 n) {
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
    sprintf(compOutput,"%d_",verb / 10);
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
    sprintf(compOutput,"%d_",noun / 10);
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
  return running;
  }

Boolean Computer::Err() {
  return err;
  }

Double Computer::read(UInt16 addr) {
  if ((addr & 0xf00) == 0x100) return regs[addr & 0xff];
  if ((addr & 0xf00) == 0x200) {
    switch (addr & 0xff) {
      case 0x00: return 0;
      case 0x01: return vehicle->Altitude();
      case 0x02: return vehicle->VelocityAltitude();
      case 0x03: return vehicle->AccelAltitude();
      case 0x04: return vehicle->Longitude();
      case 0x05: return vehicle->VelocityEast();
      case 0x06: return vehicle->AccelEast();
      case 0x07: return vehicle->Latitude();
      case 0x08: return vehicle->VelocityNorth();
      case 0x09: return vehicle->AccelNorth();
      case 0x0a: return ins->Perilune();
      case 0x0b: return ins->Apolune();
      case 0x0c: return GROUND;
      case 0x0d: return ins->MomEast();
      case 0x0e: return ins->MomNorth();
      case 0x0f: return ins->RelAltitude();
      case 0x10: return ins->TargetLongitude();
      case 0x11: return ins->TargetLatitude();
      case 0x12: return ins->RelLongitude();
      case 0x13: return ins->RelLatitude();
      case 0x14: return ins->RelAltitude();
      case 0x15: return ins->RelVel().X();
      case 0x16: return ins->RelVel().Y();
      case 0x17: return ins->RelVel().Z();
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
      case 0x26: return ins->TargetMomEast();
      case 0x27: return ins->TargetMomNorth();
      case 0x28: return ins->RelMomEast();
      case 0x29: return ins->RelMomNorth();
      case 0x2a: return vehicle->Roll();
      case 0x2b: return vehicle->Pitch();
      case 0x2c: return vehicle->Yaw();
      }
    }
  if ((addr & 0xf00) == 0x600) {
    switch (addr & 0xff) {
      case 0x00: return vehicle->Throttle();
      case 0x01: return vehicle->RollRate();
      case 0x02: return vehicle->PitchRate();
      case 0x03: return vehicle->YawRate();
      case 0x04: return vehicle->RcsThrottle();
      case 0x05: return vehicle->RcsRotThrottle();
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
      case 0x04: vehicle->RcsThrottle(value); break;
      case 0x05: vehicle->RcsRotThrottle(value); break;
      case 0x06: vehicle->RcsFbMode((value == 0) ? ' ' : 'F'); break;
      case 0x07: vehicle->RcsFbMode((value == 0) ? ' ' : 'B'); break;
      case 0x08: vehicle->RcsUdMode((value == 0) ? ' ' : 'U'); break;
      case 0x09: vehicle->RcsUdMode((value == 0) ? ' ' : 'D'); break;
      case 0x0a: vehicle->RcsLrMode((value == 0) ? ' ' : 'L'); break;
      case 0x0b: vehicle->RcsLrMode((value == 0) ? ' ' : 'R'); break;
      }
    }
  }

Vector Computer::readVector(UInt16 addr) {
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
      case 0x09: return ins->RelVel();
      case 0x0a: return ins->RelPos();
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

Boolean Computer::exec(UInt32 cmd) {
  UInt16 arg1;
  UInt16 arg2;
  Double d1;
  Double a1,a2;
  Int32 i1;
  Vector v1,v2,v3;
  arg1 = (cmd >> 12) & 0xfff;
  arg2 = cmd & 0xfff;
  switch (cmd & 0xff000000) {
    case 0x01000000:                                         /* PROG */
         prog = (cmd >> 16) & 0xff;
         verb = (cmd >> 8) & 0xff;
         noun = cmd & 0xff;
         return true;
    case 0x02000000:                                         /* MOV */
         write(cmd & 0xfff, read((cmd >> 12) & 0xfff));
         return true;
    case 0x03000000:                                         /* WAIT */
         return false;
    case 0x04000000:                                         /* JMP */
         pc = cmd & 0xffffff;
         return true;
    case 0x05000000:                                         /* END */
         running = false;
         return false;
    case 0x06000000:                                         /* SUB */
         d1 = read(arg1) - read(arg2);
         write(arg1, d1);
         return true;
    case 0x07000000:                                         /* CALP */
         i1 = findProgram(cmd & 0xffffff);
         if (i1 == -1) {
           running = false;
           err = true;
           regs[13] = ERR_NO_PRGM;
           return false;
           }
         i1++;
         if (sp >= 255) {
           running = false;
           err = true;
           regs[13] = ERR_STK_OVER;
           return false;
           }
         stack[sp++] = pc;
         pc = i1;
         return true;
    case 0x08000000:                                        /* RET */
         if (sp == 0) {
           running = false;
           err = true;
           regs[13] = ERR_STK_UNDER;
           return false;
           }
         pc = stack[--sp];
         return true;
    case 0x09000000:                                       /* END */
         running = false;
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
           running = false;
           regs[13] = ERR_DIV0;
           return false;
           }
         else {
           d1 = a1 / a2;
           write(arg1, d1);
           return true;
           }
    case 0x0d000000:                                       /* LDI */
         a1 = rom[pc++];
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
         i1 = rom[pc++];
         if (a1 == a2) pc = i1;
         return true;
    case 0x10000000:                                       /* JNE */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[pc++];
         if (a1 != a2) pc = i1;
         return true;
    case 0x11000000:                                       /* JG  */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[pc++];
         if (a1 > a2) pc = i1;
         return true;
    case 0x12000000:                                       /* JGE */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[pc++];
         if (a1 >= a2) pc = i1;
         return true;
    case 0x13000000:                                       /* JL  */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[pc++];
         if (a1 < a2) pc = i1;
         return true;
    case 0x14000000:                                       /* JLE */
         a1 = read(arg1);
         a2 = read(arg2);
         i1 = rom[pc++];
         if (a1 <= a2) pc = i1;
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
    default:
         running = false;
         err = true;
         return false;
    }
  }

void Computer::Cycle() {
  Boolean flag;
  Int16 count;
  flag = true;
  count = 100;
  if (!running) flag = false;
  while (flag) {
    if ((UInt32)pc >= romLength) {
      running = false;
      flag = false;
      err = true;
      return;
      }
    flag = exec(rom[pc++]);
    if (--count <= 0) flag = false;
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
  UInt32 code;
  if (key == 'g' && inputMode == 0 && !running) {
    err = false;
    code = 0x00000000;
    code |= (prog << 16);
    code |= (verb << 8);
    code |= noun;
    pc = findProgram(code);
    if (pc == -1) {
      running = false;
      err = true;
      regs[13] = ERR_NO_PRGM;
      }
    else {
      running = true;
      sp = 0;
      }
    }
  if (key == 'p' && inputMode == 0) {
    running = false;
    err = false;
    input = true;
    inputMode = MODE_INP_P_1;
    }
  if (key == 'v' && inputMode == 0) {
    running = false;
    err = false;
    input = true;
    inputMode = MODE_INP_V_1;
    }
  if (key == 'n' && inputMode == 0) {
    running = false;
    err = false;
    input = true;
    inputMode = MODE_INP_N_1;
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
           verb = (key - '0') * 10;
           inputMode = MODE_INP_V_2;
           break;
      case MODE_INP_V_2:
           verb += (key - '0');
           inputMode = 0;
           input = false;
           break;
      case MODE_INP_N_1:
           noun = (key - '0') * 10;
           inputMode = MODE_INP_N_2;
           break;
      case MODE_INP_N_2:
           noun += (key - '0');
           inputMode = 0;
           input = false;
           break;
      }
    }
  }



