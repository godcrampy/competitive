#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void yes() { cout << "YES\n"; }

void no() { cout << "NO\n"; }

void solve() {
  string s;
  cin >> s;

  if (s.length() % 2 == 0 && s[0] != ')' && s.back() != '(') {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main(int argc, char const *argv[]) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
