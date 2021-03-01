#include <cstring>
#include <vector>
#include "instruction_t.h"

class program_t {
  private:
    std::vector<instruction_t*> instructions_;
    std::string fileName_;

  public:
    program_t(std::string fileName);
    void load(std::string fileName);
    friend std::string fileToString(std::string fileName);
    friend std::string getTag(std::string line);
    void readInstructions(std::string strFile);

    void showInstructions();

};