#include "../Instruction.h"

class InstructionMULT: public Instruction {
  private:
    char opType_;
    int operand_;
  public:
    InstructionMULT(int line, std::string tag, std::string operation, char opType, int operand);
    ~InstructionMULT()=default;

    void show();
    int execute(RAMachine& ram);
};