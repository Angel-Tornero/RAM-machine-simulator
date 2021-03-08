/**
 * @file Program.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include <cstring>
#include <vector>
#include <map>
#include "Instruction.h"
#include "Tag.h"

/**
 * @class Program
 * 
 */
class Program {
  private:
    std::vector<Instruction*> instructions_;
    std::vector<Tag*> tags_;
    std::string fileName_;

  public:
    /**
     * @brief Construct a new Program object
     * 
     * @param fileName 
     */
    Program(std::string fileName);

    /**
     * @brief Destroy the Program object
     * 
     */
    ~Program();

    /**
     * @brief Loads the instructions of the ram program on a vector (attribute)
     * 
     * @param fileName 
     */
    void load(std::string fileName);

    /**
     * @brief Converts a file into a string (friend method)
     * 
     * @param fileName 
     * @return std::string 
     */
    friend std::string fileToString(std::string fileName);

    /**
     * @brief Get the tag from a RAM code line if exists
     * 
     * @param line 
     * @return std::string 
     */
    friend std::string getTag(std::string line);

    /**
     * @brief Parses all the instructions in the given RAM code (string format) and
     * assembles them
     * 
     * @param strFile 
     */
    void parseInstructions(std::string strFile);

    /**
     * @brief Creates a Normal Instruction object (instruction with numeric operand)
     * 
     * @param opCode 
     * @param line 
     * @param tag 
     * @param opType 
     * @param operand 
     * @return Instruction* 
     */
    Instruction* createNormalInstruction(int opCode, int line, std::string tag, char opType, std::string operand);

    /**
     * @brief Create a Jump Instruction object (instruction with a tag as operand)
     * 
     * @param opCode 
     * @param line 
     * @param tag 
     * @param jumpTag 
     * @return Instruction* 
     */
    Instruction* createJumpInstruction(int opCode, int line, std::string tag, Tag* jumpTag);

    /**
     * @brief Get the Instruction from program counter
     * 
     * @param pc 
     * @return Instruction* 
     */
    Instruction* getInstruction(int pc);

    /**
     * @brief Get all the tags of a RAM code mapped with their identifiers and saves them
     * in a the attribute vector for tags.
     * 
     * @param strFile 
     * @return std::map<std::string, Tag*> 
     */
    std::map<std::string, Tag*> getAllTags(std::string strFile);

    /**
     * @brief Prints by terminal all the instructions disassembled. Parameter serves to
     * highlight the current instruction.
     * 
     * @param pc 
     */
    void showInstructions(int pc);

};