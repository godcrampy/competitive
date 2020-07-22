#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int maxIndex = 0;
  while (true) {
    for (string s : v) {
      if (maxIndex >= s.length() || s[maxIndex] != v[0][maxIndex]) {
        if (maxIndex == 0) {
          cout << -1 << endl;
        } else {
          cout << v[0].substr(0, maxIndex) << endl;
        }
        return;
      }
    }
    ++maxIndex;
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
