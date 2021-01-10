#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll divCeil(ll x, ll y) {
  if (x % y == 0) {
    return x / y;
  }

  return (x / y) + 1;
}

void solve() {
  ll n, x;
  cin >> n >> x;

  ll temp, maxSum = 0, sum = 0;

  for (ll i = 0; i < n; ++i) {
    cin >> temp;
    maxSum += divCeil(temp, x);
    sum += temp;
  }

  cout << divCeil(sum, x) << " " << maxSum << "\n";
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
