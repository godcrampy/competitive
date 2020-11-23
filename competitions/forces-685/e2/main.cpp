#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

int main(int argc, char const *argv[]) {
  ll n;
  cin >> n;
  vector<ll> xorWithA(n + 1, 0);
  vector<vector<ll>> pos(n);
  vector<ll> ans(n + 1, 0);

  for (ll i = 2; i <= n; ++i) {
    cout << "XOR 1 " << i << "\n";
    cout.flush();
    cin >> xorWithA[i];
    pos[xorWithA[i]].push_back(i);
  }

  ll aPos = 1, bPos = -1, cPos = -1;
  ll a, b, c;
  ll same = -1;

  for (int i = 0; i < n; ++i) {
    auto v = pos[i];
    if (v.size() > 1) {
      // numbers with same xor => same numbers
      bPos = v[0];
      cPos = v[1];
      same = i;
    }
  }

  if (same == -1) {
    // no same numbers
    // i = 2 or 3 since i = 1 may pair up with either of the two
    for (ll i = 2; i <= 3; ++i) {
      for (ll j = i + 1; j <= n; ++j) {
        if ((xorWithA[i] ^ xorWithA[j]) == n - 1) {
          bPos = i;
          cPos = j;
          break;
        }
      }
    }

    ll xorAB = xorWithA[bPos];
    ll xorAC = xorWithA[cPos];
    ll xorBC = xorAB ^ xorAC;

    ll andAB, andBC = 0, andCA;

    cout << "AND 1 " << bPos << "\n";
    cout.flush();
    cin >> andAB;

    cout << "AND 1 " << cPos << "\n";
    cout.flush();
    cin >> andCA;

    ll x = xorAB + 2 * andAB;
    ll y = xorBC + 2 * andBC;
    ll z = xorAC + 2 * andCA;

    a = (x + z - y) / 2;
    b = (x + y - z) / 2;
    c = (y + z - x) / 2;

    ans[1] = a;
    ans[bPos] = b;
    ans[cPos] = c;
  } else {
    // two same numbers
    cout << "AND " << bPos << " " << cPos << "\n";
    cout.flush();
    cin >> ans[bPos];
    ans[cPos] = ans[bPos];
    b = ans[bPos];
    c = ans[bPos];
    a = b ^ xorWithA[bPos];
    ans[1] = a;
  }

  for (ll i = 2; i <= n; ++i) {
    ans[i] = a ^ xorWithA[i];
  }

  cout << "! ";

  for (ll i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
