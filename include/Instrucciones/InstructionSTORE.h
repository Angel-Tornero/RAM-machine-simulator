#include "../Instruction.h"

class InstructionSTORE: public Instruction {
  private:
    char opType_;
    int operand_;
  public:
    InstructionSTORE(int line, std::string tag, std::string operation, char opType, int operand);
    ~InstructionSTORE()=default;

    void show();
    int execute(RAMachine& ram);
};