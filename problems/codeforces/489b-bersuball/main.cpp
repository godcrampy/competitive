#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  // store in map
  // first try to match with n - 1 => n => n + 1
  ll b, g;
  cin >> b;
  map<ll, ll> boys, girls;  // skills => count
  ll temp;
  for (ll i = 0; i < b; ++i) {
    cin >> temp;
    ++boys[temp];
  }

  cin >> g;
  for (ll i = 0; i < g; ++i) {
    cin >> temp;
    ++girls[temp];
  }

  ll count = 0;
  for (auto p : boys) {
    ll skill = p.first;
    ll numBoys = p.second;
    for (ll i = 0; i < numBoys; ++i) {
      // look for matching girls
      if (girls[skill - 1] > 0) {
        --girls[skill - 1];
        ++count;
      } else if (girls[skill] > 0) {
        --girls[skill];
        ++count;
      } else if (girls[skill + 1] > 0) {
        --girls[skill + 1];
        ++count;
      } else {
        // no matching girl
        break;
      }
    }
  }

  cout << count << "\n";
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
