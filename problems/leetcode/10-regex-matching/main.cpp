#include <string>
#include <vector>
using namespace std;
// DP Problem
// https://www.youtube.com/watch?v=l3hda49XcDE
char char_at(const string &str, int i) {
  // 1 based indexing
  return str[i - 1];
}

bool is_equal_to_zero(const string &p, int i) {
  // even indices *
  // end with *
  if (i % 2 == 1) {
    return false;
  }

  for (int j = 2; j <= i; j += 2) {
    if (char_at(p, j) != '*') return false;
  }
  return true;
}

bool isMatch(string s, string p) {
  int p_len = p.length();
  int s_len = s.length();

  vector<vector<bool>> table(p_len + 1, vector<bool>(s_len + 1));

  table[0][0] = true;

  for (int i = 1; i <= s_len; ++i) {
    table[0][i] = false;
  }

  for (int j = 1; j <= p_len; ++j) {
    table[j][0] = is_equal_to_zero(p, j);
  }

  for (int i = 1; i <= p_len; ++i) {
    for (int j = 1; j <= s_len; ++j) {
      bool val = false;

      if (char_at(p, i) == char_at(s, j) || char_at(p, i) == '.') {
        val = table[i - 1][j - 1];
      } else if (char_at(p, i) == '*') {
        val =
            table[i - 2][j] ||  // zero occurrences
            ((char_at(s, j) == char_at(p, i - 1) || char_at(p, i - 1) == '.') &&
             table[i][j - 1]);
      } else {
        val = false;
      }

      table[i][j] = val;
    }
  }

  return table[p_len][s_len];
}