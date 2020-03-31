#include <limits.h>

#include <cmath>
#include <utility>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findBottomLeftValue(TreeNode* root) {
  return get_bottom_left(root, 0).second;
}

pair<int, int> get_bottom_left(TreeNode* root, int level) {
  // returns {level, value}
  if (root == NULL) {
    return {INT_MIN, 0};
  }

  auto l = get_bottom_left(root->left, level + 1);
  auto r = get_bottom_left(root->right, level + 1);

  if (l.first == INT_MIN && r.first == INT_MIN) {
    return {level, root->val};
  }

  if (l.first >= r.first) {
    return {l.first, l.second};
  }

  return {r.first, r.second};
}