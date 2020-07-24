// root: root node of the tree
vector<int> verticalOrder(Node *root) {
  if (root == NULL) {
    return {};
  }

  unordered_map<int, vector<int>> m;  // hd => vals
  queue<pair<Node *, int>> q;         // Node, hd
  q.push({root, 0});
  int minD = 0, maxD = 0;

  while (!q.empty()) {
    auto n = q.front().first;
    int hd = q.front().second;
    q.pop();
    m[hd].push_back(n->data);

    if (n->left != NULL) {
      q.push({n->left, hd - 1});
      minD = min(minD, hd - 1);
    }

    if (n->right != NULL) {
      q.push({n->right, hd + 1});
      maxD = max(maxD, hd + 1);
    }
  }

  vector<int> res;

  for (int i = minD; i <= maxD; ++i) {
    for (int j : m[i]) {
      res.push_back(j);
    }
  }

  return res;
}
