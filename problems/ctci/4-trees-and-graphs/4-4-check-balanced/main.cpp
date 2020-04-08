#include <iostream>
#include <utility>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<bool, int> check_balanced_rec(TreeNode* head) {
  if (head == NULL) {
    return {true, 0};
  }

  auto a = check_balanced_rec(head->left);
  auto b = check_balanced_rec(head->right);

  pair<bool, int> res;
  res.first = abs(a.second - b.second) <= 1;
  res.second = max(a.second, b.second) + 1;

  return res;
}

bool check_balanced(TreeNode* head) {
  // * Time: O(number of nodes)
  // * Space: O(log(number of nodes)) [height of tree]
  return check_balanced_rec(head).first;
}

int main(int argc, char const* argv[]) {
  TreeNode* a = new TreeNode(1);
  TreeNode* b = new TreeNode(2);
  TreeNode* c = new TreeNode(3);
  TreeNode* d = new TreeNode(4);
  TreeNode* e = new TreeNode(5);
  TreeNode* f = new TreeNode(6);
  TreeNode* g = new TreeNode(7);

  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  e->left = f;
  c->right = g;

  cout << check_balanced(a) << endl;
  return 0;
}
