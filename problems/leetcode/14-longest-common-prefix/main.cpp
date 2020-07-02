#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  if (strs.size() == 0) return "";
  auto min_str = min_element(strs.begin(), strs.end(), [](auto a, auto b) {
    return a.length() < b.length();
  });
  int min_length = (*min_str).length();

  for (int i = 0; i < min_length; ++i) {
    char check = strs[0][i];
    for (const string& str : strs) {
      if (str[i] != check) return str.substr(0, i);
    }
  }

  return strs[0].substr(0, min_length);
}