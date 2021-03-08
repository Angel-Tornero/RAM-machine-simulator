/**
 * @file Instruction.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include <string>
#include <iostream>

#ifndef _INSTRUCTION_
#define _INSTRUCTION_

class RAMachine;

/**
 * @class Instruction
 * 
 */
class Instruction {
  protected:
    int line_;
    std::string tag_;
    std::string operation_;
  
  public:
    /**
     * @brief Construct a new Instruction object
     * 
     */
    Instruction()=default;

    /**
     * @brief Destroy the Instruction object
     * 
     */
    virtual ~Instruction()=default;

    /**
     * @brief Executes the instruction (virtual method)
     * 
     * @param ram The RAMachine where the instruction is going to be executed. This allows the instruction to
     * read or to write the tapes and memory. 
     * @return int returns the program counter for the following instruction
     */
    virtual int execute(RAMachine& ram)=0;

    /**
     * @brief Prints by terminal the instruction disassembled (virtual method)
     * 
     */
    virtual void show()=0;
};

#endif