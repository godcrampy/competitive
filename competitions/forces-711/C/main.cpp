#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long long mod = 1000000007;

ll gcdExtended(ll a, ll b, ll *x, ll *y);

// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
ll modInverse(ll b, ll m) {
  ll x, y;  // used in extended GCD algorithm
  ll g = gcdExtended(b, m, &x, &y);

  // Return -1 if b and m are not co-prime
  if (g != 1) return -1;

  // m is added to handle negative x
  return (x % m + m) % m;
}

// Function to compute a/b under modlo m
ll modDivide(ll a, ll b, ll m) {
  a = a % m;
  ll inv = modInverse(b, m);
  return (inv * a) % m;
}

// C function for extended Euclidean Algorithm (used to
// find modular inverse.
ll gcdExtended(ll a, ll b, ll *x, ll *y) {
  // Base Case
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }

  ll x1, y1;  // To store results of recursive call
  ll gcd = gcdExtended(b % a, a, &x1, &y1);

  // Update x and y using results of recursive
  // call
  *x = y1 - (b / a) * x1;
  *y = x1;

  return gcd;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  ll count = 1;
  ll x = n;
  for (ll i = 1; i < k; ++i) {
    x %= mod;
    count += x;
    count %= mod;
    x = modDivide(((x % mod) * ((x - 1) % mod)) % mod, 2, mod);
  }

  cout << count % mod << "\n";
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
