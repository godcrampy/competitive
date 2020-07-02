#include <string>
#include <vector>

using namespace std;

pair<int, string> max_val(int num) {
  vector<pair<int, string>> m = {
      {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
      {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
      {500, "D"}, {900, "CM"}, {1000, "M"}};
  for (auto r = m.rbegin(); r != m.rend(); ++r) {
    if ((*r).first <= num) {
      return *r;
    }
  }
  return {1, "I"};
}

string intToRoman(int num) {
  string r;

  while (num > 0) {
    // get max val smaller than num
    auto p = max_val(num);
    int val = p.first;
    string c = p.second;
    int times = num / val;
    num %= val;

    for (int i = 0; i < times; ++i) {
      r += c;
    }
  }

  return r;
}