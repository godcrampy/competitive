#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, k;
  cin >> k >> n;
  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int maxVal = *max_element(v.begin(), v.end());
  int minVal = *min_element(v.begin(), v.end());
  int mid = (minVal + maxVal) / 2;

  for (int& i : v) {
    if (i <= mid)
      i += k;
    else
      i -= k;
  }

  int maxVal2 = *max_element(v.begin(), v.end());
  int minVal2 = *min_element(v.begin(), v.end());

  cout << min(maxVal - minVal, maxVal2 - minVal2) << endl;
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
