#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, k;
  cin >> n >> k;
  unordered_map<ll, ll> hm;  // skill -> quantity
  ll temp, comp, teams = 0;
  while (n--) {
    cin >> temp;
    comp = k - temp;
    if (hm.find(comp) != hm.end()) {
      --hm[comp];
      ++teams;
      if (hm[comp] == 0) {
        hm.erase(comp);
      }
    } else {
      hm[temp]++;
    }
  }

  cout << teams << "\n";
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
