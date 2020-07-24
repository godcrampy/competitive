#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  deque<int> d;
  int i = 0;
  for (; i < k; ++i) {
    while (!d.empty() && v[d.back()] <= v[i]) {
      d.pop_back();
    }
    d.push_back(i);
  }

  for (; i < n; ++i) {
    cout << v[d.front()] << " ";
    while (!d.empty() && d.front() <= i - k) {
      d.pop_front();
    }

    while (!d.empty() && v[d.back()] <= v[i]) {
      d.pop_back();
    }

    d.push_back(i);
  }

  cout << v[d.front()] << endl;
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
