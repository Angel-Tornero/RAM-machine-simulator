#include <string>
#include <vector>

#ifndef _TAPE_
#define _TAPE_

class Tape {

  protected:
    std::vector<int> values_;
    std::string fileName_;
    int index_;
  
  public:
    ~Tape()=default;

};

#endif