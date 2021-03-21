#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  string s;
  cin >> s;
  bool isZeroRegion = true;
  bool canIRemove = true;

  for (ll i = 0; i < s.length(); ++i) {
    if (isZeroRegion) {
      if (s[i] == '0') {
        // no issues
        canIRemove = true;
      } else {
        if (canIRemove) {
          // remove
          canIRemove = false;
        } else {
          isZeroRegion = false;
          canIRemove = true;
        }
      }
    } else {
      // one region
      if (s[i] == '1') {
        // no issues
        canIRemove = true;
      } else {
        if (canIRemove) {
          // remove
          canIRemove = false;
        } else {
          // stuck
          cout << "NO\n";
          return;
        }
      }
    }
  }

  cout << "YES\n";
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
