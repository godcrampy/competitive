#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, sum = 0;
  cin >> n;

  vector<ll> v(n, 0);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
  }

  for (ll i = n; i >= 1; --i) {
    // i is possible size of final array
    if (sum % i == 0) {
      ll reqSum = sum / i;
      ll currSum = 0;
      bool found = true;

      for (ll j = 0; j < n; ++j) {
        currSum += v[j];
        if (currSum > reqSum) {
          found = false;
          break;
        } else if (currSum == reqSum) {
          currSum = 0;
        }
      }

      if (found) {
        cout << n - i << "\n";
        return;
      }
    }
  }
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
