#include "../include/OutputTape.h"
#include <fstream>

OutputTape::OutputTape(std::string fileName) {
  fileName_ = fileName;
}

void OutputTape::write(int value) {
  values_.push_back(value);
}