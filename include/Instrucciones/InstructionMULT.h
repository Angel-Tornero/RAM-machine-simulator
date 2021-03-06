#include "../Instruction.h"

class InstructionMULT: public Instruction {
  private:
    char opType_;
    std::string operand_;
  public:
    InstructionMULT(int line, std::string tag, std::string operation, char opType, std::string operand);

    void show();
};