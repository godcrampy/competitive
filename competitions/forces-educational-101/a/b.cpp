#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

bool solvable(int pos, string &s, int stk) {
  // deb(s);
  // deb2(pos, stk);
  if (stk < 0) {
    return false;
  }
  if (pos >= s.length()) {
    return stk == 0;
  }

  char next = s[pos];
  switch (next) {
    case '(':
      return solvable(pos + 1, s, stk + 1);
    case ')':
      return solvable(pos + 1, s, stk - 1);

    default:
      return solvable(pos + 1, s, stk + 1) || solvable(pos + 1, s, stk - 1);
      break;
  }
}

void solve() {
  string s;
  cin >> s;
  if (solvable(0, s, 0)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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
