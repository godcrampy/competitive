#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* arr_to_tree_res(vector<int>& v, int l, int r) {
  if (l > r) {
    return NULL;
  }

  int m = l + (r - l) / 2;
  TreeNode* temp = new TreeNode(v[m]);
  temp->left = arr_to_tree_res(v, l, m - 1);
  temp->right = arr_to_tree_res(v, m + 1, r);
  return temp;
}

TreeNode* arr_to_BST(vector<int>& v) {
  // * Time: O(number of nodes)
  // * Space: O(log(number of nodes)) Stack calls
  return arr_to_tree_res(v, 0, v.size() - 1);
}

int main(int argc, char const* argv[]) {
  vector<int> v = {1, 2, 3, 4, 5, 6};
  TreeNode* a = arr_to_BST(v);

  cout << a->val << endl;
  return 0;
}
