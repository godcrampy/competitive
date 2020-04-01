#include <cmath>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isCompleteTree(TreeNode* root) {
  int n = nodes(root);
  queue<TreeNode*> to_visit;
  to_visit.push(root);
  int count = 1;
  while (!to_visit.empty()) {
    auto node = to_visit.front();
    to_visit.pop();
    if (node->left == NULL) {
      break;
    }
    to_visit.push(node->left);
    ++count;
    if (node->right == NULL) {
      break;
    }
    to_visit.push(node->right);
    ++count;
  }

  return count == n;
}

int nodes(TreeNode* root) {
  if (root == NULL) {
    return 0;
  }

  return 1 + nodes(root->left) + nodes(root->right);
}