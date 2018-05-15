#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "types.h"

class Vehicle;

class Computer {
  protected:
    Vehicle *vehicle;
    Boolean running;
    Boolean input;
    Boolean err;
    Int8    prog;
    Int8    noun;
    Int8    verb;
    Int8    inputMode;
    UInt32  stack[256];
    Int16   sp;
    UInt32  *rom;
    UInt32  romLength;
    Double  regs[256];
    Vector  vres;
    Double  read(UInt16 addr);
    void    write(UInt16 addr,Double value);
    Vector  readVector(UInt16 addr);
    void    writeVector(UInt16 addr,Vector v);
    Boolean exec(UInt32 cmd);
    Int32   pc;
    void    addOpcode(UInt16 addr,UInt32 opcode);
    void    loadDefaultProgram();
    Boolean loadCoreFile();
    Int32   findProgram(UInt32 code);
  public:
    Computer(Vehicle* v);
    virtual ~Computer();
    virtual char* Prog();
    virtual char* Noun();
    virtual char* Verb();
    virtual char* Reg(Int8 n);
    virtual Boolean Running();
    virtual Boolean Input();
    virtual Boolean Err();
    virtual void Cycle();
    virtual void Reset();
    virtual void ProcessKey(Int32 key);
    virtual UInt32 Check();
    virtual void Save(FILE* file);
    virtual void Load(FILE* file);
  };

#endif

