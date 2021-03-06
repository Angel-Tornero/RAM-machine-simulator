#include "../Instruction.h"

class InstructionSUB: public Instruction {
  private:
    char opType_;
    std::string operand_;
  public:
    InstructionSUB(int line, std::string tag, std::string operation, char opType, std::string operand);

    void show();
};