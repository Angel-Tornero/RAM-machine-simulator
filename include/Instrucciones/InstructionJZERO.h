#include "../Instruction.h"
#include "../Tag.h"

class InstructionJZERO: public Instruction {
  private:
    Tag* jumpTag_;
  public:
    InstructionJZERO(int line, std::string tag, std::string operation, Tag* jumpTag);
    ~InstructionJZERO()=default;
    
    void show();
    int execute(RAMachine& ram);
};