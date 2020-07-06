#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  long n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  for (int c = n - 1; c >= 0; --c) {
    int a = 0, b = c - 1;
    while (a < b) {
      int rhs = v[c] * v[c];
      int lhs = v[a] * v[a] + v[b] * v[b];
      if (lhs > rhs) {
        --b;
      } else if (lhs < rhs) {
        ++a;
      } else {
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";
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
