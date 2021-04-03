#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  ll smallestFactor = n;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      smallestFactor = i;
      break;
    }
  }

  ll largestFactor = n / smallestFactor;

  printf("%lld %lld\n", largestFactor, n - largestFactor);
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
