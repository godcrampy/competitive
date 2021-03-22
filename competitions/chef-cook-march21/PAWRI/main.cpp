#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  string s;
  cin >> s;
  ll n = s.length();
  ll i = 0;
  while (i < n) {
    if (i <= n - 5 && s[i] == 'p' && s.substr(i, 5) == "party") {
      cout << "pawri";
      i += 5;
    } else {
      cout << s[i++];
    }
  }

  cout << "\n";
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
