#include <map>
#include <string>
#include <iostream>

int main() {
  std::map<int, std::string> map;

  map.insert(std::make_pair(1, "hola"));
  map.insert(std::make_pair(2, "buenas"));
  map.insert(std::make_pair(3, "bolas XD"));

  std::cout << map[3];

}