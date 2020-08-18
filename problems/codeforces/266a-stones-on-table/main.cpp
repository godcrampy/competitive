#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(const string& s) {
  char last = s[0];
  int deletions = 0;
  for (int i = 1; i < s.length(); ++i) {
    if (s[i] == last) {
      ++deletions;
    } else {
      last = s[i];
    }
  }
  return deletions;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  string s;
  cin >> s;
  cout << solve(s) << '\n';
  return 0;
}
