#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Compare {
 public:
  bool operator()(pair<char, int> a, pair<char, int> b) {
    return a.second < b.second;
  }
};

void solve() {
  string s;
  cin >> s;

  priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> q;
  unordered_map<char, int> m;
  for (char c : s) {
    m[c]++;
  }

  for (auto p : m) {
    q.push(p);
  }

  string res;
  pair<char, int> prev = {0, 0};
  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    res += p.first;
    if (prev.second > 0) {
      q.push(prev);
    }
    p.second--;
    prev = p;
  }

  if (res.length() != s.length()) {
    cout << "NOT POSSIBLE" << endl;
  } else {
    cout << res << endl;
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
