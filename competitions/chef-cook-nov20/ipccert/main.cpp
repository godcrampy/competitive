#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, m, k, count = 0;
  cin >> n >> m >> k;

  for (ll i = 0; i < n; ++i) {
    ll time = 0, temp;
    for (ll j = 0; j < k; ++j) {
      cin >> temp;
      time += temp;
    }
    ll times;
    cin >> times;

    if (time >= m && times <= 10) {
      ++count;
    }
  }
  cout << count << "\n";
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
