#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;
  unordered_set<char> s;

  for (char c : b) {
    s.insert(c);
  }

  for (char c : a) {
    if (s.find(c) != s.end()) {
      cout << c << endl;
      return;
    }
  }

  cout << "$\n";
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
