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
    bool debug_;
  
  public:
    RAMachine(Program*, InputTape*, OutputTape*, bool);
    void runProgram();
    void normalMode();
    void debugMode();
    void helpDebugMode();

    int readFromInputTape();
    void writeOnOutputTape(int value);
    void writeMemory(int pos, int value);
    int readMemory(int pos);
    void halt();
    void showOutputTape();
    void showInputTape();
    int getPc();
    void showMemory();
    void printOutputTape();
};

#endif