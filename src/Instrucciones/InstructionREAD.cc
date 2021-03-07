#include "../../include/Instrucciones/InstructionREAD.h"
#include "../../include/RAMachine.h"

InstructionREAD::InstructionREAD(int line, std::string tag, std::string operation, char opType, int operand) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  opType_ = opType;
  operand_ = operand;
}

void InstructionREAD::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << opType_ << ' ' << operand_ << ">\n";
}

void InstructionREAD::execute(RAMachine ram) {
  int readValue = ram.readFromTape();
  int position;
  switch(opType_) {
    case 'd':
      position = operand_;
      ram.writeMemory(readValue, position);
      break;
    case '*':
      position = ram.readMemory(readValue);
      ram.writeMemory(readValue, position);
      break;
  }
}