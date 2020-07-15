#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(int k, vector<int>& v) {
  int count =
      upper_bound(v.begin(), v.end(), max(v[k - 1], 1), greater<int>()) -
      v.begin();
  cout << count << '\n';
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  solve(k, v);
  return 0;
}
