#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "terminal.h"

#define ARGS0 0
#define ARGS1 1
#define ARGS2 2
#define IMM2  3
#define JMP2  4

typedef struct {
  char symbol[16];
  Int32 value;
  Int32 flags;
  } INST;

typedef struct {
  char symbol[32];
  Int32 value;
  } SYMBOL;

INST inst[] = {
  { "PROG", 0x01000000, ARGS1 },
  { "MOV",  0x02000000, ARGS2 },
  { "WAIT", 0x03000000, ARGS0 },
  { "JMP",  0x04000000, ARGS1 },
  { "END",  0x05000000, ARGS0 },
  { "SUB",  0x06000000, ARGS2 },
  { "CALP", 0x07000000, ARGS1 },
  { "RET",  0x08000000, ARGS0 },
  { "END",  0x09000000, ARGS0 },
  { "ADD",  0x0a000000, ARGS2 },
  { "MUL",  0x0b000000, ARGS2 },
  { "DIV",  0x0c000000, ARGS2 },
  { "LDI",  0x0d000000, IMM2  },
  { "NEG",  0x0e000000, ARGS2 },
  { "JEQ",  0x0f000000, JMP2  },
  { "JNE",  0x10000000, JMP2  },
  { "JG",   0x11000000, JMP2  },
  { "JGE",  0x12000000, JMP2  },
  { "JL",   0x13000000, JMP2  },
  { "JLE",  0x14000000, JMP2  },
  { "COS",  0x15000000, ARGS2 },
  { "SIN",  0x16000000, ARGS2 },
  { "SQR",  0x17000000, ARGS2 },
  { "SQRT", 0x18000000, ARGS2 },
  { "INV",  0x19000000, ARGS2 },
  { "ACOS", 0x1a000000, ARGS2 },
  { "ASIN", 0x1b000000, ARGS2 },
  { "TAN",  0x1c000000, ARGS2 },
  { "ATAN", 0x1d000000, ARGS2 },
  { "",     0x7fffffff, 0     },
  };

SYMBOL symtab[] = {
  { "ZERO",   0x00000200 },
  { "ALT",    0x00000201 },
  { "AVEL",   0x00000202 },
  { "AACC",   0x00000203 },
  { "EAST",   0x00000204 },
  { "EVEL",   0x00000205 },
  { "EACC",   0x00000206 },
  { "NRTH",   0x00000207 },
  { "NVEL",   0x00000208 },
  { "NACC",   0x00000209 },
  { "PERL",   0x0000020A },
  { "APOL",   0x0000020B },
  { "GRND",   0x0000020C },
  { "ANOD",   0x0000020D },
  { "INCL",   0x0000020E },
  { "TALT",   0x0000020F },
  { "TLNG",   0x00000210 },
  { "TLAT",   0x00000211 },
  { "RLNG",   0x00000212 },
  { "RLAT",   0x00000213 },
  { "RALT",   0x00000214 },
  { "RAVEL",  0x00000215 },
  { "REVEL",  0x00000216 },
  { "RNVEL",  0x00000217 },
  { "PI",     0x00000218 },
  { "C1",     0x00000219 },
  { "C10",    0x0000021a },
  { "C100",   0x0000021b },
  { "C1000",  0x0000021c },
  { "CLKMI",  0x0000021d },
  { "CLKBU",  0x0000021e },

  { "THRTL",  0x00000600 },
  { "RLRAT",  0x00000601 },
  { "PTRAT",  0x00000602 },
  { "YWRAT",  0x00000603 },
  { "RCSTH",  0x00000604 },
  { "RCSRTH", 0x00000605 },
  { "",       0x7fffffff },
  };

SYMBOL *labels;
Int32   numLabels;
char    label[1024];
char    command[1024];
char    arg1[1024];
char    arg2[1024];
char    arg3[1024];
Int8    fields;
UInt32  program[128000];
UInt32  address;

