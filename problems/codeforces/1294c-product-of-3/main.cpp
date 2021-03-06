#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  set<ll> used;

  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      used.insert(i);
      n /= i;
      break;
    }
  }

  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0 && (used.count(i) == 0)) {
      used.insert(i);
      n /= i;
      break;
    }
  }

  if (used.size() != 2 || used.count(n) || n == 1)
    cout << "NO\n";
  else {
    used.insert(n);
    cout << "YES\n";
    for (auto i : used) cout << i << " ";
    cout << "\n";
  }
}

int main(int argc, char const* argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
