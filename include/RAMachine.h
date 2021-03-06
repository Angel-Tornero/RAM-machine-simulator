#include "InputTape.h"
#include "OutputTape.h"
#include "Program.h"
#include "Memory.h"
#include <string>

class RAMachine {

  private:
    Program* program_;
    InputTape* inputTape_;
    OutputTape* outputTape_;
    Memory* memory_;
  
  public:
    RAMachine(std::string program, std::string inputTape, std::string outputTape);
};