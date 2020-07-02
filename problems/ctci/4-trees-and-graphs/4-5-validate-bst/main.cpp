#include <limits.h>

#include <cmath>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ! IMP

// * Checked Working on Leetcode

bool validateBst(TreeNode* root, int min, int max) {
  if (root == NULL) {
    return true;
  }

  if (root->val <= min || root->val >= max) return false;

  return validateBst(root->left, min, root->val) &&
         validateBst(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
  // * Time: O(number of nodes)
  // * Space: O(log(number of nodes)) [height of tree]
  return validateBst(root, INT_MIN, INT_MAX);
}