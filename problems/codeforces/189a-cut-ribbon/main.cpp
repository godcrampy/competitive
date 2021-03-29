#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, a, b, c;
  cin >> n >> a >> b >> c;

  vector<ll> dp(max(a, max(b, max(n, c))) + 1, -1);
  dp[0] = 0;
  dp[a] = 1;
  dp[b] = 1;
  dp[c] = 1;
  for (ll i = 1; i <= n; ++i) {
    if (i - a >= 0 && dp[i - a] != -1) dp[i] = max(dp[i], 1 + dp[i - a]);
    if (i - b >= 0 && dp[i - b] != -1) dp[i] = max(dp[i], 1 + dp[i - b]);
    if (i - c >= 0 && dp[i - c] != -1) dp[i] = max(dp[i], 1 + dp[i - c]);
  }

  cout << dp[n] << "\n";
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
