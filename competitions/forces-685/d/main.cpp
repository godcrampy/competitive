#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll d, k;
  cin >> d >> k;
  ll x = 0, y = 0;

  while (true) {
    if (x < y && (x + k) * (x + k) + y * y <= d * d) {
      x += k;
    } else if (x >= y && (y + k) * (y + k) + x * x <= d * d) {
      y += k;
    } else
      break;
  }

  if (x == y)
    cout << "Utkarsh\n";
  else
    cout << "Ashish\n";
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
