#include "tape_t.h"

class input_tape_t: public tape_t {

  public:
    input_tape_t(std::string fileName);
    void load(std::string fileName);
    void show();

};