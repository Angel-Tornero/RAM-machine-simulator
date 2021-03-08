/**
 * @file InstructionREAD.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

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

int InstructionREAD::execute(RAMachine& ram) {
  int readValue = ram.readFromInputTape();
  int position;
  switch(opType_) {
    case 'd':
      position = operand_;
      ram.writeMemory(position, readValue);
      break;
    case '*':
      position = ram.readMemory(readValue);
      ram.writeMemory(position, readValue);
      break;
    case '=':
      std::cerr << "[!] Invalid option " << opType_ << " on instruction ";
      show();
      ram.halt();
      break;
  }
  return ram.getPc() + 1;
}