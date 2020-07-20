#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<string, char> removeRec(string s) {
  // returns reduced string and last removed char
  if (s.length() <= 1) {
    return {s, 0};
  }

  int j = 1;
  if (s[0] == s[1]) {
    while (j < s.length() && s[0] == s[j]) {
      ++j;
    }
    return removeRec(s.substr(j));
  }

  auto p = removeRec(s.substr(1));
  string prev(1, s[0]);
  string next = p.first;

  if (next.length() == 0) {
    if (p.second == s[0]) {
      return {"", s[0]};
    }
    return {prev, p.second};
  }

  if (next[0] == s[0]) {
    return {next.substr(1), s[0]};
  }

  return {prev + next, p.second};
}

void solve() {
  string s;
  cin >> s;
  auto p = removeRec(s);
  cout << p.first << endl;
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
