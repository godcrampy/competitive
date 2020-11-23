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

  for (ll i = 2; i <= n; ++i) {
    cout << "XOR 1 " << i << "\n";
    cout.flush();
    cin >> xorWithA[i];
  }

  ll xorAB = xorWithA[2];
  ll xorAC = xorWithA[3];
  ll xorBC = xorAB ^ xorAC;
  ll andAB, andBC, andCA;

  cout << "AND 1 2\n";
  cout.flush();
  cin >> andAB;

  cout << "AND 2 3\n";
  cout.flush();
  cin >> andBC;

  cout << "AND 1 3\n";
  cout.flush();
  cin >> andCA;

  ll x = xorAB + 2 * andAB;
  ll y = xorBC + 2 * andBC;
  ll z = xorAC + 2 * andCA;

  ll a = (x + z - y) / 2;
  ll b = (x + y - z) / 2;
  ll c = (y + z - x) / 2;

  vector<ll> ans(n + 1, 0);
  ans[1] = a;
  ans[2] = b;
  ans[3] = c;

  for (ll i = 4; i <= n; ++i) {
    ans[i] = a ^ xorWithA[i];
  }

  cout << "! ";

  for (ll i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
