/**
 * @file InstructionWRITE.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

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

int InstructionWRITE::execute(RAMachine& ram) {
  int position;
  int value;
  switch(opType_) {
    case 'd':
      if (operand_ == 0) {
        std::cerr <<"[!] Invalid operand on instruction: ";
        show(); 
        ram.halt();
        break;
      }
      value = ram.readMemory(operand_);
      ram.writeOnOutputTape(value);
      break;
    case '*':
      position = ram.readMemory(operand_);
      value = ram.readMemory(position);
      ram.writeOnOutputTape(value);
      break;
    case '=':
      value = operand_;
      ram.writeOnOutputTape(value);
      std::cout << value;
      break;
  }
  return ram.getPc() + 1;
}