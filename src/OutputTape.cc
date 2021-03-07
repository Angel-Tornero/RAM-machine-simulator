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
  for (int i = 0; i < values_.size(); i++) {
    std::cout << values_[i]<< '\n';
  }
}