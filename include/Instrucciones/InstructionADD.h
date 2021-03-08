#include "../Instruction.h"

class InstructionADD: public Instruction {
  private:
    char opType_;
    int operand_;
  public:
    InstructionADD(int line, std::string tag, std::string operation, char opType, int operand);
    ~InstructionADD()=default;

    void show();
    int execute(RAMachine& ram);
};