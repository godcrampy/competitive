/* A binary tree node structure

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

pair<bool, int> isBalancedAndHeight(Node* root) {
  if (root == NULL) {
    return {true, 0};
  }

  auto pl = isBalancedAndHeight(root->left);
  auto pr = isBalancedAndHeight(root->right);
  bool balanced = pl.first && pr.first && abs(pl.second - pr.second) <= 1;

  return {balanced, 1 + max(pr.second, pl.second)};
}

// This function should return tree if passed  tree
// is balanced, else false.
bool isBalanced(Node* root) {
  //  Your Code here
  return isBalancedAndHeight(root).first;
}
