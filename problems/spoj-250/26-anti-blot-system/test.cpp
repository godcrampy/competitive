#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "util.hpp"

std::string fix_stream(std::vector<std::string> vector) {
  if (vector.at(0).find("machula") != std::string::npos)
    vector.at(0) =
        std::to_string(std::stoi(vector.at(4)) - std::stoi(vector.at(2)));
  else if (vector.at(2).find("machula") != std::string::npos)
    vector.at(2) =
        std::to_string(std::stoi(vector.at(4)) - std::stoi(vector.at(0)));
  else
    vector.at(4) =
        std::to_string(std::stoi(vector.at(0)) + std::stoi(vector.at(2)));
  std::string final;
  for (auto word : vector) final += word + " ";
  return final;
}

int main(int argc, char const *argv[]) {
  std::string line, word;
  std::getline(std::cin, line);
  std::vector<std::string> split;
  std::stringstream stream(line);
  while (stream >> word) split.push_back(word);
  std::cout << fix_stream(split) << std::endl;
  return 0;
}
