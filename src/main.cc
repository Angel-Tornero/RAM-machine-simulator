#include "../include/RAMachine.h"
#include <string>

int main(int argv, char* argc[]) {
  
  std::string ramProgram(argc[1]);
  std::string inputTape(argc[2]);
  std::string outputTape(argc[3]);
  int debug = atoi(argc[4]);

  Program program(ramProgram);
  InputTape tape(inputTape);

  program.showInstructions();

  //RAMachine ramMachine(ramProgram, inputTape, outputTape);
}
