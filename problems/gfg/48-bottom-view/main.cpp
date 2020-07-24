/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
vector<int> bottomView(Node *root) {
  if (root == NULL) {
    return {};
  }
  // make map of vertical order
  unordered_map<int, vector<int>> m;  // hd => node values
  queue<pair<Node *, int>> q;         // node, hd
  q.push({root, 0});
  int minD = 0, maxD = 0;

  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    auto node = p.first;
    int hd = p.second;
    m[hd].push_back(node->data);

    if (node->left != NULL) {
      q.push({node->left, hd - 1});
      minD = min(minD, hd - 1);
    }

    if (node->right != NULL) {
      q.push({node->right, hd + 1});
      maxD = max(maxD, hd + 1);
    }
  }
  // treaverse from left to right
  vector<int> res;
  for (int i = minD; i <= maxD; ++i) {
    res.push_back(m[i].back());
  }

  return res;
}
