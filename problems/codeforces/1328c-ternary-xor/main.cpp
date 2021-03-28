#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  string x;
  cin >> x;
  string a(n, '0'), b(n, '0');

  bool areCompeting = true;  // if required, a gets the higher number

  for (ll i = 0; i < n; ++i) {
    char c = x[i];
    if (areCompeting) {
      // split equally
      if (c == '1') {
        a[i] = c;
        areCompeting = false;
        b[i] = '0';
      } else if (c == '2') {
        a[i] = '1';
        b[i] = '1';
      }
    } else {
      // keep a lower
      b[i] = c;
    }
  }

  cout << a << "\n" << b << "\n";
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
