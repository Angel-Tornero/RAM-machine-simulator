#include <map>
#include <string>
#include <iostream>
#include <regex>

int main() {
  std::string hola = "11";

  if (std::regex_match(hola, std::regex("([0-9])+"))) {
    std::cout << "faletin";
  }

}