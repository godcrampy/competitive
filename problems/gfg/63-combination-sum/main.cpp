#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void recurse(vector<vector<int>> &sol, vector<int> &res, const vector<int> &v,
             int i, int sum) {
  int n = v.size();

  if (sum < 0) {
    return;
  }

  if (sum == 0) {
    sol.push_back(res);
    return;
  }

  if (i >= n) {
    return;
  }

  res.push_back(v[i]);
  recurse(sol, res, v, i + 1, sum - v[i]);
  res.pop_back();
  int temp = v[i];
  while (i < n && v[i] == temp) {
    i++;
  }
  recurse(sol, res, v, i, sum);
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  int sum;
  cin >> sum;
  vector<int> res(0);
  vector<vector<int>> sol(0);
  recurse(sol, res, v, 0, sum);

  if (sol.size() == 0) {
    cout << "Empty\n";
    return;
  }
  for (auto v : sol) {
    cout << "(";
    for (int i = 0; i < v.size() - 1; ++i) {
      cout << v[i] << " ";
    }
    cout << v[v.size() - 1] << ")";
  }
  cout << endl;
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
