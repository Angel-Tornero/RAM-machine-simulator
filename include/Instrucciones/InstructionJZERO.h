#include "../Instruction.h"

class InstructionJZERO: public Instruction {
  private:
    std::string operand_;
    int tagStartLine_;
  public:
    InstructionJZERO(int line, std::string tag, std::string operation, std::string operand, int tagStartLine);

    void show();
    void execute(RAMachine ram);
};