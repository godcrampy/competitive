#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  bool lessThan = true;

  for (int i = 0; i < n - 1; ++i) {
    if (lessThan && v[i] > v[i + 1]) {
      swap(v[i], v[i + 1]);
    }
    if (!lessThan && v[i] < v[i + 1]) {
      swap(v[i], v[i + 1]);
    }
    lessThan = !lessThan;
  }

  for (auto n : v) {
    cout << n << " ";
  }
  cout << endl;
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
