#include <cmath>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isUnivalTree(TreeNode* root) { return is_valid(root, root->val); }

bool is_valid(TreeNode* root, int value) {
  if (root == NULL) {
    return true;
  }

  return root->val == value && is_valid(root->left, value) &&
         is_valid(root->right, value);
}