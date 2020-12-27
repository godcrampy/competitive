#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, temp;
  cin >> n;

  vector<ll> m(n + 2, 0); // number => frequency

  for (ll i = 0; i < n; ++i) {
    cin >> temp;
    m[temp]++;
  }

  ll count = 0;

  for (int i = 2; i < n; i++) {
    count += m[i - 1] * m[i] * m[i + 1];
  }
  for (int i = 1; i < n; i++) {
    count += m[i] * (m[i] - 1) / 2 * m[i + 1];
  }
  for (int i = 2; i <= n; i++) {
    count += m[i - 1] * m[i] * (m[i] - 1) / 2;
  }
  for (int i = 2; i < n; i++) {
    count += m[i - 1] * m[i + 1] * (m[i + 1] - 1) / 2;
  }
  for (int i = 2; i < n; i++) {
    count += m[i + 1] * m[i - 1] * (m[i - 1] - 1) / 2;
  }
  for (int i = 1; i <= n; i++) {
    count += m[i] * (m[i] - 1) * (m[i] - 2) / 6;
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
