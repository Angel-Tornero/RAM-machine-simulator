/**
 * @file InstructionHALT.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include "../../include/Instrucciones/InstructionHALT.h"
#include "../../include/RAMachine.h"

InstructionHALT::InstructionHALT(int line, std::string tag, std::string operation) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
}

void InstructionHALT::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ">\n";
}

int InstructionHALT::execute(RAMachine& ram) {
  ram.halt();
  return ram.getPc();
}