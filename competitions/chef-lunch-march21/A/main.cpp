#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, x;
  cin >> n >> x;
  ll maxRating = -1;
  ll s, r;
  for (ll i = 0; i < n; ++i) {
    cin >> s >> r;
    if (s <= x) {
      maxRating = max(maxRating, r);
    }
  }

  cout << maxRating << "\n";
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
