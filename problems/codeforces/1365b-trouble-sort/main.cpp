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
  vector<int> parity(n);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  bool have0 = false, have1 = false;

  for (ll i = 0; i < n; ++i) {
    cin >> parity[i];
    if (parity[i] == 1) {
      have1 = true;
    }

    if (parity[i] == 0) {
      have0 = true;
    }
  }

  if (!have0 || !have1) {
    if (is_sorted(v.begin(), v.end())) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  } else {
    cout << "Yes\n";
  }
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
