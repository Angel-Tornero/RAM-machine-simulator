#include "../include/InputTape.h"
#include <fstream>
#include <iostream>

InputTape::InputTape(std::string fileName) {
  
  load(fileName);
  index_ = 0;
}

void InputTape::load(std::string fileName) {
  fileName_ = fileName;
  std::fstream inFile;
  int value;

  inFile.open(fileName.c_str(), std::ios::in);

  if (inFile.fail()) {
    std::cerr << "File " << fileName << " does not exist (input tape).\n";
    exit(0);
  } 

  values_.clear();
  while (inFile >> value) {
    values_.push_back(value);
  }
  inFile.close();
}

void InputTape::show() {
  std::cout << "Input tape:\n";
  for (int i = 0; i < values_.size(); i++) {
    std::cout << 'x' << i + 1 << " = [" << values_[i] << "]" << ((index_ == i)? " *\n": "\n");
  }
}

int InputTape::readValue() {
  return values_[index_++];

}
