#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll numberOfPaths(vector<ll> current, vector<pair<ll, ll>> remEdges) {
  if (remEdges.size() == 0) {
    return 0;
  }
  ll count = 0;
  ll last;
  if (current.size()) {
    last = current.back();
  }

  for (ll i = 0; i < remEdges.size(); ++i) {
    auto p = remEdges[i];

    if (last == p.first) {
      vector<pair<ll, ll>> cop(remEdges);
      cop.erase(cop.begin() + i);
      current.push_back(p.second);
      count += numberOfPaths(current, cop) + 1;
    }

    else if (last == p.second) {
      vector<pair<ll, ll>> cop(remEdges);
      cop.erase(cop.begin() + i);
      current.push_back(p.first);
      count += numberOfPaths(current, cop) + 1;
    } else if (current.size() == 0) {
      vector<pair<ll, ll>> cop(remEdges);
      cop.erase(cop.begin() + i);
      current.push_back(p.first);
      current.push_back(p.second);
      count += numberOfPaths(current, cop) + 1;
    }
  }

  return count;
}

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> edges;

  for (ll i = 0; i < n; ++i) {
    pair<ll, ll> p;
    cin >> p.first;
    cin >> p.second;

    edges.push_back(p);
  }
  vector<ll> current = {};
  cout << numberOfPaths(current, edges) << "\n";
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
