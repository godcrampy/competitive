#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  char s[1001];
  cin.getline(s, sizeof(s));
  int n = strlen(s);

  bool visited[256];
  fill_n(visited, 256, false);
  int index = 0;

  for (int i = 0; i <= n; ++i) {
    if (!visited[s[i]]) {
      s[index++] = s[i];
      visited[s[i]] = true;
    }
  }

  cout << s << endl;
}

int main(int argc, char const* argv[]) {
  int t;
  cin >> t;
  getchar();

  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
