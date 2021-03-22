#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll w1, w2, x1, x2, m;
  cin >> w1 >> w2 >> x1 >> x2 >> m;
  ll change = w2 - w1;
  ll minChange = m * x1;
  ll maxChange = m * x2;
  if (minChange <= change && change <= maxChange) {
    cout << "1\n";
  } else {
    cout << "0\n";
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
