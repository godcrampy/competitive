#include <cmath>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* pruneTree(TreeNode* root) {
  if (!has_one(root)) return NULL;
  root->left = pruneTree(root->left);
  root->right = pruneTree(root->right);
  return root;
}

bool has_one(TreeNode* root) {
  if (root == NULL) return false;
  return root->val == 1 || has_one(root->left) || has_one(root->right);
}