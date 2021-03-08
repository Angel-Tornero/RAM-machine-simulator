/**
 * @file RAMachine.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

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

RAMachine::~RAMachine() {
  delete program_;
  delete inputTape_;
  delete outputTape_;
  delete memory_;
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
          std::cout << "Trace NOT available now. Program is halted.\n";
          break;
        }
        std::cout << "Running next instruction...\n";
        program_->getInstruction(pc_)->show();
        pc_ = program_->getInstruction(pc_)->execute(*this);
        break;
      case 'e':
        if (halt_) {
          std::cout << "Execute NOT available now. Program is halted.\n";
          break;
        }
        std::cout << "Running program...\n";
        while(!halt_) {
          pc_ = program_->getInstruction(pc_)->execute(*this);
        }
        break;
      case 's':
        program_->showInstructions(pc_);
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
        std::cout << "Leaving debugging console...\n";
        exit = true;
        break;
      default:
        std::cout << "These are the valid commands:\n";
        helpDebugMode();
        break;
    }
  }
}

void RAMachine::helpDebugMode() {
  std::cout << "r: view registers\n"
               "t: trace\ne: execute\n"
               "s: disassemble\n"
               "i: view input tape\n"
               "o: view output tape\n"
               "h: help\n"
               "x: exit\n";
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
