#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string cover(k, '0');
  s = cover + s + cover;
  ll count = 0;
  ll oneCount = 0;
  ll l = 0;
  ll r = 0;

  for (ll i = 0; i < 2 * k + 1 && r < n; ++i) {
    if (s[r] == '1') ++oneCount;
    ++r;
  }

  n = s.size();

  // First block special
  if (oneCount == 0) {
    ++count;
    ++oneCount;
    s[0] = '1';
  }
  ++l;
  ++r;

  while (r < n) {
    if (s[r] == '1') ++oneCount;
    if (s[l - 1] == '1') --oneCount;

    if (oneCount == 0) {
      ++count;
      ++oneCount;
      s[(l + k)] = '1';
    }
    // if (s[l] == '1') --oneCount;
    // if (s[r] == '1') ++oneCount;
    ++l;
    ++r;
  }

  cout << count << "\n";
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
