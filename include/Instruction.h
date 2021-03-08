#include <string>
#include <iostream>

#ifndef _INSTRUCTION_
#define _INSTRUCTION_

class RAMachine;

class Instruction {
  protected:
    int line_;
    std::string tag_;
    std::string operation_;
  
  public:
    Instruction() {}
    virtual int execute(RAMachine& ram)=0;
    void printOperation();
    virtual void show()=0;
};

#endif