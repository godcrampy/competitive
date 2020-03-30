#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  inorder_rec(root, res);
  return res;
}

void inorder_rec(TreeNode* root, vector<int>& res) {
  if (root == NULL) {
    return;
  }

  inorder_rec(root->left, res);
  res.push_back(root->val);
  inorder_rec(root->right, res);
}

vector<int> inorderTraversalRecursive(TreeNode* root) {
  stack<TreeNode*> s;
  TreeNode* itr = root;
  vector<int> res;

  while (!s.empty() || itr != NULL) {
    if (itr != NULL) {
      s.push(itr);
      itr = itr->left;
    } else {
      itr = s.top();
      s.pop();
      res.push_back(itr->val);
      itr = itr->right;
    }
  }

  return res;
}