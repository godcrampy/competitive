#include <algorithm>
#include <climits>
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

  int removedSoFar = 0, temp = 0, count = INT_MAX;
  sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i) {
    temp = removedSoFar;
    removedSoFar += v[i];
    for (int j = n - 1; j > i; --j) {
      temp += max(v[j] - v[i] - k, 0);
    }

    count = min(count, temp);
  }

  cout << count << endl;
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