#include "../include/RAMachine.h"

RAMachine::RAMachine(Program* program, InputTape* inputTape, OutputTape* outputTape, bool debug) {
  program_ = program;
  inputTape_ = inputTape;
  outputTape_ = outputTape;
  memory_ = new Memory;
  pc_ = 0;
  halt_ = false;
  debug_ = debug;
}

void RAMachine::runProgram() {
  if (debug_) {
    debugMode();
  } else {
    normalMode();
  }
}

void RAMachine::normalMode() {
  int counter = 0;
  while(!halt_) {
    pc_ = program_->getInstruction(pc_)->execute(*this);
    counter++;
  }
  printOutputTape();
  std::cout << "Instructions executed: " << counter << '\n';
}

void RAMachine::debugMode() {
  std::string commandLine;
  char command;
  bool exit = 0;
  while(!exit) {
    std::cout << "> ";
    std::cin >> commandLine;
    if (commandLine.length() == 1) {
      command = commandLine[0];
    } else {
      std::cout << "These are the valid commands:\n";
      helpDebugMode();
      continue;
    }
    switch (command) {
      case 'r':
        showMemory();
        break;
      case 't':
        if (halt_) {
          std::cout << "Trace not available now. Program is halted.\n";
          break;
        }
        pc_ = program_->getInstruction(pc_)->execute(*this);
        break;
      case 'e':
        if (halt_) {
          std::cout << "Execute not available now. Program is halted.\n";
          break;
        }
        while(!halt_) {
          pc_ = program_->getInstruction(pc_)->execute(*this);
        }
        break;
      case 's':
        program_->getInstruction(pc_)->show();
        std::cout << '\n';
        break;
      case 'i':
        showInputTape();
        break;
      case 'o':
        showOutputTape();
        break;
      case 'h':
        helpDebugMode();
        break;
      case 'x':
        exit = true;
        break;
    }
  }
}

void RAMachine::helpDebugMode() {
  std::cout << "r: view registers\nt: trace\ne: execute\ns: disassemble\ni: view input tape\n";
  std::cout << "o: view output tape\nh: help\nx: exit\n";
}

int RAMachine::readFromInputTape() {
  return inputTape_->readValue();
}

void RAMachine::writeOnOutputTape(int value) {
  return outputTape_->write(value);
}


void RAMachine::writeMemory(int pos, int value) {
  memory_->write(pos, value);
}

int RAMachine::readMemory(int pos) {
  return memory_->read(pos);
}

void RAMachine::halt() {
  halt_ = true;
}

void RAMachine::showOutputTape() {
  outputTape_->show();
}

void RAMachine::showInputTape() {
  inputTape_->show();
}

int RAMachine::getPc() {
  return pc_;
}

void RAMachine::showMemory() {
  memory_->show();
}

void RAMachine::printOutputTape() {
  outputTape_->outputTapeToFile();
}