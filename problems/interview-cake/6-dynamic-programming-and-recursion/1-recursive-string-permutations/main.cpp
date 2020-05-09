#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> getPermutations(const string& inputString) {
  // generate all permutations of the input string
  if (inputString.length() == 0) {
    return {""};
  }

  string exceptOne = inputString.substr(1);
  auto strings = getPermutations(exceptOne);
  auto first = inputString.substr(0, 1);

  unordered_set<string> res;

  for (auto str : strings) {
    for (int i = 0; i <= str.length(); ++i) {
      string start = str.substr(0, i);
      string end = str.substr(i);
      res.insert(start + first + end);
    }
  }

  return res;
}
