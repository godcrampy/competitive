#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int l = 0, r = n - 1;

  while (l < r) {
    int m = l + (r - l) / 2;
    int next = m + 1;

    if (m % 2 == 0) {
      if (a[m] == a[next]) {
        l = m + 2;
      } else {
        r = m;
      }
    } else {
      if (a[m] == a[next]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
  }

  if (l == r) {
    cout << a[l] << endl;
  } else {
    cout << -1 << endl;
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
