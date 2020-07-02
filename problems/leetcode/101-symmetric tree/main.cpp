#include <cmath>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* root) {
  if (root == NULL) {
    return true;
  }
  return is_sym(root->left, root->right);
}

bool is_sym(TreeNode* a, TreeNode* b) {
  if (a == NULL && b == NULL) {
    return true;
  }

  if (a == NULL || b == NULL) {
    return false;
  }

  return a->val == b->val & is_sym(a->left, b->right) &
         is_sym(a->right, b->left);
}

bool isSymmetricIterative(TreeNode* root) {
  if (root == NULL) {
    return true;
  }
  stack<TreeNode*> s;

  s.push(root->left);
  s.push(root->right);

  while (!s.empty()) {
    TreeNode* a = s.top();
    s.pop();
    if (s.empty()) return false;
    TreeNode* b = s.top();
    s.pop();
    if (a == NULL && b == NULL) continue;
    if (a == NULL || b == NULL || a->val != b->val) return false;
    s.push(a->left);
    s.push(b->right);
    s.push(a->right);
    s.push(b->left);
  }

  return true;
}