#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> costAndCapacity(n);
  for (ll i = 0; i < n; ++i) {
    cin >> costAndCapacity[i].second;
  }

  for (ll i = 0; i < n; ++i) {
    cin >> costAndCapacity[i].first;
  }

  ll costSoFar = 0;
  ll travelled = 0;
  sort(costAndCapacity.begin(), costAndCapacity.end());

  for (ll i = 0; i < n; ++i) {
    ll travelLeft = n - travelled;
    ll fuelReq = min(travelLeft, costAndCapacity[i].second);
    travelled += fuelReq;
    costSoFar += fuelReq * costAndCapacity[i].first;
    if (travelled == n) break;
  }

  cout << costSoFar << "\n";
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
