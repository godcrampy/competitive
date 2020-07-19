#include <bits/stdc++.h>

using namespace std;

long roadsAndLibraries(int n, int c_lib, int c_road,
                       vector<vector<int>> cities) {
  if (c_lib <= c_road) {
    return (long)n * (long)c_lib;
  }

  unordered_map<int, unordered_set<int>> neighbours;

  for (auto v : cities) {
    neighbours[v[0]].insert(v[1]);
    neighbours[v[1]].insert(v[0]);
  }
  unordered_set<int> left;

  for (int i = 1; i <= n; ++i) {
    left.insert(i);
  }

  // get number of islands
  long numberOfIslands = 0;
  while (left.size() != 0) {
    ++numberOfIslands;
    queue<int> dfs;
    dfs.push(*left.begin());
    while (!dfs.empty()) {
      int top = dfs.front();
      dfs.pop();
      left.erase(top);
      for (int i : neighbours[top]) {
        if (left.find(i) != left.end()) {
          dfs.push(i);
        }
      }
    }
  }

  return numberOfIslands * (long)c_lib + (n - numberOfIslands) * (long)c_road;
}
