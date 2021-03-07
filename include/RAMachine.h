#include "InputTape.h"
#include "OutputTape.h"
#include "Program.h"
#include "Memory.h"

#include <string>

#ifndef _RAMACHINE_
#define _RAMACHINE_

class RAMachine {

  private:
    Program* program_;
    InputTape* inputTape_;
    OutputTape* outputTape_;
    Memory* memory_;
    int pc_;
    bool halt_;
  
  public:
    RAMachine(Program*, InputTape*, OutputTape*);
    void runProgram();
    void increasePC();
    int readFromInputTape();
    void writeOutputTape(int value);
    void writeMemory(int pos, int value);
    int readMemory(int pos);
    void jump(int line);
    void halt();
    void showOutputTape();
    int getPc();
    void showMemory();
};

#endif