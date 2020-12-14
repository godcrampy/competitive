#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, count = 0;
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    for (ll j = 1; j <= n; ++j) {
      ll num = i * (j + 1);
      ll den = (i + 1) * j;
      ll gc = __gcd(num, den);
      num /= gc;
      den /= gc;
      if (num + 1 == den) {
        count++;
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
