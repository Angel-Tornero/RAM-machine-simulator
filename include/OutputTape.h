#include "Tape.h"

class OutputTape: public Tape {

  public:
    OutputTape(std::string fileName);
    ~OutputTape()=default;

    void write(int value);
    void show();
    void outputTapeToFile();

};