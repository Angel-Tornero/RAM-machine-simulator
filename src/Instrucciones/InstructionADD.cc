#include "../../include/Instrucciones/InstructionADD.h"

InstructionADD::InstructionADD(int line, std::string tag, std::string operation, char opType, std::string operand) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  opType_ = opType;
  operand_ = operand;
}

void InstructionADD::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << opType_ << ' ' << operand_ << ">\n";
}