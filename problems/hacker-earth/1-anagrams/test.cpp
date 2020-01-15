#include <iostream>
#include <map>
#include <string>
#include "util.hpp"

int number_of_deletions(std::map<char, int> &map1, std::map<char, int> &map2) {
  int deletions = 0;
  for (auto stuff : map1) {
    char c1 = stuff.first;
    int i1 = stuff.second;
    if (map2.count(c1))
      // map2 has this charecter as well
      deletions += std::max(0, i1 - map2[c1]);
    else
      // map2 doesn't have that charecter
      deletions += i1;
  }
  for (auto stuff : map2) {
    char c2 = stuff.first;
    int i2 = stuff.second;
    if (map1.count(c2))
      // map1 has this charecter as well
      deletions += std::max(0, i2 - map1[c2]);
    else
      // map2 doesn't have that charecter
      deletions += i2;
  }
  return deletions;
}

void string_to_map(const std::string &string, std::map<char, int> &map) {
  // works
  for (auto charecter : string)
    if (map.count(charecter))
      // charecter exists
      ++map[charecter];
    else
      map.insert({charecter, 1});
}

int main(int argc, char const *argv[]) {
  std::map<char, int> map1, map2;
  std::string string1, string2;
  std::getline(std::cin, string1);
  std::getline(std::cin, string2);
  string_to_map(string1, map1);
  string_to_map(string2, map2);

  std::cout << number_of_deletions(map1, map2) << std::endl;

  return 0;
}
