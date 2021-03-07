#include "../../include/Instrucciones/InstructionJZERO.h"
#include "../../include/RAMachine.h"

InstructionJZERO::InstructionJZERO(int line, std::string tag, std::string operation, Tag* jumpTag) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  jumpTag_ = jumpTag;
}

void InstructionJZERO::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << jumpTag_->getId() <<
  " (line " << jumpTag_->getStartLine() <<")>\n";
}

int InstructionJZERO::execute(RAMachine& ram) {
  if (ram.readMemory(0) == 0) {
    return jumpTag_->getStartLine() - 1;
  } else {
    return ram.getPc() + 1;
  }
}
