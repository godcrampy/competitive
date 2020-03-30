#include <string>

using namespace std;

bool backspaceCompare(string S, string T) {
  return processString(S) == processString(T);
}

string processString(string S) {
  int count = 0;
  string res = "";

  for (int i = S.length() - 1; i >= 0; --i) {
    char c = S[i];
    if (c == '#') {
      ++count;
    } else {
      if (count > 0) {
        --count;
      } else {
        res += c;
      }
    }
  }
  return res;
}