#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<int> v(n);
  ll totalOnes = 0;
  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
    totalOnes += v[i];
  }

  // find the substring with least 1s
  ll leastOnes = n;
  ll currentCount = 0;
  for (ll i = 0; i < k; ++i) {
    if (v[i] == 1) ++currentCount;
  }
  leastOnes = currentCount;
  for (ll i = k; i < n; ++i) {
    ll l = i - k;
    currentCount += v[i] - v[l];
    leastOnes = min(leastOnes, currentCount);
  }
  // reduce it
  ll cost = ((leastOnes) * (leastOnes + 1)) / 2;
  // add unit cost for the rest of the 1s
  cost += totalOnes - leastOnes;
  cout << cost << "\n";
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
