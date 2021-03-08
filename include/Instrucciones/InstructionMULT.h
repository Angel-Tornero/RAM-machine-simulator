/**
 * @file InstructionMULT.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include "../Instruction.h"

/**
 * @class InstructionMULT
 * 
 */
class InstructionMULT: public Instruction {
  private:
    char opType_;
    int operand_;
  public:
    /**
     * @brief Construct a new InstructionMULT object
     * 
     * @param line 
     * @param tag 
     * @param operation 
     * @param opType 
     * @param operand 
     */
    InstructionMULT(int line, std::string tag, std::string operation, char opType, int operand);
    
    /**
     * @brief Destroy the InstructionMULT object
     * 
     */
    ~InstructionMULT()=default;

    /**
     * @brief Prints by terminal the instruction disassembled
     * 
     */
    void show();
    
    /**
     * @brief Executes the instruction MULT
     * 
     * @param ram The RAMachine where the instruction is going to be executed. This allows the instruction to
     * read or to write the tapes and memory. 
     * @return int returns the program counter for the following instruction
     */
    int execute(RAMachine& ram);
};