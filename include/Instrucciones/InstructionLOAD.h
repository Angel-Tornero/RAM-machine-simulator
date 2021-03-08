#include "../Instruction.h"

class InstructionLOAD: public Instruction {
  private:
    char opType_;
    int operand_;
  public:
    InstructionLOAD(int line, std::string tag, std::string operation, char opType, int operand);
    ~InstructionLOAD()=default;
    
    void show();
    int execute(RAMachine& ram);
};