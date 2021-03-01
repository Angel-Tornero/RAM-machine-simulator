#include "input_tape_t.h"
#include "output_tape_t.h"
#include "program_t.h"
#include "memory_t.h"
#include <string>

class ram_t {

  private:
    program_t* program_;
    input_tape_t* inputTape_;
    output_tape_t* outputTape_;
    memory_t* memory_;
  
  public:
    ram_t(std::string program, std::string inputTape, std::string outputTape);
};