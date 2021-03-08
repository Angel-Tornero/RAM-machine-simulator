#include <string>

#ifndef _TAG_
#define _TAG_

class Tag {
  private:
    int startLine_;
    std::string id_;
  
  public:
    Tag(int sl, std::string id);
    ~Tag()=default;
    void setStartLine(int sl);
    int getStartLine();
    std::string getId();
};

#endif