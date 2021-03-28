#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  vector<int> v(n);
  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  ll maxOnes = -1, count = 0;

  for (ll i = 0; i < n; ++i) {
    count = 0;
    ll prev = 0;
    ll fin = 0;
    for (ll j = 0; j < i; ++j) {
      prev += v[j];
    }
    for (ll j = i; j < n; ++j) {
      fin += v[j];
    }

    for (ll j = i; j < n; ++j) {
      if (v[j] == 0) {
        ++count;
      } else {
        --fin;
      }

      maxOnes = max(maxOnes, prev + count + fin);
    }
  }

  cout << maxOnes << "\n";
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
