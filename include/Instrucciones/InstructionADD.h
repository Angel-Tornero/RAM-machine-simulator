#include "../Instruction.h"

class InstructionADD: public Instruction {
  private:
    char opType_;
    std::string operand_;
  public:
    InstructionADD(int line, std::string tag, std::string operation, char opType, std::string operand);

    void show();
};