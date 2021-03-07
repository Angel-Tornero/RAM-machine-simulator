#include "../../include/Instrucciones/InstructionMULT.h"
#include "../../include/RAMachine.h"

InstructionMULT::InstructionMULT(int line, std::string tag, std::string operation, char opType, int operand) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  opType_ = opType;
  operand_ = operand;
}

void InstructionMULT::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << opType_ << ' ' << operand_ << ">\n";
}

int InstructionMULT::execute(RAMachine& ram) {
  int position;
  int value;
  switch(opType_) {
    case 'd':
      value = ram.readMemory(operand_);
      ram.writeMemory(0, ram.readMemory(0) * value);
      break;
    case '*':
      position = ram.readMemory(operand_);
      value = ram.readMemory(position);
      ram.writeMemory(0, ram.readMemory(0) * value);
      break;
    case '=':
      value = operand_;
      ram.writeMemory(0, ram.readMemory(0) * value);
      break;
  }
  return ram.getPc() + 1;
}