#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

int lcsubstr(string &a, string &b) {
  ll m = a.length(), n = b.length();
  int dp[m + 1][n + 1];
  int result = 0;

  for (ll i = 0; i <= m; i++) {
    for (ll j = 0; j <= n; j++) {
      // The first row and first column
      // entries have no logical meaning,
      // they are used only for simplicity
      // of program
      if (i == 0 || j == 0)
        dp[i][j] = 0;

      else if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        result = max(result, dp[i][j]);
      } else
        dp[i][j] = 0;
    }
  }
  return result;
}

void solve() {
  string a, b;
  cin >> a >> b;

  ll n = lcsubstr(a, b);

  cout << a.length() + b.length() - 2 * n << "\n";
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
