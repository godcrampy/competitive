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
  unordered_map<long long, int> store;
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
    auto xEnd = x.end();
    auto yEnd = y.end();
    if (c == 'A') {
      cin >> l1 >> r1;
      xStart = lower_bound(x.begin(), x.end(), l1);
      xEnd = upper_bound(x.begin(), x.end(), min(r1, z - 1));
    } else if (c == 'B') {
      cin >> l2 >> r2;
      yStart = lower_bound(y.begin(), y.end(), l2);
      yEnd = upper_bound(y.begin(), y.end(), min(r2, z - 1));
    } else {
      cin >> l1 >> r1 >> l2 >> r2;
      xStart = lower_bound(x.begin(), x.end(), l1);
      yStart = lower_bound(y.begin(), y.end(), l2);
      xEnd = upper_bound(x.begin(), x.end(), min(r1, z - 1));
      yEnd = upper_bound(y.begin(), y.end(), min(r2, z - 1));
    }

    for (auto i = xStart; i != xEnd && xStart <= xEnd; ++i) {
      // find index such that y[index] == *yStart
      int startIndex = yStart - y.begin();
      int endIndex1 = yEnd - y.begin();

      int endIndex2;
      // if (store.find(z - *i) == store.end()) {
      endIndex2 = upper_bound(y.begin(), y.end(), z - *i) - y.begin();
      // store[z - *i] = endIndex2;
      // } else {
      // endIndex2 = store[z - *i];
      // }

      int endIndex = min(endIndex1, endIndex2);
      count += max(endIndex - startIndex, 0);
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