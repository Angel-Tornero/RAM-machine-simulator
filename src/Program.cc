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

Program::Program(std::string fileName) {
  load(fileName);
}

std::string fileToString(std::string fileName) {
  std::ifstream inFile;
  std::string aux;
  std::string strFile = "";
  inFile.open(fileName);

  if (inFile.fail()) {
    std::cerr << "File does not exist (inFile).\n";
    exit(0);
  }
  while(!inFile.eof()) {
    getline(inFile, aux);
    if (aux[0] == ';') {
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
  readInstructions(strFile);
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

void Program::readInstructions(std::string strFile) {
  std::transform(strFile.begin(), strFile.end(), strFile.begin(), ::toupper);
  std::vector<std::string> normalOperations = {"LOAD", "STORE", "ADD", "SUB", "MULT", "DIV", "READ", "WRITE"};
  std::vector<std::string> jumpOperations = {"JUMP", "JGTZ", "JZERO"};
  bool error = false;
  bool validInstruction;
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

  while (token != NULL && !error) {
    validInstruction = false;
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
        if (std::regex_match(operand, std::regex("[0-9]"))) {
          validInstruction = true;
          newInstruction = createNormalInstruction(opCode, line, currentTag, operandType, operand);
        } else {
          std::cerr << "Invalid operand.\n";
          exit(-1);
        }
      } else if (std::regex_match(operand, std::regex("[0-9]"))) {
        operandType = 'd';
        validInstruction = true;
        newInstruction = createNormalInstruction(opCode, line, currentTag, operandType, operand);
      }
    } else if (find(jumpOperations.begin(), jumpOperations.end(), opWord) != jumpOperations.end()) {
        opCode = std::distance(jumpOperations.begin(), std::find(jumpOperations.begin(), jumpOperations.end(), opWord));
        iss >> operand;
        validInstruction = true;
        newInstruction = createJumpInstruction(opCode, line, currentTag, operand);
    } else if (opWord.find("HALT") != std::string::npos) {
        validInstruction = true;
        newInstruction = new InstructionHALT(line, currentTag, "HALT");
    }

    if (validInstruction) {
      line++;
      instructions_.push_back(newInstruction);
    }
    token = std::strtok(NULL, "\n");
  }
}

void Program::showInstructions() {
  for (int i = 0; i < instructions_.size(); i++) {
    instructions_[i]->show();
  }
}

Instruction* Program::createNormalInstruction(int opCode, int line, std::string tag, char opType, std::string operand) {
  switch(opCode) {
    case 0:
      return new InstructionLOAD(line, tag, "LOAD", opType, operand);
    case 1:
      return new InstructionSTORE(line, tag, "STORE", opType, operand);
    case 2:
      return new InstructionADD(line, tag, "ADD", opType, operand);
    case 3:
      return new InstructionSUB(line, tag, "SUB", opType, operand);
    case 4:
      return new InstructionMULT(line, tag, "MULT", opType, operand);
    case 5:
      return new InstructionDIV(line, tag, "DIV", opType, operand);
    case 6:
      return new InstructionREAD(line, tag, "READ", opType, operand);
    case 7:
      return new InstructionWRITE(line, tag, "WRITE", opType, operand);
  }
}

Instruction* Program::createJumpInstruction(int opCode, int line, std::string tag, std::string operand) {
  switch(opCode) {
    case 0:
      return new InstructionJUMP(line, tag, "JUMP", operand);
    case 1:
      return new InstructionJGTZ(line, tag, "JGTZ", operand);
    case 2:
      return new InstructionJZERO(line, tag, "JZERO", operand);
  }
}