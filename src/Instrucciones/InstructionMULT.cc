#include "../../include/Instrucciones/InstructionMULT.h"

InstructionMULT::InstructionMULT(int line, std::string tag, std::string operation, char opType, std::string operand) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  opType_ = opType;
  operand_ = operand;
}

void InstructionMULT::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << opType_ << ' ' << operand_ << ">\n";
}