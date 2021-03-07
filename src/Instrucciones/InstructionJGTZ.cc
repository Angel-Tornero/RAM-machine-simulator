#include "../../include/Instrucciones/InstructionJGTZ.h"

InstructionJGTZ::InstructionJGTZ(int line, std::string tag, std::string operation, std::string operand, int tagStartLine) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  operand_ = operand;
  tagStartLine_ = tagStartLine;
}

void InstructionJGTZ::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << operand_ << ">\n";
}