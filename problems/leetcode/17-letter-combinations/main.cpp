#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits) {
  if (digits.length() == 0) {
    return {};
  }
  map<char, set<string>> m = {
      {'2', {"a", "b", "c"}}, {'3', {"d", "e", "f"}},
      {'4', {"g", "h", "i"}}, {'5', {"j", "k", "l"}},
      {'6', {"m", "n", "o"}}, {'7', {"p", "q", "r", "s"}},
      {'8', {"t", "u", "v"}}, {'9', {"w", "x", "y", "z"}}};

  set<string> res = {""};
  for (int i = 0; i < digits.length(); ++i) {
    set<string> adder = m[digits[i]];
    set<string> temp;

    for (string s : res) {
      for (string a : adder) {
        temp.insert(s + a);
      }
    }
    res = temp;
  }
  vector<string> v(res.begin(), res.end());
  return v;
}