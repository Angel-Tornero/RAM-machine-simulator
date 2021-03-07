#include "../../include/Instrucciones/InstructionJUMP.h"

InstructionJUMP::InstructionJUMP(int line, std::string tag, std::string operation, std::string operand, int tagStartLine) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  operand_ = operand;
  tagStartLine_ = tagStartLine;
}

void InstructionJUMP::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << operand_ << ">\n";
}