#include <cmath>
#include <map>
#include <vector>

using namespace std;

// IMP
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<int, int> right_most;  // depth to right most val
vector<int> rightSideView(TreeNode* root) {
  add_to_view(root, 0);
  vector<int> res;
  for (auto p : right_most) {
    res.push_back(p.second);
  }
  return res;
}

void add_to_view(TreeNode* root, int depth) {
  if (root == NULL) return;
  if (right_most.find(depth) == right_most.end()) {
    right_most[depth] = root->val;
  }

  add_to_view(root->right, depth + 1);
  add_to_view(root->left, depth + 1);
}