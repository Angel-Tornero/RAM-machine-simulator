#include "../Instruction.h"

class InstructionJZERO: public Instruction {
  private:
    std::string operand_;
  public:
    InstructionJZERO(int line, std::string tag, std::string operation, std::string operand);

    void show();
};