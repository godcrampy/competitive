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
  // deb2(a, b);
  vector<int> vaa(26, 0);
  vector<int> vbb(26, 0);

  for (char c : a) {
    vaa[c - 'a']++;
  }

  for (char c : b) {
    vbb[c - 'a']++;
  }

  for (int i = 25; i >= 0; --i) {
    if (vaa[i] > vbb[i]) {
      cout << "No\n";
      return;
    }
    vbb[i] -= vaa[i];
    vaa[i] = 0;

    if (vbb[i] == 0) {
      continue;
    }
    if (vbb[i] % k != 0) {
      cout << "No\n";
      return;
    }
    for (int j = i - 1; j >= 0; --j) {
      if (vaa[j] >= vbb[i]) {
        vaa[j] -= vbb[i];
        vbb[i] = 0;
        break;
      } else {
        int setsRequired = vbb[i] / k;
        int setsAvailable = vaa[j] / k;
        vaa[j] -= setsAvailable * k;
        vbb[i] -= setsAvailable * k;
      }
    }
    if (vbb[i] != 0) {
      cout << "No\n";
      return;
    }
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
