#include <vector>

class Memory {
  private:
    std::vector<int> register_;
  
  public:
    Memory() {}
    ~Memory()=default;
    void write(int pos, int value);
    int read(int pos);
    void show();

};