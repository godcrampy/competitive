#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  priority_queue<int> s;
  priority_queue<int, vector<int>, greater<int>> g;
  int median;
  int i;
  cin >> i;

  s.push(i);
  median = i;
  cout << median << endl;

  for (int j = 1; j < n; ++j) {
    cin >> i;

    if (s.size() > g.size()) {
      if (i < median) {
        g.push(s.top());
        s.pop();
        s.push(i);
      } else {
        g.push(i);
      }

      median = (s.top() + g.top()) / 2;
      cout << median << endl;
    } else if (g.size() > s.size()) {
      if (i > median) {
        s.push(g.top());
        g.pop();
        g.push(i);
      } else {
        s.push(i);
      }

      median = (s.top() + g.top()) / 2;
      cout << median << endl;
    } else {
      if (i < median) {
        s.push(i);
        median = s.top();
      } else {
        g.push(i);
        median = g.top();
      }

      cout << median << endl;
    }
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
