#include <cmath>

// IMP
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
  if (root == NULL) return;

  flatten(root->left);
  flatten(root->right);

  TreeNode* itr = root;
  TreeNode* temp = root->right;
  root->right = root->left;
  while (itr->right != NULL) {
    itr = itr->right;
  }

  itr->right = temp;
  root->left = NULL;
}