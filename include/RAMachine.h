/**
 * @file RAMachine.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include "InputTape.h"
#include "OutputTape.h"
#include "Program.h"
#include "Memory.h"

#include <string>

#ifndef _RAMACHINE_
#define _RAMACHINE_

/**
 * @class RAMachine
 * 
 */
class RAMachine {

  private:
    Program* program_;
    InputTape* inputTape_;
    OutputTape* outputTape_;
    Memory* memory_;
    int pc_;
    bool halt_;
    bool debug_;
  
  public:
    /**
     * @brief Construct a new RAMachine object
     * 
     */
    RAMachine(Program*, InputTape*, OutputTape*, bool);

    /**
     * @brief Destroy the RAMachine object
     * 
     */
    ~RAMachine();

    /**
     * @brief Runs the program that was opened in the machine
     * 
     */
    void runProgram();

    /**
     * @brief Runs the program on normal mode (showing the number
     * of performed instructions)
     * 
     */
    void normalMode();

    /**
     * @brief Runs the program on debug mode (opening the debug terminal
     * for this simulator)
     * 
     */
    void debugMode();

    /**
     * @brief Prints the help message of debug mode
     * 
     */
    void helpDebugMode();

    /**
     * @brief Reads next value from input tape
     * 
     * @return int 
     */
    int readFromInputTape();

    /**
     * @brief Writes on output tape the given value
     * 
     * @param value 
     */
    void writeOnOutputTape(int value);

    /**
     * @brief Writes on a memory position the given value
     * 
     * @param pos
     * @param value 
     */
    void writeMemory(int pos, int value);

    /**
     * @brief Reads the value from a memory position 
     * 
     * @param pos 
     * @return int 
     */
    int readMemory(int pos);

    /**
     * @brief Halts the program
     * 
     */
    void halt();

    /**
     * @brief Prints output tape on terminal (showing the position pointed
     * by the machine currently)
     * 
     */
    void showOutputTape();

    /**
     * @brief Prints input tape on terminal (showing the position pointed
     * by the machine currently)
     * 
     */
    void showInputTape();

    /**
     * @brief Get the Program counter
     * 
     * @return int 
     */
    int getPc();

    /**
     * @brief Prints all the memory registers on terminal
     * 
     */
    void showMemory();

    /**
     * @brief Prints output tape on the associated output file
     * 
     */
    void printOutputTape();
};

#endif