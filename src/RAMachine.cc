#include "../include/RAMachine.h"

RAMachine::RAMachine(Program* program, InputTape* inputTape, OutputTape* outputTape) {
  program_ = program;
  inputTape_ = inputTape;
  outputTape_ = outputTape;
  memory_ = new Memory;
  pc_ = 0;

  program_->showInstructions();
  inputTape->show();
}

void RAMachine::runProgram() {
  int n = 10;
  while(n != -1) {
    program_->getInstruction(pc_) -> show();
    pc_ = program_->getInstruction(pc_)->execute(*this);
    showMemory();
    n--;
  }
}

void RAMachine::increasePC() {
  pc_++;
  std::cout << pc_ << '\n';
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

void RAMachine::halt() {
  halt_ = true;
}

void RAMachine::showOutputTape() {
  outputTape_->show();
}

int RAMachine::getPc() {
  return pc_;
}

void RAMachine::showMemory() {
  memory_->show();
}