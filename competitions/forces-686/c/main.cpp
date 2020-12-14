#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, temp;
  cin >> n;
  vector<ll> v;
  unordered_map<ll, ll> hm;  // num -> freq
  for (ll i = 0; i < n; ++i) {
    cin >> temp;
    if (v.size() == 0 || v.back() != temp) {
      v.push_back(temp);
      hm[temp]++;
    }
  }

  hm[v.front()]--;
  hm[v.back()]--;

  ll minS = LONG_LONG_MAX;

  for (auto p : hm) {
    if (p.second < minS) {
      minS = p.second;
    }
  }

  cout << minS + 1 << "\n";
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
