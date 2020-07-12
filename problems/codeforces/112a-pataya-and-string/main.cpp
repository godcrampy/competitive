#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

char toLowerCase(char a) {
  if (a >= 'A' && a <= 'Z') {
    return a - 'A' + 'a';
  }
  return a;
}

int solve(const string& a, const string& b) {
  int i = 0, j = 0;
  while (i < a.length() || j < b.length()) {
    if (i == a.length()) {
      return -1;
    }
    if (j == b.length()) {
      return 1;
    }

    char c1 = toLowerCase(a[i]), c2 = toLowerCase(b[j]);
    if (c1 < c2) {
      return -1;
    }
    if (c1 > c2) {
      return 1;
    }
    ++i;
    ++j;
  }

  return 0;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  cout << solve(a, b) << '\n';
  return 0;
}
