#include "../Instruction.h"

class InstructionDIV: public Instruction {
  private:
    char opType_;
    int operand_;
  public:
    InstructionDIV(int line, std::string tag, std::string operation, char opType, int operand);
    ~InstructionDIV()=default;

    void show();
    int execute(RAMachine& ram);
};