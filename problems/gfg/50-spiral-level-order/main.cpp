
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

void printSpiral(Node *root) {
  // Your code here
  if (root == NULL) {
    return;
  }

  deque<Node *> q1, q2;
  q1.push_back(root);
  bool leftToRight = true;

  while (!q1.empty()) {
    while (!q1.empty()) {
      auto n = q1.front();
      q1.pop_front();
      cout << n->data << " ";
      if (!leftToRight) {
        q2.push_back(n);
      } else {
        q2.push_front(n);
      }
    }

    while (!q2.empty()) {
      auto n = q2.front();
      q2.pop_front();
      if (leftToRight) {
        if (n->left != NULL) {
          q1.push_back(n->left);
        }

        if (n->right != NULL) {
          q1.push_back(n->right);
        }
      } else {
        if (n->left != NULL) {
          q1.push_front(n->left);
        }

        if (n->right != NULL) {
          q1.push_front(n->right);
        }
      }
    }

    leftToRight = !leftToRight;
  }
}