void Parse(char* line) {
  char *orig;
  char *start;
  fields = 0;
  strcpy(label,"");
  strcpy(command,"");
  strcpy(arg1,"");
  strcpy(arg2,"");
  orig = line;
  if (*line == 0) return;
  if ((*line >= 'A' && *line <= 'Z') || (*line >= 'a' && *line <= 'z')) {
    start = line;
    while (*line != 0 && *line != ' ' && *line != '\t' && *line != ':') line++;
    if (*line == 0) {
      Write("Unexpected end of line: ");
      WriteLn(orig);
      return;
      }
    if (*line != ':') {
      Write("Invalid label termination: ");
      WriteLn(orig);
      return;
      }
    strncpy(label,start,line-start);
    label[line-start] = 0;
    fields |= 1;
    line++;
    }
  else if (*line == ';') return;
  else if (*line != ' ' && *line != '\t') {
    Write("Invalid character at start of line: ");
    WriteLn(orig);
    return;
    }
  while (*line == ' ' || *line == '\t') line++;
  if (*line == ';') return;
  start = line;
  while (*line != 0 && *line != ' ' && *line != '\t' && *line != ';') line++;
  if (line == start) {
    Write("No command found on line: ");
    WriteLn(orig);
    return;
    }
  strncpy(command,start,line-start);
  command[line-start] = 0;
  fields |= 2;
  while (*line == ' ' || *line == '\t') line++;
  if (*line == ';') return;
  start = line;
  while (*line != 0 && *line != ' ' && *line != '\t' && *line != ';' && 
         *line != ',') line++;
  if (start == line) return;
  strncpy(arg1,start,line-start);
  arg1[line-start] = 0;
  fields |= 4;

  while (*line == ' ' || *line == '\t') line++;
  if (*line == ';') return;
  if (*line == 0) return;
  if (*line != ',') {
    Write("Invalid character found on line: ");
    WriteLn(orig);
    return;
    }
  line++;
  while (*line == ' ' || *line == '\t') line++;
  if (*line == ';') return;
  start = line;
  while (*line != 0 && *line != ' ' && *line != '\t' && *line != ';' && 
         *line != ',') line++;
  if (start == line) return;
  strncpy(arg2,start,line-start);
  arg2[line-start] = 0;
  fields |= 8;

  while (*line == ' ' || *line == '\t') line++;
  if (*line == ';') return;
  if (*line == 0) return;
  if (*line != ',') {
    Write("Invalid character found on line: ");
    WriteLn(orig);
    return;
    }
  line++;
  while (*line == ' ' || *line == '\t') line++;
  if (*line == ';') return;
  start = line;
  while (*line != 0 && *line != ' ' && *line != '\t' && *line != ';' && 
         *line != ',') line++;
  if (start == line) return;
  strncpy(arg3,start,line-start);
  arg3[line-start] = 0;
  fields |= 16;
  }

Int32 FindInstruction(char* cmd) {
  Int32 i;
  i = 0;
  while (strlen(inst[i].symbol) > 0) {
    if (strcasecmp(cmd,inst[i].symbol) == 0) return i;
    i++;
    }
  return -1;
  }

Int32 FindLabel(char* label) {
  Int32 i;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(label,labels[i].symbol) == 0) return i;
  return -1;
  }

Boolean AddLabel(char* label,Int32 value) {
  if (FindLabel(label) >= 0) return false;
  if (labels == NULL)
    labels = (SYMBOL*)malloc(sizeof(SYMBOL));
  else
    labels = (SYMBOL*)realloc(labels,sizeof(SYMBOL)*(numLabels+1));
  strcpy(labels[numLabels].symbol, label);
  labels[numLabels].value = value;
  numLabels++;
  return true;
  }

Int32 GetProgVerbNoun(char* arg) {
  Int32 p,v,n;
  if (strlen(arg) != 9) return -1;
  if (arg[0] != 'P' && arg[0] != 'p') return -1;
  if (arg[1] < '0' || arg[1] > '9') return -1;
  if (arg[2] < '0' || arg[2] > '9') return -1;
  if (arg[3] != 'V' && arg[3] != 'v') return -1;
  if (arg[4] < '0' || arg[4] > '9') return -1;
  if (arg[5] < '0' || arg[5] > '9') return -1;
  if (arg[6] != 'N' && arg[6] != 'n') return -1;
  if (arg[7] < '0' || arg[7] > '9') return -1;
  if (arg[8] < '0' || arg[8] > '9') return -1;
  p = ((arg[1] - '0') * 10) + (arg[2] - '0');
  v = ((arg[4] - '0') * 10) + (arg[5] - '0');
  n = ((arg[7] - '0') * 10) + (arg[8] - '0');
  return (p << 16) | (v << 8) | n;
  }

