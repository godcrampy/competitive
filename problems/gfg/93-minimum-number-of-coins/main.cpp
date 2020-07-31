#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> den = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  int count = 0;
  vector<int> res;

  for (int c : den) {
    if (n >= c) {
      for (int i = 0; i < n / c; ++i) {
        res.push_back(c);
      }
      n = n % c;
    }
  }

  for (auto i : res) {
    cout << i << " ";
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
