#include <iostream>
#include <vector>

using namespace std;

void print_length_of_subsequence(vector<long> a, vector<long> b, vector<long> c)
{
  // Assumption: 1 index array
  int m = a.size(), n = b.size(), o = c.size();
  long table[m][n][o];
  for (auto i = 0; i < m; ++i)
    for (auto j = 0; j < n; ++j)
      for (auto k = 0; k < o; ++k)
        table[i][j][k] = 0;

  // Fill the table
  for (int i = 1; i < m; ++i)
    for (int j = 1; j < n; ++j)
      for (int k = 1; k < o; ++k)
      {
        long t = table[i - 1][j][k];
        long u = table[i][j - 1][k];
        long v = table[i][j][k - 1];
        long w = table[i - 1][j - 1][k];
        long x = table[i - 1][j][k - 1];
        long y = table[i][j - 1][k - 1];
        long z = (a[i] == b[j] && b[j] == c[k]) ? (table[i - 1][j - 1][k - 1] + 1) : (table[i - 1][j - 1][k - 1]);
        table[i][j][k] = max(t, max(u, max(v, max(w, max(x, max(y, z))))));
      }

  cout << table[m - 1][n - 1][o - 1] << endl;
}

int main()
{
  int n, m, o;
  cin >> m;
  vector<long> a(m + 1, 0);
  for (auto i = 1; i <= m; ++i)
    cin >> a[i];
  cin >> n;
  vector<long> b(n + 1, 0);
  for (auto j = 1; j <= n; ++j)
    cin >> b[j];
  cin >> o;
  vector<long> c(o + 1, 0);
  for (auto k = 1; k <= o; ++k)
    cin >> c[k];
  print_length_of_subsequence(a, b, c);
  return 0;
}