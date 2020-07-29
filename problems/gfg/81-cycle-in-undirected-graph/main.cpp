
bool isCyclic(vector<int> g[], int N) {
  bool visited[N];
  fill_n(visited, N, false);
  stack<int> s;
  s.push(0);
  unordered_map<int, int> m;  // child -> parent
  unordered_set<int>
      remaining;  // used instead of visited as there may be islands of graphs
  for (int i = 1; i < N; ++i) {
    remaining.insert(i);
  }

  m[0] = -1;

  while (!s.empty() || !remaining.empty()) {
    if (s.empty()) {
      // find next island
      s.push(*remaining.begin());
      remaining.erase(remaining.begin());
    }
    int top = s.top();
    s.pop();

    for (int i : g[top]) {
      if (remaining.find(i) != remaining.end()) {
        remaining.erase(i);
        //   visited[i] = true;
        s.push(i);
        m[i] = top;
      } else {
        if (i != m[top]) {
          //   cout << "i" << i << endl;
          return true;
        }
      }
    }
  }
  return false;
}