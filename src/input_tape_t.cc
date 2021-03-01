#include "../include/input_tape_t.h"
#include <fstream>
#include <iostream>

input_tape_t::input_tape_t(std::string fileName) {
  
  load(fileName);
}

void input_tape_t::load(std::string fileName) {
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

void input_tape_t::show() {
  for (int i = 0; i < values_.size(); i++) {
    std::cout << values_[i]<< '\n';
  }
}