#include "../../include/Instrucciones/InstructionJZERO.h"
#include "../../include/RAMachine.h"

InstructionJZERO::InstructionJZERO(int line, std::string tag, std::string operation, std::string operand, int tagStartLine) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  operand_ = operand;
  tagStartLine_ = tagStartLine;

}

void InstructionJZERO::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << operand_ << ">\n";
}

void InstructionJZERO::execute(RAMachine ram) {
  if (ram.readMemory(0) == 0) {
    ram.jump(tagStartLine_);
  }
}