#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  vector<ll> q;
  ll x = n;
  for (ll i = 2; i <= n; ++i) {
    if (x % i == 0) {
      while (x % i == 0) {
        q.push_back(i);
        x /= i;
      }
    }
  }

  if (q.size() < 3) {
    cout << "NO\n";
    return;
  }

  ll a = q[0];
  ll b = q[1];
  if (a == b) {
    b *= q[2];
    ll c = 1;
    for (ll i = 3; i < q.size(); ++i) {
      c *= q[i];
    }
    if (c == 1 || b == c || c == a) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << a << " " << b << " " << c << "\n";
    }
  } else {
    ll c = 1;
    for (ll i = 2; i < q.size(); ++i) {
      c *= q[i];
    }
    if (c == 1 || b == c || c == a) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << a << " " << b << " " << c << "\n";
    }
  }
}

int main(int argc, char const* argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
