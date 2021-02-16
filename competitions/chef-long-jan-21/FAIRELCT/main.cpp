#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  ll sumA = 0, sumB = 0;

  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    sumA += a[i];
  }

  for (ll i = 0; i < m; ++i) {
    cin >> b[i];
    sumB += b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<ll>());
  ll i = 0, j = 0, count = 0;

  while (i < a.size() && j < b.size() && sumA <= sumB) {
    ll change = b[j] - a[i];
    swap(a[i++], b[j++]);
    sumA += change;
    sumB -= change;
    ++count;
  }

  if (sumA > sumB) {
    cout << count << "\n";
  } else {
    cout << "-1\n";
  }
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
