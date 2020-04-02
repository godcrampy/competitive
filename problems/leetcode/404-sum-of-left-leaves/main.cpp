#include <cmath>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root) {
  if (root == NULL) {
    return 0;
  }
  if (is_leaf(root->left)) {
    return root->left->val + sumOfLeftLeaves(root->right);
  }
  return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

bool is_leaf(TreeNode* root) {
  if (root == NULL) {
    return false;
  }
  return root->left == NULL && root->right == NULL;
}