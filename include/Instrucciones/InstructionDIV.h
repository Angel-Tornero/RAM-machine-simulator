#include "../Instruction.h"

class InstructionDIV: public Instruction {
  private:
    char opType_;
    std::string operand_;
  public:
    InstructionDIV(int line, std::string tag, std::string operation, char opType, std::string operand);

    void show();
};