/**
 * @file InstructionDIV.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include "../../include/Instrucciones/InstructionDIV.h"
#include "../../include/RAMachine.h"

InstructionDIV::InstructionDIV(int line, std::string tag, std::string operation, char opType, int operand) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  opType_ = opType;
  operand_ = operand;
}

void InstructionDIV::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << opType_ << ' ' << operand_ << ">\n";
}

int InstructionDIV::execute(RAMachine& ram) {
  int position;
  int value;
  switch(opType_) {
    case 'd':
      value = ram.readMemory(operand_);
      if (value == 0) {
        std::cerr << "[!] Invalid operation on instruction: ";
        show();
        std::cerr << "Divisor cannot be 0. \n";
        ram.halt();
        break;
      }
      ram.writeMemory(0, ram.readMemory(0) / value);
      break;
    case '*':
      position = ram.readMemory(operand_);
      value = ram.readMemory(position);
      if (value == 0) {
        std::cerr << "[!] Invalid operation on instruction: ";
        show();
        std::cerr << "Divisor cannot be 0. \n";
        ram.halt();
        break;
      }
      ram.writeMemory(0, ram.readMemory(0) / value);
      break;
    case '=':
      value = operand_;
      if (value == 0) {
        std::cerr << "[!] Invalid operation on instruction: ";
        show();
        std::cerr << "Divisor cannot be 0. \n";
        ram.halt();
        break;
      }
      ram.writeMemory(0, ram.readMemory(0) / value);
      break;
  }
  return ram.getPc() + 1;
}