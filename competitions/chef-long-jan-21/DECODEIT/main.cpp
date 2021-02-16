#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;

  for (ll i = 0; i < n; i += 4) {
    ll count = 0;
    for (ll j = 0; j < 4; ++j) {
      if (s[i + j] == '1') {
        count += 1 << (3 - j);
      }
    }

    cout << (char)(count + 'a');
  }
  cout << "\n";
}

int main(int argc, char const *argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
