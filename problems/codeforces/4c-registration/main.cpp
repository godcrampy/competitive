#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;

  map<string, int> m;  // str => current max
  string s;

  for (ll i = 0; i < n; ++i) {
    cin >> s;
    if (m[s] == 0) {
      cout << "OK\n";
    } else {
      cout << s << m[s] << "\n";
    }
    ++m[s];
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
