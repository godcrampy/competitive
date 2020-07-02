// Knuth Morris Pratt Algorithm

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void lps(string pattern, vector<int>& vec) {
  int j = 0;
  int i = 1;

  while (i != pattern.length()) {
    // if equal
    if (pattern[j] == pattern[i]) {
      vec[i] = j + 1;
      ++i;
      ++j;
    } else {
      // not equal
      if (j == 0) {
        vec[i] == 0;
        ++i;
      } else {
        j = vec[j - 1];  // * Fallback
      }
    }
  }
}

int search(string& text, string& pattern, const vector<int>& vec) {
  int i = 0;  // itr for pattern
  int j = 0;  // itr for text

  while (i != pattern.length() && j != text.length()) {
    if (pattern[i] == text[j]) {
      ++i;
      ++j;
    } else {
      if (i == 0) {
        ++j;
      } else {
        i = vec[i - 1];  // * Fallback
      }
    }
  }

  return i == pattern.length() ? j - i : -1;
}

int main(int argc, char const* argv[]) {
  string text = "AABAACAADAABAABA";
  string pattern = "AABA";

  vector<int> vec(pattern.length(), 0);
  lps(pattern, vec);  // longest prefix suffix

  cout << search(text, pattern, vec) << endl;

  return 0;
}
