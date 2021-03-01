#include "../include/ram_t.h"
#include <string>

int main(int argv, char* argc[]) {
  
  std::string ramProgram(argc[1]);
  std::string inputTape(argc[2]);
  std::string outputTape(argc[3]);
  int debug = atoi(argc[4]);

  program_t program(ramProgram);
  input_tape_t tape(inputTape);

  program.showInstructions();
  tape.show();

  //ram_t ramMachine(ramProgram, inputTape, outputTape);
}
