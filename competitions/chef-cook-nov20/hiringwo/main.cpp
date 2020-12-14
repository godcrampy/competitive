#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll minSumReq(vector<ll> v, ll n) {
  if (n >= v.size()) {
    ll sum = 0;
    for (ll i : v) {
      sum += i;
    }
    sum += n - v.size();
    return sum;
  }
  // cout << "ss\n";
  ll last = v.back();
  v.pop_back();
  ll minSum = minSumReq(v, n - 1) + last;

  for (int i = 0; i < v.size(); ++i) {
    v[i] *= last;
    minSum = min(minSum, minSumReq(v, n));
    v[i] /= last;
  }
  v.push_back(last);
  return minSum;
}

void solve() {
  ll k, x;
  cin >> k >> x;

  vector<ll> factors;  // {number, count}

  for (ll i = 2; x != 1; ++i) {
    if (x % i == 0) {
      // divisible
      ll temp = 1;
      while (x % i == 0) {
        x /= i;
        temp *= i;
      }
      factors.push_back(temp);
    }
  }
  sort(factors.begin(), factors.end(), greater<ll>());
  cout << minSumReq(factors, k) << "\n";
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
