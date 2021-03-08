#include "../include/Program.h"
#include "../include/Instrucciones/InstructionADD.h"
#include "../include/Instrucciones/InstructionDIV.h"
#include "../include/Instrucciones/InstructionHALT.h"
#include "../include/Instrucciones/InstructionJGTZ.h"
#include "../include/Instrucciones/InstructionJUMP.h"
#include "../include/Instrucciones/InstructionJZERO.h"
#include "../include/Instrucciones/InstructionLOAD.h"
#include "../include/Instrucciones/InstructionMULT.h"
#include "../include/Instrucciones/InstructionREAD.h"
#include "../include/Instrucciones/InstructionSTORE.h"
#include "../include/Instrucciones/InstructionSUB.h"
#include "../include/Instrucciones/InstructionWRITE.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>
#include <tuple>

Program::Program(std::string fileName) {
  load(fileName);
}

std::string fileToString(std::string fileName) {
  std::ifstream inFile;
  std::string aux;
  std::string strFile = "";
  inFile.open(fileName);

  if (inFile.fail()) {
    std::cerr << "File " << fileName << " does not exist (ram program).\n";
    exit(0);
  }
  while(!inFile.eof()) {
    getline(inFile, aux);
    if (aux[0] == ';' || aux.size() == 0) {
      continue;
    }
    strFile += aux + "\n";
  }
  inFile.close();
  return strFile;
}

void Program::load(std::string fileName) {
  fileName_ = fileName;
  std::string strFile = fileToString(fileName);
  parseInstructions(strFile);
}


std::string getTag(std::string line) {
  std::string tag = "";
  int pos = 0;
  if (line.find(":") != std::string::npos) {
    while(line[pos] != ':') {
      tag.push_back(line[pos]);
      pos++;
    }
  }
  return tag;
}

void Program::parseInstructions(std::string strFile) {
  std::transform(strFile.begin(), strFile.end(), strFile.begin(), ::toupper);
  std::vector<std::string> normalOperations = {"LOAD", "STORE", "ADD", "SUB", "MULT", "DIV", "READ", "WRITE"};
  std::vector<std::string> jumpOperations = {"JUMP", "JGTZ", "JZERO"};
  std::string copyStrFile = strFile;
  std::map<std::string, Tag*> map = getAllTags(copyStrFile);
  bool newTag;
  int line = 1;
  int opCode;
  Instruction* newInstruction;
  char* input = (char*) strFile.c_str();
  char* token = std::strtok(input, "\n");
  std::string strLine;
  std::string currentTag = "MAIN";
  std::string tag;
  std::string opWord;
  std::string operand;
  char operandType;

  while (token != NULL) {
    newTag = false;
    opWord = "";
    strLine = token;
    tag = getTag(strLine);

    if (tag != "") {
      currentTag = tag;
      newTag = true;
    }
    strFile = token;
    std::istringstream iss(strFile);
    iss >> opWord;

    if (newTag) {
      iss >> opWord;
    }
    if (opWord == ":") {
      iss >> opWord;
    }

    if (find(normalOperations.begin(), normalOperations.end(), opWord) != normalOperations.end()) {
      opCode = std::distance(normalOperations.begin(), std::find(normalOperations.begin(), normalOperations.end(), opWord));
      iss >> operand;
      if (operand[0] == '*' || operand[0] == '=') {
        operandType = operand[0];
        operand.erase(operand.begin());
        if (std::regex_match(operand, std::regex("([0-9])+"))) {
          newInstruction = createNormalInstruction(opCode, line, currentTag, operandType, operand);
        } else {
          std::cerr << "[!] An error occurred in " << fileName_ << " file:\n";
          std::cerr << "Invalid operand <" << operand<< "> on line " << line << ". Must be an integer.\n";
          exit(-1);
        }
      } else if (std::regex_match(operand, std::regex("([0-9])+"))) {
        operandType = 'd';
        newInstruction = createNormalInstruction(opCode, line, currentTag, operandType, operand);
      } else {
          std::cerr << "[!] An error occurred in " << fileName_ << " file:\n";
          std::cerr << "Invalid operand <" << operand<< "> on line " << line << ". Must be an integer.\n";
          exit(-1);
        }
    } else if (find(jumpOperations.begin(), jumpOperations.end(), opWord) != jumpOperations.end()) {
        opCode = std::distance(jumpOperations.begin(), std::find(jumpOperations.begin(), jumpOperations.end(), opWord));
        iss >> operand;
        if (map[operand] == NULL) {
          std::cerr << "[!] An error occurred in file " << fileName_ << " file:\n";
          std::cerr << "Invalid jump on line " << line << ". Tag [" << operand << "] does not exist. \n";
          exit(-1);
        }
        newInstruction = createJumpInstruction(opCode, line, currentTag, map[operand]);
    } else if (opWord.find("HALT") != std::string::npos) {
        newInstruction = new InstructionHALT(line, currentTag, "HALT");
    } else {
        std::cerr << "[!] An error occurred in " << fileName_ << " file:\n";
        std::cerr << "Not recognized instruction on line " << line << ". Instruction <" << opWord << "> does not exist. \n";
          exit(-1);
    }
    line++;
    instructions_.push_back(newInstruction);
    token = std::strtok(NULL, "\n");
  }
}

void Program::showInstructions(int pc) {
  for (int i = 0; i < instructions_.size(); i++) {
    if (pc == i) {
      std::cout << "\e[1m";
    }
    instructions_[i]->show();
    std::cout << "\e[0m";
  }
}

Instruction* Program::createNormalInstruction(int opCode, int line, std::string tag, char opType, std::string operand) {
  int numericOperand = stoi(operand);
  switch(opCode) {
    case 0:
      return new InstructionLOAD(line, tag, "LOAD", opType, numericOperand);
    case 1:
      return new InstructionSTORE(line, tag, "STORE", opType, numericOperand);
    case 2:
      return new InstructionADD(line, tag, "ADD", opType, numericOperand);
    case 3:
      return new InstructionSUB(line, tag, "SUB", opType, numericOperand);
    case 4:
      return new InstructionMULT(line, tag, "MULT", opType, numericOperand);
    case 5:
      return new InstructionDIV(line, tag, "DIV", opType, numericOperand);
    case 6:
      return new InstructionREAD(line, tag, "READ", opType, numericOperand);
    case 7:
      return new InstructionWRITE(line, tag, "WRITE", opType, numericOperand);
  }
}

Instruction* Program::createJumpInstruction(int opCode, int line, std::string tag, Tag* jumpTag) {
  switch(opCode) {
    case 0:
      return new InstructionJUMP(line, tag, "JUMP", jumpTag);
    case 1:
      return new InstructionJGTZ(line, tag, "JGTZ", jumpTag);
    case 2:
      return new InstructionJZERO(line, tag, "JZERO", jumpTag);
  }
}

Instruction* Program::getInstruction(int pc) {
  return instructions_[pc];
}

std::map<std::string, Tag*> Program::getAllTags(std::string strFile) {
  std::map<std::string, Tag*> map;
  int line = 1;
  char* input = (char*) strFile.c_str();
  char* token = std::strtok(input, "\n");
  std::string strLine;
  std::string tag;
  while (token != NULL) {
    strLine = token;
    tag = getTag(strLine);
    if (tag != "") {
      map.insert(make_pair(tag, new Tag(line, tag)));
    }
    line++;
    token = std::strtok(NULL, "\n");
  }
  return map;
}
