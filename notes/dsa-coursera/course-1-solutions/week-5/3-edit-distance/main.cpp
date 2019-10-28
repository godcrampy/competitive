#include <iostream>
#include <string>

using namespace std;

int edit_distance(string a, string b)
{
  int m = a.length();
  int n = b.length();
  int table[m + 1][n + 1];
  table[0][0] = 0;
  for (auto i = 1; i <= m; ++i)
    table[i][0] = i;
  for (auto j = 1; j <= n; ++j)
    table[0][j] = j;

  // filling the table
  for (auto i = 1; i <= m; ++i)
  {
    for (auto j = 1; j <= n; ++j)
    {
      int x = (a[i - 1] == b[j - 1]) ? (table[i - 1][j - 1]) : (table[i - 1][j - 1] + 1);
      int y = table[i - 1][j] + 1;
      int z = table[i][j - 1] + 1;
      table[i][j] = min(x, min(y, z));
    }
  }
  return table[m][n];
}

int main(int argc, char const *argv[])
{
  string a, b;
  getline(cin, a);
  getline(cin, b);
  cout << edit_distance(a, b) << endl;
  return 0;
}
