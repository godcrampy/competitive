#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int m, n;
  cin >> m >> n;

  vector<long> a(m), b(n);

  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  long ans = 0;
  long sum1 = 0, sum2 = 0;
  int i = 0, j = 0;

  while (i < m && j < n) {
    if (a[i] < b[j]) {
      sum1 += a[i++];
    } else if (a[i] > b[j]) {
      sum2 += b[j++];
    } else {
      int temp = a[i];

      while (i < m && a[i] == temp) {
        sum1 += a[i++];
      }

      while (j < n && b[j] == temp) {
        sum2 += b[j++];
      }

      ans += max(sum1, sum2);
      sum1 = 0;
      sum2 = 0;
    }
  }

  while (i < m) {
    sum1 += a[i++];
  }

  while (j < n) {
    sum2 += b[j++];
  }

  ans += max(sum1, sum2);

  cout << ans << endl;
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
