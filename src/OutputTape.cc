/**
 * @file OutputTape.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include "../include/OutputTape.h"
#include <fstream>
#include <iostream>

OutputTape::OutputTape(std::string fileName) {
  fileName_ = fileName;
}

void OutputTape::write(int value) {
  values_.push_back(value);
}

void OutputTape::show() {
  std::cout << "Output tape:\n";
  for (int i = 0; i < values_.size(); i++) {
    std::cout << 'y' << i + 1 << "= [" << values_[i] << "]" << '\n';
  }
  std::cout << 'y' << values_.size() << " = [] *\n";
}

void OutputTape::outputTapeToFile() {
  std::fstream outFile;
  int value;

  outFile.open(fileName_.c_str(), std::ios::out);

  if (outFile.fail()) {
    std::cerr << "File "<< fileName_ << " could not be opened (output file). This is the output tape: \n";
    show();
    return;
  }

  for (int i = 0; i < values_.size(); i++) {
    outFile << values_[i] << ' ';
  }
  outFile.close();
}