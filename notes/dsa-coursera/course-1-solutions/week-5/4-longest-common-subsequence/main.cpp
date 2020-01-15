#include <iostream>
#include <vector>

using namespace std;

void print_length_of_subsequence(vector<long> a, vector<long> b) {
  // Assumption: 1 index array
  int m = a.size(), n = b.size();
  long table[m][n];
  table[0][0] = 0;
  for (auto i = 1; i < m; ++i)
    table[i][0] = 0;
  for (auto j = 0; j < n; ++j)
    table[0][j] = 0;

  // Fill the table
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      long x = table[i - 1][j];
      long y = table[i][j - 1];
      long z = (a[i] == b[j]) ? (table[i - 1][j - 1]) + 1 : (table[i - 1][j - 1]);
      table[i][j] = max(x, max(y, z));
    }
  }

  cout << table[m - 1][n - 1] << endl;
}

int main() {
  int n, m;
  cin >> m;
  vector<long> a(m + 1, 0);
  for (auto i = 1; i <= m; ++i)
    cin >> a[i];
  cin >> n;
  vector<long> b(n + 1, 0);
  for (auto j = 1; j <= n; ++j)
    cin >> b[j];
  print_length_of_subsequence(a, b);
  return 0;
}