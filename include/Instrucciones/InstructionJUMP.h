/**
 * @file InstructionJUMP.h
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
#include "../Tag.h"

/**
 * @class InstructionJUMP
 * 
 */
class InstructionJUMP: public Instruction {
  private:
    Tag* jumpTag_;
  public:
    /**
     * @brief Construct a new InstructionJUMP object
     * 
     * @param line 
     * @param tag 
     * @param operation 
     * @param opType 
     * @param operand 
     */
    InstructionJUMP(int line, std::string tag, std::string operation, Tag* jumpTag);

    /**
     * @brief Destroy the InstructionJUMP object
     * 
     */
    ~InstructionJUMP()=default;
    
    /**
     * @brief Prints by terminal the instruction disassembled
     * 
     */
    void show();

    /**
     * @brief Executes the instruction JUMP
     * 
     * @param ram The RAMachine where the instruction is going to be executed. This allows the instruction to
     * read or to write the tapes and memory. 
     * @return int returns the program counter for the following instruction
     */
    int execute(RAMachine& ram);
};