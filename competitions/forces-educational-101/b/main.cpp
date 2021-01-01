#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll m, n, temp;
  vector<ll> a = {0}, b = {0};
  cin >> m;
  for (ll i = 0; i < m; ++i) {
    cin >> temp;
    a.push_back(temp + a.back());
  }

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> temp;
    b.push_back(temp + b.back());
  }

  cout << *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end())
       << "\n";
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
