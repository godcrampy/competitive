#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;
ll dp[1001][1001][2];

ll solveMem(ll n, ll k, ll d, ll N) {
  if (k == 1) {
    return 1;
  }

  if (dp[n][k][d] != -1) return dp[n][k][d];

  ll ans = 2;

  if (d == 1) {
    // right
    if (n < N) {
      ans += solveMem(n + 1, k, d, N) - 1;
    }

    ans %= mod;

    if (n > 1) {
      ans += solveMem(n - 1, k - 1, 1 - d, N) - 1;
    }
    ans %= mod;

    dp[n][k][d] = ans;
  } else {
    // left
    if (n > 1) {
      ans += solveMem(n - 1, k, d, N) - 1;
    }

    ans %= mod;

    if (n < N) {
      ans += solveMem(n + 1, k - 1, 1 - d, N) - 1;
    }
    ans %= mod;

    dp[n][k][d] = ans;
  }

  return ans;
}

void solve() {
  ll n, k;
  cin >> n >> k;

  memset(dp, -1, sizeof(dp));
  cout << solveMem(1, k, 1, n) << "\n";
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
