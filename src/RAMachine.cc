#include "../include/RAMachine.h"

RAMachine::RAMachine(std::string program, std::string inputTape, std::string outputTape) {
  program_ = new Program(program);
  inputTape_ = new InputTape(inputTape);
  outputTape_ = new OutputTape(outputTape);
  memory_ = new Memory;
  pc_ = 0;
}

void RAMachine::runProgram() {
  while(!halt_) {
    program_->getInstruction(pc_)->execute(*this);
  }
}

void RAMachine::increasePC() {
  pc_++;
}

int RAMachine::readFromInputTape() {
  return inputTape_->readValue();
}

void RAMachine::writeOutputTape(int value) {
  return outputTape_->write(value);
}


void RAMachine::writeMemory(int pos, int value) {
  memory_->write(pos, value);
}

int RAMachine::readMemory(int pos) {
  return memory_->read(pos);
}

void RAMachine::jump(int line) {
  pc_ = line;
}