#include <string>
#include <iostream>

class instruction_t {
  private:
    int line_;
    std::string tag_;
    std::string operation_;
    std::string opType_;
    std::string operand_;
  public:
    instruction_t(int line, std::string tag, std::string operation, std::string opType, std::string operand);

    void show() {
      std::cout << '[' << tag_ << "] at line " << line_ << " <" << operation_ << ' ' << opType_ << ' ' << operand_ << ">\n";
    }
};