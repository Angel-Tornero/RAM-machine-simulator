#include "Tape.h"

class InputTape: public Tape {

  public:
    InputTape(std::string fileName);
    void load(std::string fileName);
    void show();

};