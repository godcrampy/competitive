void solve(int m[MAX][MAX], int n, int x, int y, string &s,
           vector<string> &res) {
  if (x < 0 || y < 0 || x >= n || y >= n || m[x][y] != 1) return false;

  if (x == n - 1 && y == n - 1) {
    res.push_back(s);
    return;
  }
  m[x][y] = 2;
  string a = s + 'U';
  solve(m, n, x - 1, y, a, res);

  string b = s + 'D';
  solve(m, n, x + 1, y, b, res);

  string c = s + 'L';
  solve(m, n, x, y - 1, c, res);

  string d = s + 'R';
  solve(m, n, x, y + 1, d, res);

  m[x][y] = 1;
}
// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
vector<string> printPath(int m[MAX][MAX], int n) {
  string str;
  vector<string> res;
  solve(m, n, 0, 0, str, res);
  sort(res.begin(), res.end());
  return res;
}
