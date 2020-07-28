#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  long long sumSoFar = 0;
  vector<long> v(n);
  vector<long long> prefixSum(n);
  unordered_map<long long, vector<int>> m;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    sumSoFar += v[i];
    prefixSum[i] = sumSoFar;
    m[sumSoFar].push_back(i);
  }

  long count = 0;
  for (auto p : m) {
    auto size = p.second.size();
    count += (size * (size - 1)) / 2;
  }

  count += m[0].size();

  cout << count << endl;
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
