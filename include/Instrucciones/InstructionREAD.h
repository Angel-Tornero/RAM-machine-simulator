#include "../Instruction.h"

class InstructionREAD: public Instruction {
  private:
    char opType_;
    int operand_;
  public:
    InstructionREAD(int line, std::string tag, std::string operation, char opType, int operand);
    ~InstructionREAD()=default;

    void show();
    int execute(RAMachine& ram);
};