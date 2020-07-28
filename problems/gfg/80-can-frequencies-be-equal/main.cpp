#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  string s;
  cin >> s;

  unordered_map<char, int> m;
  unordered_map<int, int> ff;
  int maxFreq = -1;
  for (char c : s) {
    m[c]++;
    maxFreq = max(maxFreq, m[c]);
  }

  for (auto p : m) {
    ff[p.second]++;
  }

  if (ff.size() == 1) {
    cout << 1 << endl;
  } else if (ff.size() == 2) {
    auto it = ff.begin();
    int fv = it->first;
    int fc = it->second;
    ++it;
    int sv = it->first;
    int sc = it->second;

    if (abs(fv - sv) == 1 && (fc == 1 || sc == 1)) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  } else {
    cout << 0 << endl;
  }
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
