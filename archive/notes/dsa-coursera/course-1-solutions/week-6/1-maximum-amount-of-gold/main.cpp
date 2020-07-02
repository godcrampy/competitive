#include <iostream>
#include <vector>

using namespace std;

int get_optimal_weight(int W, vector<int> &weights) {
  // weights is one indexed
  int n = weights.size() - 1;
  vector<vector<int>> table(n + 1, {0});
  for (int i = 0; i <= n; ++i) {
    vector<int> temp(W + 1, 0);
    table[i] = temp;
  }
  for (int w = 0; w <= W; ++w) table[0][w] = 0;
  for (int i = 0; i <= n; ++i) table[i][0] = 0;
  for (int w = 1; w <= W; ++w)
    for (int i = 1; i <= n; ++i) {
      int a =
          w - weights[i] >= 0 ? table[i - 1][w - weights[i]] + weights[i] : -1;
      int b = table[i - 1][w];
      table[i][w] = max(a, b);
    }
  return table[n][W];
}

int main(int argc, char const *argv[]) {
  int W, n;
  cin >> W >> n;
  vector<int> weights(n + 1, 0);
  for (int i = 1; i <= n; ++i) cin >> weights[i];
  cout << get_optimal_weight(W, weights) << endl;
  return 0;
}
