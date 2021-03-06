#include <string>
#include <iostream>

#ifndef _INSTRUCTION_
#define _INSTRUCTION_

class Instruction {
  protected:
    int line_;
    std::string tag_;
    std::string operation_;
  
  public:
    Instruction() {}

    virtual void show()=0;
};

#endif