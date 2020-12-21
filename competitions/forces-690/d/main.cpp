#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

bool equalArray(vector<ll> &v) {
  if (v.size() <= 1)
    return true;
  ll first = v[0];

  for (ll i : v) {
    if (i != first)
      return false;
  }
  return true;
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n, 0);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  ll steps = 0;

  while (!equalArray(v)) {
    // find smallest pair
    ll smallest = v[0];
    ll smallestIndex = 0;
    for (ll i = 0; i < v.size() - 1; ++i) {
      if (v[i] < smallest) {
        smallest = v[i];
        smallestIndex = i;
      }
    }

    // merge smallest pair
    steps++;
    if (smallestIndex == 0) {
      v[smallestIndex + 1] += v[smallestIndex];
      v.erase(v.begin());
      continue;
    }
    if (smallestIndex == v.size() - 1) {
      v[smallestIndex - 1] += v[smallestIndex];
      v.pop_back();
      continue;
    }
    ll nextMin = v[smallestIndex - 1];
    ll nextMinIndex = smallestIndex - 1;

    if (v[smallestIndex + 1] < nextMin) {
      nextMin = v[smallestIndex + 1];
      nextMinIndex = smallestIndex + 1;
    }
    v[smallestIndex] += nextMin;
    v.erase(v.begin() + nextMinIndex);
  }
  cout << steps << "\n";
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
