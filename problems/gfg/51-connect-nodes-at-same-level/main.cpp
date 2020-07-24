
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void connect(Node *p) {
  // Your Code Here
  if (p == NULL) {
    return;
  }

  queue<Node *> q;
  vector<Node *> v;
  q.push(p);

  while (!q.empty()) {
    v = {};
    while (!q.empty()) {
      v.push_back(q.front());
      q.pop();
    }

    for (int i = 0; i < v.size() - 1; ++i) {
      v[i]->nextRight = v[i + 1];
    }
    v.back()->nextRight = NULL;

    for (auto n : v) {
      if (n->left != NULL) {
        q.push(n->left);
      }
      if (n->right != NULL) {
        q.push(n->right);
      }
    }
  }
}
