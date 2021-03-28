#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  ll sum = 0;
  bool isTwo = false;
  ll temp;
  for (ll i = 0; i < n; ++i) {
    cin >> temp;
    sum += temp;
    if (temp == 2) {
      isTwo = true;
    }
  }

  if (sum % 2 == 0) {
    cout << "0\n";
  } else {
    if (isTwo) {
      cout << "1\n";
    } else {
      cout << "-1\n";
    }
  }
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
