#include <cstring>
#include <vector>
#include "Instruction.h"

class Program {
  private:
    std::vector<Instruction*> instructions_;
    std::string fileName_;

  public:
    Program(std::string fileName);
    void load(std::string fileName);
    friend std::string fileToString(std::string fileName);
    friend std::string getTag(std::string line);
    void readInstructions(std::string strFile);
    Instruction* createNormalInstruction(int opCode, int line, std::string tag, char opType, std::string operand);
    Instruction* createJumpInstruction(int opCode, int line, std::string tag, std::string operand, int tagStartLine);
    Instruction* runInstructions();

    void showInstructions();

};