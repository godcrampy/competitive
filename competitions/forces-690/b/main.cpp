#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  string str;
  cin >> str;
  string rev = str;
  reverse(rev.begin(), rev.end());
  if (str.length() < 4) {
    cout << "NO\n";
    return;
  }
  if (rev.substr(0, 4) == "0202") {
    // 1. end with 2020
    cout << "YES\n";

  } else if (str.substr(0, 1) == "2" && rev.substr(0, 3) == "020") {
    // 2. start with 2 and end with 020
    cout << "YES\n";
  } else if (str.substr(0, 2) == "20" && rev.substr(0, 2) == "02") {
    //  3. start with 20 and end with 20
    cout << "YES\n";
  } else if (str.substr(0, 3) == "202" && rev.substr(0, 1) == "0") {
    // 4. start with 202 and end with 0
    cout << "YES\n";
  } else if (str.substr(0, 4) == "2020") {
    // 5. start with 2020
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
