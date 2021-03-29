#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n), b(n);

  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(a.begin(), a.end());

  ll l = -1, r = -1;

  for (ll i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      l = i;
      break;
    }
  }

  for (ll i = n - 1; i >= 0; --i) {
    if (a[i] != b[i]) {
      r = i;
      break;
    }
  }

  if (l == -1 || r == -1) {
    cout << "yes\n";
    cout << "1 1\n";
  } else {
    reverse(b.begin() + l, b.begin() + r + 1);
    if (equal(a.begin(), a.end(), b.begin(), b.end())) {
      cout << "yes\n";
      cout << l + 1 << " " << r + 1 << "\n";
    } else {
      cout << "no\n";
    }
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
