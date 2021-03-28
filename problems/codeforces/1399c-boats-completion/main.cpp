#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll countOfTarget(const vector<ll>& v, ll target) {
  ll count = 0;
  ll l = 0, r = v.size() - 1;

  while (l < r) {
    ll sum = v[l] + v[r];
    if (sum < target) {
      ++l;
    } else if (sum > target) {
      --r;
    } else {
      ++l;
      --r;
      ++count;
    }
  }

  return count;
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  ll count = -1;
  for (ll i = 2; i <= 2 * n; ++i) {
    count = max(count, countOfTarget(v, i));
  }

  cout << count << "\n";
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
