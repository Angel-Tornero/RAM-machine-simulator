#include "Tape.h"

class OutputTape: public Tape {

  public:
    OutputTape(std::string fileName);

    void write(int value);

};