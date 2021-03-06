#include "../Instruction.h"

class InstructionJGTZ: public Instruction {
  private:
    std::string operand_;
  public:
    InstructionJGTZ(int line, std::string tag, std::string operation, std::string operand);

    void show();
};