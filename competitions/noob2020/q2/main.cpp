#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

string charToDir(char c) {
  if (c == 'e') {
    return "east";
  }
  if (c == 'w') {
    return "west";
  }
  if (c == 'n') {
    return "north";
  }
  return "south";
}

void solve() {
  string a, b;
  cin >> a >> b;
  ll la = a.length(), lb = b.length();
  unordered_map<char, ll> hma, hmb;
  ll maxA = 0, maxB = 0;

  for (int i = 0; i < la - 1; ++i) {
    hma[a[i]]++;
    maxA = max(maxA, hma[a[i]]);
  }

  for (int i = 0; i < lb - 1; ++i) {
    hmb[b[i]]++;
    maxB = max(maxB, hmb[b[i]]);
  }

  cout << maxA << " " << charToDir(a.back()) << " " << maxB << " "
       << charToDir(b.back()) << "\n";
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
