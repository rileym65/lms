#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "types.h"

class Vehicle;
class Ins;

class Computer {
  protected:
    Vehicle *vehicle;
    Ins     *ins;
    Boolean *running;
    Boolean p_running;
    Boolean vn_running;
    Boolean input;
    Boolean err;
    Int8    prog;
    Int8    noun;
    Int8    verb;
    Int8    nounIn;
    Int8    verbIn;
    Int8    inputMode;
    UInt32  p_stack[256];
    UInt32  vn_stack[256];
    UInt32 *stack;
    Int16   p_sp;
    Int16   vn_sp;
    Int16  *sp;
    UInt32  *rom;
    UInt32  romLength;
    Double  regs[256];
    Vector  vres;
    Int32   p_pc;
    Int32   vn_pc;
    Int32  *pc;
    Double  read(UInt16 addr);
    void    write(UInt16 addr,Double value);
    Vector  readVector(UInt16 addr);
    void    writeVector(UInt16 addr,Vector v);
    Boolean exec(UInt32 cmd);
    void    addOpcode(UInt16 addr,UInt32 opcode);
    void    loadDefaultProgram();
    Boolean loadCoreFile();
    Int32   findProgram(UInt32 code);
    void    Push(UInt32 v);
  public:
    Computer(Vehicle* v);
    virtual ~Computer();
    virtual char* Prog();
    virtual char* Noun();
    virtual char* Verb();
    virtual char* Reg(UInt8 n);
    virtual Boolean Running();
    virtual Boolean Input();
    virtual Boolean Err();
    virtual void PCycle();
    virtual void VnCycle();
    virtual void Reset();
    virtual void ProcessKey(Int32 key);
    virtual UInt32 Check();
    virtual void Save(FILE* file);
    virtual void Load(FILE* file);
  };

#endif

