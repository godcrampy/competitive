#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll pairUp(ll x) { return x * (x - 1) / 2; }

void solve() {
  ll n, m;
  cin >> n >> m;

  ll largestTeamSize = n - m + 1;
  ll maxPairs = pairUp(largestTeamSize);

  ll x = n / m;
  ll extra = n % m;  // distribute one each of these among teams
  ll minPairs = (m - extra) * pairUp(x) + extra * pairUp(x + 1);

  cout << minPairs << " " << maxPairs << "\n";
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
