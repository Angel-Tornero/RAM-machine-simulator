#include "Tape.h"

class InputTape: public Tape {

  public:
    InputTape(std::string fileName);
    ~InputTape()=default;

    void load(std::string fileName);
    void show();
    int readValue();

};