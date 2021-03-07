#include <cstring>
#include <vector>
#include <map>
#include "Instruction.h"
#include "Tag.h"

class Program {
  private:
    std::vector<Instruction*> instructions_;
    std::vector<Tag*> tags_;
    std::string fileName_;

  public:
    Program(std::string fileName);
    void load(std::string fileName);
    friend std::string fileToString(std::string fileName);
    friend std::string getTag(std::string line);
    void readInstructions(std::string strFile);
    Instruction* createNormalInstruction(int opCode, int line, std::string tag, char opType, std::string operand);
    Instruction* createJumpInstruction(int opCode, int line, std::string tag, Tag* jumpTag);
    Instruction* getInstruction(int pc);
    std::vector<Tag*> getAllTags(std::string strFile);
    Tag* findTag(std::string id, std::vector<Tag*> vector);

    void showInstructions();

};