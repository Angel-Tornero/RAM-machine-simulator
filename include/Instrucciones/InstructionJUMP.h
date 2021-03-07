#include "../Instruction.h"
#include "../Tag.h"

class InstructionJUMP: public Instruction {
  private:
    Tag* jumpTag_;
  public:
    InstructionJUMP(int line, std::string tag, std::string operation, Tag* jumpTag);
    void show();
    int execute(RAMachine& ram);
};