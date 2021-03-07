#include "../Instruction.h"

class InstructionSUB: public Instruction {
  private:
    char opType_;
    int operand_;
  public:
    InstructionSUB(int line, std::string tag, std::string operation, char opType, int operand);

    void show();
    int execute(RAMachine& ram);
};