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
  int f;
  cin >> f;

  // find rotation point
  int l = 0;
  int r = n - 1;

  while (l < r) {
    int m = l + (r - l) / 2;
    int next = (m + 1) % n;

    if (a[m] > a[next]) {
      r = next;
      break;
    } else {
      if (a[0] > a[m]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
  }

  // r has the rotation point
  int rot = r;
  if (a[rot] <= f && f <= a[n - 1]) {
    l = rot;
    r = n - 1;
  } else {
    l = 0;
    r = rot - 1;
  }

  while (l <= r) {
    int m = l + (r - l) / 2;
    if (a[m] > f) {
      r = m - 1;
    } else if (a[m] < f) {
      l = m + 1;
    } else {
      cout << m << endl;
      return;
    }
  }
  cout << -1 << endl;
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
