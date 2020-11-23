#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (ll i = 0; i < q; ++i) {
    ll x, y;
    cin >> x >> y;
    --x;
    --y;
    char target = s[x];
    bool solved = false;
    for (ll j = 0; j < x; ++j) {
      if (target == s[j]) {
        solved = true;
        break;
      }
    }
    target = s[y];
    for (ll j = y + 1; j < n && !solved; ++j) {
      if (target == s[j]) {
        solved = true;
        break;
      }
    }
    if (!solved) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
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