Int32 GetImmValue(Int8 pass,char* arg) {
  return atoi(arg);
  }

Int32 GetArgValue(Int8 pass,char* arg) {
  Int32 ret;
  if (pass == 1) return 0;
  if ((arg[0] == 'R' || arg[0] == 'r') &&
      (arg[1] >= '0' && arg[1] <= '9')) {
    ret = atoi(arg+1);
    if (ret > 255) {
      Write("Invalid register: ");
      WriteLn(arg);
      return -1;
      }
    return ret | 0x100;
    }
  ret = GetProgVerbNoun(arg);
  if (ret >= 0) return ret;
  ret = FindLabel(arg);
  if (ret >= 0) return labels[ret].value;
  return -1;
  }

Boolean Pass(Int8 pass,char* filename) {
  Int32  i;
  Int32  a1;
  Int32  a2;
  UInt32 opcode;
  FILE* file;
  char  line[1024];
  file = fopen(filename, "r");
  address = 0;
  if (file == NULL) {
    WriteLn("Could not open input file");
    return false;
    }
  while (fgets(line, 1023, file) != NULL) {
    while (line[strlen(line)-1] > 0 && line[strlen(line)-1] < 32) {
      line[strlen(line)-1] = 0;
      }
    Parse(line);
    if (fields & 1) {
      if (pass == 1) {
        if (!AddLabel(label,address)) {
          Write("Duplicate label: ");
          WriteLn(label);
          return false;
          }
        }
      }
    if (fields & 2) {
      i = FindInstruction(command);
      if (i < 0) {
        Write("Opcode not found: ");
        WriteLn(command);
        return false;
        }
      opcode = inst[i].value;
      switch (inst[i].flags) {
        case ARGS0:
             program[address++] = opcode;
             break;
        case ARGS1:
             a1 = GetArgValue(pass,arg1);
             if (a1 < 0) {
               Write("Invalid label: ");
               WriteLn(arg1);
               return false;
               }
             opcode |= (a1 & 0xffffff);
             program[address++] = opcode;
             break;
        case ARGS2:
             a1 = GetArgValue(pass,arg1);
             if (a1 < 0) {
               Write("Invalid label: ");
               WriteLn(arg1);
               return false;
               }
             a2 = GetArgValue(pass,arg2);
             if (a2 < 0) {
               Write("Invalid label: ");
               WriteLn(arg2);
               return false;
               }
             opcode |= ((a1 & 0xfff) << 12);
             opcode |= (a2 & 0xfff);
             program[address++] = opcode;
             break;
        case IMM2:
             a1 = GetArgValue(pass,arg1);
             if (a1 < 0) {
               Write("Invalid label: ");
               WriteLn(arg1);
               return false;
               }
             a2 = GetImmValue(pass,arg2);
             opcode |= ((a1 & 0xfff) << 12);
             program[address++] = opcode;
             program[address++] = a2;
             break;
        case JMP2:
             a1 = GetArgValue(pass,arg1);
             a2 = GetArgValue(pass,arg2);
             opcode |= ((a1 & 0xfff) << 12);
             opcode |= (a2 & 0xfff);
             program[address++] = opcode;
             a1 = GetArgValue(pass,arg3);
             program[address++] = a1;
             break;
        }

      }
    }
  return true;
  }

int main(int argc, char** argv) {
  Int32 i;
  FILE* file;
  WriteLn("");
  WriteLn("GcAsm v1.0");
  if (argc != 2) {
    WriteLn("Usage: gcasm sourcefile");
    return 1;
    }
  labels = NULL;
  numLabels = 0;
  i = 0;
  while (strlen(symtab[i].symbol) != 0) {
    AddLabel(symtab[i].symbol, symtab[i].value);
    i++;
    }
  if (!Pass(1,argv[1])) {
    WriteLn("Assembly error. Aborting");
    return 1;
    }
  if (!Pass(2,argv[1])) {
    WriteLn("Assembly error. Aborting");
    return 1;
    }
  file = fopen("core.bin","w");
  for (i=0; (UInt32)i<address; i++)
    fprintf(file,"%08x\n",program[i]);
  fclose(file);

  if (labels != NULL) free(labels);
  return 0;
  }

