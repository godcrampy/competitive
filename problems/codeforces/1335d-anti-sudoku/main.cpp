#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  for (ll i = 0; i < 9; ++i) {
    string s;
    cin >> s;
    ll target = i / 3 + 3 * (i % 3);
    if (s[target] == '1')
      s[target] = '2';
    else
      s[target] = '1';
    cout << s << "\n";
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
