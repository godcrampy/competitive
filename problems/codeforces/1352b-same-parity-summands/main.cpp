#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, k;
  cin >> n >> k;

  if (n % 2 == 0) {
    // n is even
    if (k % 2 == 0) {
      // k is even
      if (n >= k) {
        ll sum = 0;
        cout << "YES\n";

        for (ll i = 1; i < k; ++i) {
          cout << "1 ";
          sum += 1;
        }
        cout << n - sum << "\n";
        return;
      } else {
        cout << "NO\n";
        return;
      }
    } else {
      // k is odd
      if (n >= k * 2) {
        ll sum = 0;
        cout << "YES\n";

        for (ll i = 1; i < k; ++i) {
          cout << "2 ";
          sum += 2;
        }
        cout << n - sum << "\n";
        return;

      } else {
        cout << "NO\n";
        return;
      }
    }
  } else {
    // n is odd
    if (k % 2 == 0) {
      // k is even
      cout << "NO\n";
    } else {
      // k is odd
      if (n >= k) {
        ll sum = 0;
        cout << "YES\n";
        for (ll i = 1; i < k; ++i) {
          cout << "1 ";
          sum += 1;
        }
        cout << n - sum << "\n";
        return;
      } else {
        cout << "NO\n";
        return;
      }
    }
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
