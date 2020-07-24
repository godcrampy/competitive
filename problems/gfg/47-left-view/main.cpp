/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// A wrapper over leftViewUtil()
void leftView(Node *root) {
  if (root == NULL) {
    return;
  }
  vector<int> res;
  deque<Node *> q1, q2;
  q1.push_back(root);

  while (!q1.empty()) {
    cout << q1.front()->data << " ";

    while (!q1.empty()) {
      q2.push_back(q1.front());
      q1.pop_front();
    }

    while (!q2.empty()) {
      auto n = q2.front();
      q2.pop_front();
      if (n->left != NULL) {
        q1.push_back(n->left);
      }
      if (n->right != NULL) {
        q1.push_back(n->right);
      }
    }
  }
}
