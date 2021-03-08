/**
 * @file InstructionSTORE.h
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
 * @class InstructionSTORE
 * 
 */
class InstructionSTORE: public Instruction {
  private:
    char opType_;
    int operand_;
  public:
    /**
     * @brief Construct a new InstructionSTORE object
     * 
     * @param line 
     * @param tag 
     * @param operation 
     * @param opType 
     * @param operand 
     */
    InstructionSTORE(int line, std::string tag, std::string operation, char opType, int operand);
    
    /**
     * @brief Destroy the InstructionSTORE object
     * 
     */
    ~InstructionSTORE()=default;

    /**
     * @brief Prints by terminal the instruction disassembled
     * 
     */
    void show();

    /**
     * @brief Executes the instruction STORE
     * 
     * @param ram The RAMachine where the instruction is going to be executed. This allows the instruction to
     * read or to write the tapes and memory. 
     * @return int returns the program counter for the following instruction
     */
    int execute(RAMachine& ram);
};