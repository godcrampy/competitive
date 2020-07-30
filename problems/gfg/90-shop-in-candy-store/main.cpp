#include <algorithm>
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

  sort(v.begin(), v.end());

  int minVal = 0, maxVal = 0;
  int j = n, i = 0;

  while (j > i) {
    minVal += v[i++];
    j -= k;
  }

  j = -1, i = n - 1;
  while (j < i) {
    maxVal += v[i--];
    j += k;
  }
  cout << minVal << " " << maxVal << endl;
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
