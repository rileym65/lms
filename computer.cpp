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

char compOutput[128];

typedef struct {
  char symbol[16];
  Int32 value;
  } INST;

INST symtab[] = {
  { "PROG", 0x01000000 },
  { "MOV",  0x02000000 },
  { "WAIT", 0x03000000 },
  { "JMP",  0x04000000 },
  { "END",  0x05000000 },
  { "SUB",  0x06000000 },
  { "CALP", 0x07000000 },
  { "RET",  0x08000000 },
  { "END",  0x09000000 },

  { "R1",   0x00000101 },
  { "R2",   0x00000102 },
  { "R3",   0x00000103 },
  { "R4",   0x00000104 },
  { "R5",   0x00000105 },
  { "R6",   0x00000106 },
  { "R7",   0x00000107 },
  { "R8",   0x00000108 },
  { "R9",   0x00000109 },
  { "R10",  0x0000010a },
  { "R11",  0x0000010b },
  { "R12",  0x0000010c },
  { "R13",  0x0000010d },
  { "R14",  0x0000010e },
  { "R15",  0x0000010f },
  { "ALT",  0x00000201 },
  { "AVEL", 0x00000202 },
  { "AACC", 0x00000203 },
  { "EAST", 0x00000204 },
  { "EVEL", 0x00000205 },
  { "EACC", 0x00000206 },
  { "NRTH", 0x00000207 },
  { "NVEL", 0x00000208 },
  { "NACC", 0x00000209 },
  { "PERL", 0x0000020A },
  { "APOL", 0x0000020B },
  { "GRND", 0x0000020C },
  { "ANOD", 0x0000020D },
  { "INCL", 0x0000020E },
  { "TALT", 0x0000020F },
  { "TLNG", 0x00000210 },
  { "TLAT", 0x00000211 },
  };

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
  file = fopen("core.dat","r");
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
    if (fabs(regs[n]) > 9999999) sprintf(compOutput,"%8.0f",regs[n]);
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
      }
    }
  return 0;
  }

void Computer::write(UInt16 addr,Double value) {
  if ((addr & 0xf00) == 0x100) regs[addr & 0xff] = value;
  }

Boolean Computer::exec(UInt32 cmd) {
  UInt16 arg1;
  UInt16 arg2;
  Double d1;
  Int32 i1;
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
    input = true;
    inputMode = MODE_INP_P_1;
    }
  if (key == 'v' && inputMode == 0) {
    running = false;
    input = true;
    inputMode = MODE_INP_V_1;
    }
  if (key == 'n' && inputMode == 0) {
    running = false;
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



