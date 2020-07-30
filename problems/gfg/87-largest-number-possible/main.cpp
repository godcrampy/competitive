#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n, s;
  cin >> n >> s;

  string res;

  if (s == 0) {
    cout << -1 << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (s >= 9) {
      s -= 9;
      res += '9';
    } else {
      res += '0' + s;
      s = 0;
    }
  }

  if (s == 0) {
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }
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
