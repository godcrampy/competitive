#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  ll i = s.find_first_of("*");
  ll count = 1;

  while (true) {
    ll j = min(i + k, n - 1);
    while (i < j && s[j] == '.') {
      --j;
    }

    if (i == j) break;
    ++count;
    i = j;
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
