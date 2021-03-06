#include "../Instruction.h"

class InstructionLOAD: public Instruction {
  private:
    char opType_;
    std::string operand_;
  public:
    InstructionLOAD(int line, std::string tag, std::string operation, char opType, std::string operand);

    void show();
};