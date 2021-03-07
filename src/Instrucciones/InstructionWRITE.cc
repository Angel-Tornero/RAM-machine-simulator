#include "../../include/Instrucciones/InstructionWRITE.h"
#include "../../include/RAMachine.h"

InstructionWRITE::InstructionWRITE(int line, std::string tag, std::string operation, char opType, int operand) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  opType_ = opType;
  operand_ = operand;
}

void InstructionWRITE::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << opType_ << ' ' << operand_ << ">\n";
}

void InstructionWRITE::execute(RAMachine ram) {
  int position;
  int value;
  switch(opType_) {
    case 'd':
      value = ram.readMemory(operand_);
      ram.writeOutputTape(value);
      break;
    case '*':
      position = ram.readMemory(operand_);
      value = ram.readMemory(position);
      ram.writeOutputTape(value);
      break;
    case '=':
      value = operand_;
      ram.writeOutputTape(value);
      break;
  }
}