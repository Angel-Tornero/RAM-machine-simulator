#include "../../include/Instrucciones/InstructionJUMP.h"
#include "../../include/RAMachine.h"

InstructionJUMP::InstructionJUMP(int line, std::string tag, std::string operation, Tag* jumpTag) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  jumpTag_ = jumpTag;
}

void InstructionJUMP::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << jumpTag_->getId() <<
  " (line " << jumpTag_->getStartLine() <<")>\n";
}

int InstructionJUMP::execute(RAMachine& ram) {
  return jumpTag_->getStartLine() - 1;
}
