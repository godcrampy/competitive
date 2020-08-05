string findOrder(string dict[], int n, int K) {
  // Your code here
  unordered_map<char, unordered_set<char>> m;

  for (int i = 0; i < n - 1; ++i) {
    string first = dict[i];
    string second = dict[i + 1];

    int l = min(first.length(), second.length());
    for (int j = 0; j < l; ++j) {
      if (first[j] != second[j]) {
        m[first[j]].insert(second[j]);
        break;
      }
    }
  }

  // topological sort;
  string res;

  unordered_map<char, int> indegree;

  for (auto p : m) {
    indegree[p.first];
    for (auto i : p.second) {
      indegree[i]++;
    }
  }

  queue<char> q;
  for (auto p : indegree) {
    if (p.second == 0) {
      q.push(p.first);
    }
  }

  while (!q.empty()) {
    char top = q.front();
    q.pop();
    res += top;

    for (auto c : m[top]) {
      indegree[c]--;
      if (indegree[c] == 0) q.push(c);
    }
  }
  return res;
}
