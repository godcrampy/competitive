#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> grid(n, vector<ll>(m, 0));
  vector<ll> xorVals(m + n, 0);
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j < m; ++j) {
      cin >> grid[i][j];
      xorVals[i + j] ^= grid[i][j];
    }
  }

  bool zero = true;

  for (ll i : xorVals) {
    if (i != 0) {
      zero = false;
      break;
    }
  }

  if (zero) {
    cout << "Jeel\n";
  } else {
    cout << "Ashish\n";
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
