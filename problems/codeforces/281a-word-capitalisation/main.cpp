#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

char toUpperCase(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a' + 'A';
  }
  return c;
}

void solve(string& s) {
  s[0] = toUpperCase(s[0]);
  cout << s << '\n';
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  solve(s);
  return 0;
}
