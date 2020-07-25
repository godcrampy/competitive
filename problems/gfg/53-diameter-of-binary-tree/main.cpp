
/* Tree node structure  used in the program
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

pair<int, int> diaUtil(Node* node) {  // height, maxDia
  if (node == NULL) {
    return {0, 0};
  }

  auto p1 = diaUtil(node->left);
  auto p2 = diaUtil(node->right);

  return {1 + max(p1.first, p2.first),
          max(p1.first + p2.first + 1, max(p1.second, p2.second))};
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
  // Your code here
  return diaUtil(node).second;
}
