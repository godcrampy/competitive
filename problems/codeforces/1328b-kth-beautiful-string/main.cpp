#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, k;
  cin >> n >> k;

  // finding first pos:
  ll adder = 1;
  ll i = 0;

  while (i < k) {
    i += adder;
    ++adder;
  }

  ll firstPos = n + 1 - adder;
  ll secondPos = n - adder + i - k + 2;
  string a(n, 'a');
  a[firstPos - 1] = 'b';
  a[secondPos - 1] = 'b';
  cout << a << "\n";
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
