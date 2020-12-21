#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
const long mod = 1000000007;

void solve() {
  ll n;
  cin >> n;
  vector<ll> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  string ans = "";
  while (n && nums.size()) {
    if (n >= nums.back()) {
      ans += to_string(nums.back());
      n -= nums.back();
      nums.pop_back();
    } else {
      for (ll i = nums.size() - 1; i >= 0; --i) {
        if (nums[i] <= n) {
          ans += to_string(nums[i]);
          n -= nums[i];
          nums.erase(nums.begin() + i);
          break;
        }
      }
    }
  }

  if (n) {
    cout << "-1\n";
  } else {
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
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
