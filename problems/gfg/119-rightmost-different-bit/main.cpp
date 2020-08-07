#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int m, n;
  cin >> m >> n;

  for (int i = 0; i < 32; ++i) {
    int a = 1, b = 1;
    a = a & (m >> i);
    b = b & (n >> i);
    if (a ^ b) {
      cout << i + 1 << endl;
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
