#include <algorithm>
#include <iostream>
using namespace std;

set<string> getPermutations(string &s) {
  if (s.length() == 1) {
    return {s};
  }

  string f = s.substr(0, 1);
  string rest = s.substr(1);
  auto perms = getPermutations(rest);
  set<string> res;

  for (string str : perms) {
    for (int i = 0; i <= str.length(); ++i) {
      string start = str.substr(0, i);
      string end = str.substr(i);
      res.insert(start + f + end);
    }
  }
  return res;
}

void solve2() {
  string s;
  cin >> s;
  auto perms = getPermutations(s);
  for (string str : perms) {
    cout << str << " ";
  }
  cout << "\n";
}

void solve() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());

  do {
    cout << s << " ";
  } while (next_permutation(s.begin(), s.end()));
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
