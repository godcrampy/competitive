#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, l;
  cin >> n >> l;

  vector<ll> v(n);
  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  // sort
  sort(v.begin(), v.end());
  // find max distance
  ll maxDistance = -1;

  for (ll i = 0; i < n - 1; ++i) {
    maxDistance = max(maxDistance, v[i + 1] - v[i]);
  }
  double d = (double)(maxDistance) / 2.0;
  // compare with endpoints
  d = max(d, (double)max(v[0], l - v.back()));
  printf("%.10f\n", d);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
