#include <cmath>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int distributeCoins(TreeNode* root) {
  int res = 0;
  get_moves(root, res);
  return res;
}

int get_moves(TreeNode* root, int& res) {
  if (root == NULL) {
    return 0;
  }

  int L = get_moves(root->left, res);
  int R = get_moves(root->right, res);

  res += abs(L) + abs(R);

  return L + R + root->val - 1;
}