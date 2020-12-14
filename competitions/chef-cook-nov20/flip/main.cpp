#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

int diff(vector<char> &a, vector<char> &b) {
  int count = 0;
  bool changing = false;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == b[i] && changing) {
      changing = false;
    } else if (a[i] != b[i]) {
      count += !changing;
      changing = true;
    }
  }
  return count;
}

void solve() {
  string a, b;
  cin >> a >> b;
  vector<char> vaodd, vaeven, vbodd, vbeven;

  for (int i = 0; i < a.size(); ++i) {
    if (i % 2) {
      // odd
      vaodd.push_back(a[i]);
      vbodd.push_back(b[i]);
    } else {
      vaeven.push_back(a[i]);
      vbeven.push_back(b[i]);
    }
  }

  cout << diff(vaodd, vbodd) + diff(vaeven, vbeven) << "\n";
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
