#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll sumOfDigits(ll n) {
  ll sum = 0;

  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}

ll gcdSum(ll n) { return __gcd(n, sumOfDigits(n)); }

void solve() {
  ll n;
  cin >> n;

  while (true) {
    ll gcd = gcdSum(n);
    if (gcd > 1) {
      cout << n << "\n";
      return;
    }
    ++n;
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
