/**
 * @file InstructionJGTZ.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include "../../include/Instrucciones/InstructionJGTZ.h"
#include "../../include/RAMachine.h"

InstructionJGTZ::InstructionJGTZ(int line, std::string tag, std::string operation, Tag* jumpTag) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  jumpTag_ = jumpTag;
}

void InstructionJGTZ::show() {
  std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << jumpTag_->getId() <<
  " (line " << jumpTag_->getStartLine() <<")>\n";
}

int InstructionJGTZ::execute(RAMachine& ram) {
  if (ram.readMemory(0) > 0) {
    return jumpTag_->getStartLine() - 1;
  } else {
    return ram.getPc() + 1;
  }
}