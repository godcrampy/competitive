#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, m;
  cin >> n >> m;
  ll firstAvail = 1;
  vector<ll> k(n + 1), c(m + 1);
  for (ll i = 1; i <= n; ++i) {
    cin >> k[i];
  }

  for (ll i = 1; i <= m; ++i) {
    cin >> c[i];
  }

  sort(k.begin(), k.end(), greater<ll>());
  ll sum = 0;
  for (ll ki : k) {
    // deb2(ki, firstAvail);
    if (ki > firstAvail) {
      sum += c[firstAvail++];
    } else {
      sum += c[ki];
    }
    // deb(sum);
  }

  cout << sum << "\n";
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
