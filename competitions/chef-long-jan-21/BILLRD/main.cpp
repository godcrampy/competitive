#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, k, x, y;
  cin >> n >> k >> x >> y;

  ll diff = abs(x - y);

  k %= 4;
  if (x < y) {
    switch (k) {
      case 1:
        // up
        cout << n - diff << " " << n << "\n";
        break;
      case 2:
        // right
        cout << n << " " << n - diff << "\n";
        break;
      case 3:
        // down
        cout << diff << " " << 0 << "\n";
        break;
      default:
        // left
        cout << 0 << " " << diff << "\n";
        break;
    }
  } else if (x > y) {
    switch (k) {
      case 1:
        // right
        cout << n << " " << n - diff << "\n";
        break;
      case 2:
        // up
        cout << n - diff << " " << n << "\n";
        break;
      case 3:
        // left
        cout << 0 << " " << diff << "\n";
        break;
      default:
        // down
        cout << diff << " " << 0 << "\n";
        break;
    }
  } else {
    cout << n << " " << n << "\n";
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
