#include "../Instruction.h"

class InstructionHALT: public Instruction {
  public:
    InstructionHALT(int line, std::string tag, std::string operation);
    ~InstructionHALT()=default;

    void show();
    int execute(RAMachine& ram);
};