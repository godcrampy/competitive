#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n, 0);

  for (ll i = 0; i < n; ++i) {
    cin >> v[i];
  }

  vector<double> l, r;
  double sumL = 0.0, sumR = 0.0;

  for (ll i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      // l
      sumL += v[i];
      auto sz = l.size() + 1;
      l.push_back(sumL / (double)(sz));
    } else {
      // r
      sumR += v[i];
      auto sz = r.size() + 1;
      r.push_back(sumR / (double)(sz));
    }
  }

  vector<pair<double, double>> grid;
  grid.push_back({l[0] + r[0], LONG_LONG_MAX});
  ll lLen = l.size();

  for (ll i = 1; i < lLen - 1; ++i) {
    grid.push_back({l[i] + r[i], l[i] + r[i - 1]});
  }

  if (lLen != 1) {
    if (lLen == r.size()) {
      grid.push_back({l[lLen - 1] + r[lLen - 1], l[lLen - 1] + r[lLen - 2]});
    } else {
      grid.push_back(
          {LONG_LONG_MAX, (double)l[lLen - 1] + (double)r[lLen - 2]});
    }
  }

  ll minSum = grid[0].first;
  ll minI = 0, minJ = 0;

  for (ll i = 1; i < grid.size(); ++i) {
    auto p = grid[i];
    if (p.first <= minSum) {
      minSum = p.first;
      minI = i;
      minJ = i;
    }

    if (p.second <= minSum) {
      minSum = p.second;
      minI = i;
      minJ = i - 1;
    }
  }

  vector<ll> left, right;

  for (ll i = 0; i <= minI; ++i) {
    left.push_back(v[i * 2]);
  }

  for (ll i = 0; i <= minJ; ++i) {
    right.push_back(v[i * 2 + 1]);
  }

  ll leftMin = *min_element(left.begin(), left.end());
  ll rightMin = *min_element(right.begin(), right.end());

  ll leftCount = 0, leftCost = 0, rightCost = 0, rightCount = 0;

  for (ll lval : left) {
    if (lval != leftMin) {
      ++leftCount;
      leftCost += lval;
    }
  }

  for (ll rval : right) {
    if (rval != rightMin) {
      ++rightCount;
      rightCost += rval;
    }
  }

  leftCost += (n - leftCount) * leftMin;
  rightCost += (n - rightCount) * rightMin;

  cout << leftCost + rightCost << "\n";
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
