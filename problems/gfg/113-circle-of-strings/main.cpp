#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  if (!n) {
    cout << 0 << endl;
    return;
  }
  vector<string> strings(n);
  for (int i = 0; i < n; ++i) {
    cin >> strings[i];
  }

  if (n == 1) {
    bool test = strings[0].front() == strings[0].back();
    cout << test << endl;
    return;
  }

  vector<int> g[n];

  // create graph
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (strings[i].back() == strings[j].front() && i != j) {
        g[i].push_back(j);
      }
    }
  }

  // check if the graph is connected
  unordered_set<int> visited;
  queue<int> q;
  q.push(0);
  visited.insert(0);

  while (!q.empty()) {
    int top = q.front();
    q.pop();

    for (int i : g[top]) {
      if (visited.find(i) == visited.end()) {
        // not visited
        q.push(i);
        visited.insert(i);
      }
    }
  }

  if (visited.size() != n) {
    cout << 0 << endl;
    return;
  }
  // check if indegree is equal to outdegree
  int indegree[26];
  int outdegree[26];
  fill_n(indegree, 26, 0);
  fill_n(outdegree, 26, 0);
  for (string str : strings) {
    indegree[str.front() - 'a']++;
    outdegree[str.back() - 'a']++;
  }
  for (int i = 0; i < 26; ++i) {
    if (indegree[i] != outdegree[i]) {
      cout << 0 << endl;
      return;
    }
  }

  cout << 1 << endl;
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
