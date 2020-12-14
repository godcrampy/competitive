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
  ll count = 0;
  ll curl = 0, sqr = 0;

  for (char c : s) {
    if (c == '(') {
      ++curl;
    } else if (c == '[') {
      ++sqr;
    } else if (c == ']' && sqr) {
      --sqr;
      ++count;
    } else if (c == ')' && curl) {
      --curl;
      ++count;
    }
  }

  cout << count << "\n";
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
