#include "../Instruction.h"

class InstructionJGTZ: public Instruction {
  private:
    std::string operand_;
    int tagStartLine_;
  public:
    InstructionJGTZ(int line, std::string tag, std::string operation, std::string operand, int tagStartLine);

    void show();
};