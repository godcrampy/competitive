#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  ll distance = 0, fuelLeft = v[0];

  for (ll i = 1; i < n; ++i) {
    if (fuelLeft >= 1) {
      ++distance;
      --fuelLeft;
      fuelLeft += v[i];
    } else {
      break;
    }
  }

  distance += fuelLeft;
  cout << distance << "\n";
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
