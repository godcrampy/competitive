#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(string s) {
  if (s.length() > 10) {
    cout << s[0] << s.length() - 2 << s[s.length() - 1] << '\n';
  } else {
    cout << s << '\n';
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  string s;
  for (int i = 0; i < t; ++i) {
    cin >> s;
    solve(s);
  }
  return 0;
}
