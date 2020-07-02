#include <iostream>
#include <vector>

using namespace std;

bool does_partition_exist(vector<int> weights) {
  // assumption 1 indexed vector weights
  int n = weights.size() - 1;
  int w_sum = 0;
  for (int weight : weights) w_sum += weight;
  if (w_sum % 3 != 0) return false;
  int w_each = w_sum / 3;

  // can fit 1
  vector<vector<int>> table_1(n + 1, vector<int>(w_each + 1, 0));
  for (int i = 0; i <= n + 1; ++i) table_1[i][0] = 1;

  for (int i = 1; i <= n + 1; ++i)
    for (int j = 1; j <= w_each + 1; ++j) {
      int a = j - weights[j] >= 0 ? table_1[i - 1][j - weights[j]] : 0;
      int b = table_1[i - 1][j];
      table_1[i][j] = a || b;
    }

  if (table_1[n][w_each] != 1) return false;
}
