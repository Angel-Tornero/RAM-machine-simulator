#include "../include/program_t.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>

program_t::program_t(std::string fileName) {
  
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
    if (aux[0] == ';')
      continue;

    strFile += aux + "\n";
  }
  inFile.close();

  return strFile;
}

void program_t::load(std::string fileName) {
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

void program_t::readInstructions(std::string strFile) {
  std::transform(strFile.begin(), strFile.end(), strFile.begin(), ::toupper);
  std::vector<std::string> operations = {"LOAD", "STORE", "ADD", "SUB", "MULT", "DIV", "READ", "WRITE"};
  std::vector<std::string> jumpOperations = {"JUMP", "JGTZ", "JZERO"};

  bool error = false;
  bool validInstruction;
  bool newTag;
  int line = 0;

  instruction_t* newInstruction;

  char* input = (char*) strFile.c_str();
  char* token = std::strtok(input, "\n");
  std::string strLine;

  std::string currentTag = "MAIN";
  std::string tag;
  std::string opWord;
  std::string operand;
  std::string operandType;

  while (token != NULL && !error) {
    validInstruction = false;
    newTag = false;
    opWord = "";
    operand = "";
    operandType = "";

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

    if (find(operations.begin(), operations.end(), opWord) != operations.end()) {
      iss >> operand;
      if (operand[0] == '*' || operand[0] == '=') {
        operandType = operand[0];
        operand.erase(operand.begin());
        if (std::regex_match(operand, std::regex("[0-9]"))) {
          validInstruction = true;
        } else {
          std::cerr << "Invalid operand.\n";
          exit(-1);
        }
      } else if (std::regex_match(operand, std::regex("[0-9]"))) {
        operandType = 'd';
        validInstruction = true;
      }
    } else if (find(jumpOperations.begin(), jumpOperations.end(), opWord) != jumpOperations.end()) {
        iss >> operand;
        validInstruction = true;
    } else if (opWord.find("HALT") != std::string::npos) {
        validInstruction = true;
    }

    if (validInstruction) {
      line++;
      instructions_.push_back(new instruction_t(line, currentTag, opWord, operandType, operand));
    }
    token = std::strtok(NULL, "\n");
  }
}

void program_t::showInstructions() {
  for (int i = 0; i < instructions_.size(); i++) {
    instructions_[i]->show();
  }
}