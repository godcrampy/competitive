#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  vector<ll> fuels(n), cost(n);
  vector<bool> reached(n, false);
  map<ll, set<ll>> priceToLocation;
  for (ll i = 0; i < n; ++i) {
    cin >> fuels[i];
  }

  for (ll i = 0; i < n; ++i) {
    cin >> cost[i];
    priceToLocation[cost[i]].insert(i);
  }

  ll visited = 0, costSoFar = 0;

  while (visited < n && priceToLocation.size() != 0) {
    ll nextCost = priceToLocation.begin()->first;
    ll nextPos = *priceToLocation.begin()->second.begin();
    priceToLocation.begin()->second.erase(nextPos);
    if (priceToLocation.begin()->second.empty()) {
      priceToLocation.erase(nextCost);
    }

    ll capacity = fuels[nextPos];
    ll fuelRequired = 0;
    ll pos = nextPos;
    while (visited < n && capacity) {
      if (!reached[pos]) {
        fuelRequired++;
        capacity--;
        reached[pos] = true;
        ++visited;
      }
      pos = (pos + 1) % n;
    }

    costSoFar += fuelRequired * nextCost;
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
