#include "../include/instruction_t.h"

instruction_t::instruction_t(int line, std::string tag, std::string operation, std::string opType, std::string operand) {
  line_ = line;
  tag_ = tag;
  operation_ = operation;
  opType_ = opType;
  operand_ = operand;
}

