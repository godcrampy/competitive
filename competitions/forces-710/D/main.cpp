#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  map<ll, ll> m;
  for (ll i = 0; i < n; ++i) {
    ll temp;
    cin >> temp;
    ++m[temp];
  }

  priority_queue<pair<ll, ll>> q;

  for (auto p : m) {
    q.push({p.second, p.first});
  }

  int size = n;

  while (q.size() >= 2) {
    auto a = q.top();
    q.pop();
    auto b = q.top();
    q.pop();

    size -= 2;
    --a.first;
    --b.first;

    if (a.first) {
      q.push(a);
    }

    if (b.first) {
      q.push(b);
    }
  }

  cout << size << "\n";
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
