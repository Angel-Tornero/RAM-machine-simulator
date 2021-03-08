#include "../include/Memory.h"
#include <iostream>

void Memory::write(int pos, int value) {
  if (register_.size() <= pos) {
    register_.resize(pos + 1);
  }
  register_[pos] = value;
}

int Memory::read(int pos) {
  if (register_.size() <= pos) {
    return 0;
  }
  return register_[pos];
}

void Memory::show() {
  std::cout << "Memory:\n";
  for (int i = 0; i < register_.size(); i++) {
    std::cout << 'r' << i << " = [" << register_[i] << "]\n";
  }
}
