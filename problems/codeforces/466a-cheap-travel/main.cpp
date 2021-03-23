#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  ll combo = n / m;
  ll remainder = n % m;
  ll cost = combo * (min(b, a * m)) + min(b, remainder * a);
  cout << cost << "\n";
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
