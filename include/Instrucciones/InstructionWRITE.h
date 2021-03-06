#include "../Instruction.h"

class InstructionWRITE: public Instruction {
  private:
    char opType_;
    std::string operand_;
  public:
    InstructionWRITE(int line, std::string tag, std::string operation, char opType, std::string operand);

    void show();
};