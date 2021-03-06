#include "../../include/Instrucciones/InstructionJZERO.h"

InstructionJZERO::InstructionJZERO(int line, std::string tag, std::string operation, std::string operand) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  operand_ = operand;
}

void InstructionJZERO::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << operand_ << ">\n";
}