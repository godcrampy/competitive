#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n, k;
  cin >> n >> k;
  string a, b;
  cin >> a >> b;
  vector<int> vaa(27, 0);
  vector<int> vbb(27, 0);

  for (char c : a) {
    vaa[c - 'a']++;
  }

  for (char c : b) {
    vbb[c - 'a']++;
  }

  for (int i = 0; i < 26; ++i) {
    if (vbb[i] > vaa[i]) {
      cout << "No\n";
      return;
    }
    vaa[i] -= vbb[i];
    if (vaa[i] % k != 0) {
      cout << "No\n";
      return;
    }
    vaa[i + 1] += vaa[i];
  }

  cout << "Yes\n";
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
