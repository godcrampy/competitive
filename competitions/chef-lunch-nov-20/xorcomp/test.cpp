#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl

ll randomNumber(ll l, ll r) {
  // * Returns a random integer from [l, r]
  return l + (std::rand() % (r - l + 1));
}

template <typename T>
void printVector(const vector<T> &v, string msg) {
  cout << msg;
  for (auto n : v) {
    cout << n << " ";
  }
  cout << endl;
}

ll toggle(ll n, ll k) { return (n ^ (1 << (k - 1))); }

ll leftMostSetBit(ll n) {
  if (n == 0) return 0;

  ll msb = 1;
  n = n / 2;
  while (n != 0) {
    n = n / 2;
    msb++;
  }

  return msb;
}

void construct(unordered_set<ll> &s, ll nextK, ll fixedK, ll n) {
  if (nextK >= 20) return;
  if (nextK == fixedK) {
    construct(s, nextK + 1, fixedK, n);
    return;
  }
  ll initialSize = s.size();
  for (ll i : s) {
    ll temp = toggle(i, nextK);
    if (temp <= n) {
      s.insert(temp);
    }
  }

  if (initialSize < s.size()) {
    construct(s, nextK + 1, fixedK, n);
  }
}

bool kthBit(ll n, ll k) { return ((n & (1 << (k - 1))) >> (k - 1)); }

ll solve(ll x, ll y, ll n) {
  if (x == y) {
    return 0;
  }
  ll firstBitDifferentFromLeft = leftMostSetBit(x ^ y);
  ll xK = kthBit(x, firstBitDifferentFromLeft);
  ll yK = kthBit(y, firstBitDifferentFromLeft);
  ll nFirstBitDifferent = leftMostSetBit(n);
  ll count = 0;

  ll str = 0;
  if (xK) {
    ll start = 1 << (min(nFirstBitDifferent, firstBitDifferentFromLeft) - 1);
    for (ll i = start; i <= n; ++i) {
      if ((i ^ x) < (y ^ i)) {
        ++count;
      }
    }
    return count;
  }

  for (ll i = 1; i < nFirstBitDifferent; ++i) {
    // cout << i << "\n";
    if (i == firstBitDifferentFromLeft) continue;
    if (count == 0) {
      count = 2;
    } else {
      count *= 2;
    }
  }

  ll start = 1 << (nFirstBitDifferent - 1);
  for (ll i = start; i <= n; ++i) {
    if ((i ^ x) < (y ^ i)) {
      ++count;
    }
  }

  return count;
}
ll solveNaive(ll x, ll y, ll n) {
  ll count = 0;

  for (ll i = 0; i <= n; ++i) {
    if ((i ^ x) < (y ^ i)) {
      // deb(i);
      ++count;
    }
  }

  return count;
}

void smokeTest() {
  ll i = 1;
  while (true) {
    deb(i++);
    ll x, y, n;
    x = randomNumber(0, 10);
    y = randomNumber(0, 10);
    n = 0;
    deb2(x, y);
    deb(n);
    ll naive = solveNaive(x, y, n);
    ll fast = solve(x, y, n);
    if (naive != fast) {
      deb2(naive, fast);
      return;
    }
  }
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(0));

  smokeTest();
  return 0;
}
