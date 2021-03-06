#include "../Instruction.h"

class InstructionSTORE: public Instruction {
  private:
    char opType_;
    std::string operand_;
  public:
    InstructionSTORE(int line, std::string tag, std::string operation, char opType, std::string operand);

    void show();
};