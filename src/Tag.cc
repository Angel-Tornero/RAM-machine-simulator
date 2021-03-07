#include "../include/Tag.h"

Tag::Tag(int sl, std::string id) {
  id_ = id;
  startLine_ = sl;
}

void Tag::setStartLine(int sl) {
  startLine_ = sl;
}

int Tag::getStartLine() {
  return startLine_;
}

std::string Tag::getId() {
  return id_;
}