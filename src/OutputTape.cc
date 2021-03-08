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
  std::cout << 'y' << values_.size() << "= [] *\n\n";
}

void OutputTape::outputTapeToFile() {
  std::fstream outFile;
  int value;

  outFile.open(fileName_.c_str(), std::ios::out);

  if (outFile.fail()) {
    std::cerr << "File does not exist (outFile). This is the output tape: \n";
    show();
    exit(0);
  }

  for (int i = 0; i < values_.size(); i++) {
    outFile << values_[i] << ' ';
  }
  outFile.close();
}