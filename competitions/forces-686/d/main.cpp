#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, copy;
  cin >> n;
  copy = n;
  unordered_map<ll, ll> divisors;

  while (n % 2 == 0) {
    n /= 2;
    divisors[2]++;
  }

  for (ll i = 3; n != 1 && i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      n /= i;
      divisors[i]++;
    }
  }
  if (n > 2) {
    divisors[n]++;
  }

  if (divisors.size() == 0) {
    cout << "1\n";
    cout << copy << "\n";
    return;
  }
  ll maxNum = -1, maxCount = -1;
  for (auto p : divisors) {
    if (p.second > maxCount) {
      maxNum = p.first;
      maxCount = p.second;
    }
  }

  vector<ll> ans(maxCount, maxNum);

  for (auto p : divisors) {
    if (p.first != maxNum) {
      for (ll i = 0; i < p.second; ++i) {
        ans.back() *= p.first;
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
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
