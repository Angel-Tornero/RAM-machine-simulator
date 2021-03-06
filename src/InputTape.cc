#include "../include/InputTape.h"
#include <fstream>
#include <iostream>

InputTape::InputTape(std::string fileName) {
  
  load(fileName);
}

void InputTape::load(std::string fileName) {
  fileName_ = fileName;
  std::fstream inFile;
  int value;

  inFile.open(fileName.c_str(), std::ios::in);

  if (inFile.fail()) {
    std::cerr << "File does not exist (inFile).\n";
    exit(0);
  } 

  values_.clear();
  while (inFile >> value) {
    values_.push_back(value);
  }
  inFile.close();
}

void InputTape::show() {
  for (int i = 0; i < values_.size(); i++) {
    std::cout << values_[i]<< '\n';
  }
}