#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2) {
    ll x = x1 + abs(y2 - y1);
    cout << x << " " << y1 << " " << x << " " << y2 << "\n";
  } else if (y1 == y2) {
    ll y = y1 + abs(x2 - x1);
    cout << x1 << " " << y << " " << x2 << " " << y << "\n";
  } else {
    if (abs(x2 - x1) == abs(y2 - y1))
      cout << x1 << " " << y2 << " " << x2 << " " << y1 << "\n";
    else
      cout << "-1\n";
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
