#include "../include/RAMachine.h"
#include <string>

int main(int argv, char* argc[]) {

  if (argv != 5) {
    std::cout << "You can run the machine by using the following command:\n";
    std::cout << "$ ./ram_sim ram_program.ram input_tape.in output_tape.out debug\n";
    return 0;
  }
  
  std::string ramProgram(argc[1]);
  std::string inputTape(argc[2]);
  std::string outputTape(argc[3]);
  int debug = atoi(argc[4]);

  if (debug != 0 && debug != 1) {
    std::cout << "Last argument must be 0 or 1.\n";
    return 0;
  }
  std::exception error;

  try {
    RAMachine ramMachine(new Program(ramProgram), new InputTape(inputTape), new OutputTape(outputTape), debug);
    ramMachine.runProgram();
  } catch (std::string errorType) {
      std::cerr << errorType;
      return -1;
  }

  return 0;
}
