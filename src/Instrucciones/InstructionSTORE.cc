/**
 * @file InstructionSTORE.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include "../../include/Instrucciones/InstructionSTORE.h"
#include "../../include/RAMachine.h"

InstructionSTORE::InstructionSTORE(int line, std::string tag, std::string operation, char opType, int operand) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  opType_ = opType;
  operand_ = operand;
}

void InstructionSTORE::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << opType_ << ' ' << operand_ << ">\n";
}

int InstructionSTORE::execute(RAMachine& ram) {
  int position;
  int value;
  switch(opType_) {
    case 'd':
      position = operand_;
      ram.writeMemory(position, ram.readMemory(0));
      break;
    case '*':
      position = ram.readMemory(operand_);
      ram.writeMemory(position, ram.readMemory(0));
      break;
    case '=':
      std::cerr << "[!] Invalid option " << opType_ << " on instruction ";
      show();
      ram.halt();
  }
  return ram.getPc() + 1;
}