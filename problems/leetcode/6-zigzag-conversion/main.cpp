#include <string>
#include <vector>

using namespace std;

int row_number(int numRows, int t) {
  int x = (numRows - 1) * 2;
  return min(t % x, x - (t % x));
}

string convert(string s, int numRows) {
  if (numRows <= 1) return s;
  vector<string> table(numRows);

  for (int i = 0; i < s.length(); ++i) {
    int r = row_number(numRows, i);
    table[r] += s.substr(i, 1);
  }

  string ret;
  for (auto str : table) {
    ret += str;
  }
  return ret;
}