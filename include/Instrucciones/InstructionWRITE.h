#include "../Instruction.h"

class InstructionWRITE: public Instruction {
  private:
    char opType_;
    int operand_;
  public:
    InstructionWRITE(int line, std::string tag, std::string operation, char opType, int operand);
    ~InstructionWRITE()=default;

    void show();
    int execute(RAMachine& ram);
};