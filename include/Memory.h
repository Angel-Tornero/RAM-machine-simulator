#include <vector>

class Memory {
  private:
    std::vector<int> register_;
  
  public:
    Memory() {}
    void write(int pos, int value);
    int read(int pos);

};