#include "../Instruction.h"
#include "../Tag.h"

class InstructionJGTZ: public Instruction {
  private:
    Tag* jumpTag_;
  public:
    InstructionJGTZ(int line, std::string tag, std::string operation, Tag* jumpTag);
    ~InstructionJGTZ()=default;
    
    void show();
    int execute(RAMachine& ram);
};
