#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  long long z, l1, r1, l2, r2, count;
  char c;
  int q, n, m;
  cin >> n >> m >> q;
  vector<long long> x(n), y(m);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> y[i];
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  for (int k = 0; k < q; ++k) {
    cin >> z;
    cin >> c;
    count = 0;

    auto xStart = x.begin();
    auto yStart = y.begin();
    auto xEnd = x.end();      // * First guy greater than r1
    auto yEnd = y.end() - 1;  // * Last guy less than or equal to r2
    if (c == 'A') {
      cin >> l1 >> r1;
      xStart = lower_bound(x.begin(), x.end(), l1);
      xEnd = upper_bound(x.begin(), x.end(), r1);
    } else if (c == 'B') {
      cin >> l2 >> r2;
      yStart = lower_bound(y.begin(), y.end(), l2);
      while (*yEnd > r2) {
        --yEnd;
      }
    } else {
      cin >> l1 >> r1 >> l2 >> r2;
      xStart = lower_bound(x.begin(), x.end(), l1);
      yStart = lower_bound(y.begin(), y.end(), l2);
      xEnd = upper_bound(x.begin(), x.end(), r1);
      while (*yEnd > r2) {
        --yEnd;
      }
    }

    while (xStart != xEnd && yEnd >= yStart) {
      if (*xStart + *yEnd <= z) {
        count += yEnd - yStart + 1;
        ++xStart;
      } else {
        --yEnd;
      }
    }
    cout << count << endl;
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}