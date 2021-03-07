#include "../include/Memory.h"

void Memory::write(int pos, int value) {
  if (register_.size() <= pos) {
    register_.resize(pos + 1);
  }
  register_[pos] = value;
}

int Memory::read(int pos) {
  return register_[pos];
}