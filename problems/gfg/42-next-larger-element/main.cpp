#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  stack<int> s;
  vector<long> res(n, -1);

  for (int i = 0; i < n; ++i) {
    if (s.empty()) {
      s.push(i);
      continue;
    }

    while (!s.empty() && v[s.top()] < v[i]) {
      res[s.top()] = v[i];
      s.pop();
    }

    s.push(i);
  }

  for (long i : res) {
    cout << i << " ";
  }
  cout << endl;
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