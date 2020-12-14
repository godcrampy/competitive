#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, sum = 0, maxVal = LONG_LONG_MIN;
  cin >> n;
  vector<ll> v(n, 0);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
    maxVal = max(maxVal, v[i]);
  }

  ll k = max(maxVal, (ll)ceil((double)sum / (n - 1)));

  cout << k * (n - 1) - sum << "\n";
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
