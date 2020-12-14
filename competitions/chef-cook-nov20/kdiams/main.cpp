#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, k;
  cin >> n >> k;

  if (k > (n - 1) * (n - 2) / 2 && k != n * (n - 1) / 2) {
    cout << "-1\n";
    return;
  }
  vector<pair<ll, ll>> v;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = i + 1; j <= n; ++j) {
      v.push_back({i, j});
    }
  }

  if (k != (n) * (n - 1) / 2) {
    while (k != 0) {
      v.pop_back();
      k--;
    }
  }

  cout << v.size() << "\n";
  for (auto p : v) {
    cout << p.first << " " << p.second << "\n";
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
