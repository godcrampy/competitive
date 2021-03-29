#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  ll oddCount = 0, evenCount = 0;
  ll lastOdd = -1, lastEven = -1;

  for (ll i = 0; i < n; ++i) {
    if (v[i] % 2 == 1) {
      ++oddCount;
      lastOdd = i;
    } else {
      ++evenCount;
      lastEven = i;
    }
  }

  if (oddCount == 1) {
    cout << lastOdd + 1 << "\n";
  } else {
    cout << lastEven + 1 << "\n";
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
