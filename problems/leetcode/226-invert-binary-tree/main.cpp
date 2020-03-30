#include <cmath>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
  if (root == NULL) {
    return NULL;
  }

  // swap
  TreeNode* temp = root->left;
  root->left = root->right;
  root->right = temp;

  // recurse
  root->left = invertTree(root->left);
  root->right = invertTree(root->right);

  return root;
}