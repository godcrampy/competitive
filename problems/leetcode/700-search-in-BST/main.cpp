#include <cmath>

// IMP
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
  if (root == NULL) return NULL;

  if (val > root->val) {
    return searchBST(root->right, val);
  }

  if (val < root->val) {
    return searchBST(root->left, val);
  }

  return root;
}