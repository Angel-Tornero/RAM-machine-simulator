#include "../Instruction.h"

class InstructionREAD: public Instruction {
  private:
    char opType_;
    std::string operand_;
  public:
    InstructionREAD(int line, std::string tag, std::string operation, char opType, std::string operand);

    void show();
};