#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int capacity;
  cin >> capacity;

  deque<int> q;
  unordered_set<int> s;

  int count = 0;

  for (int i = 0; i < n; ++i) {
    if (s.find(v[i]) == s.end()) {
      // not found
      if (s.size() == capacity) {
        int top = q.front();
        q.pop_front();
        s.erase(top);
      }
      q.push_back(v[i]);
      s.insert(v[i]);
      ++count;
    } else {
      // found
      // move v[i] to top
      for (auto it = q.begin(); it != q.end(); it++) {
        if (*it == v[i]) {
          q.erase(it);
          q.push_back(v[i]);
          break;
        }
      }
    }
  }

  cout << count << endl;
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
