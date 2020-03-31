#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;

vector<int> largestValues(TreeNode* root) {
  vector<int> res;
  dfs(res, root, 0);
  return res;
}

void dfs(vector<int>& res, TreeNode* root, int level) {
  if (root == NULL) {
    return;
  }

  if (level == res.size()) {
    // first node for this level
    res.push_back(root->val);
  } else {
    res[level] = max(res[level], root->val);
  }

  dfs(res, root->left, level + 1);
  dfs(res, root->right, level + 1);
}