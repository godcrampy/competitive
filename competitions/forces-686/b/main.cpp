#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  ll minSoFar = LONG_LONG_MAX, pos = -1;
  unordered_set<ll> s, duplicates;
  vector<ll> v(n, 0);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  for (ll i : v) {
    if (s.find(i) == s.end()) {
      // unique
      s.insert(i);
    } else {
      // no unique
      duplicates.insert(i);
    }
  }

  for (ll i = 0; i < n; ++i) {
    if (duplicates.find(v[i]) == duplicates.end() && v[i] < minSoFar) {
      minSoFar = v[i];
      pos = i + 1;
    }
  }

  cout << pos << "\n";
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
