#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

ll numFactors(ll n) {
  ll count = 0;
  for (ll i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      if (i * i == n) {
        ++count;
      } else {
        count += 2;
      }
    }
  }

  return count;
}

void solve() {
  ll n;
  cin >> n;
  ll numPrimes = 1000000;
  vector<bool> isPrime(numPrimes + 1, true);

  for (ll i = 2; i <= numPrimes; ++i) {
    if (isPrime[i]) {
      for (ll j = i * i; j <= numPrimes; j += i) {
        isPrime[j] = false;
      }
    }
  }

  set<ll> tPrimes;

  for (ll i = 2; i <= numPrimes; ++i) {
    if (isPrime[i]) {
      tPrimes.insert(i * i);
    }
  }

  while (n--) {
    ll temp;
    cin >> temp;
    if (tPrimes.find(temp) == tPrimes.end()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}

int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
