#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ! IMP Common Ancestor

pair<bool, TreeNode*> common_ancestor(TreeNode* head, TreeNode* p,
                                      TreeNode* q) {
  // * Time: O(n)
  // * Space: O(n)
  // Returns {true, ancestor} if found in subtree
  // Returns {false, p/q} if only p or q found in subtree
  // Returns {false, NULL} if both not found in subtree
  if (head == p && head == q) {
    return {true, head};
  }

  if (head == NULL) {
    return {false, NULL};
  }

  auto l = common_ancestor(head->left, p, q);
  if (l.first) return l;

  auto r = common_ancestor(head->right, p, q);
  if (r.first) return r;

  if (r.second != NULL && l.second != NULL) {
    return {true, head};
  }

  if (head == p || head == q) {
    bool is_anc = l.second != NULL || r.second != NULL;
    return {is_anc, head};
  }

  return {false, l.second == NULL ? r.second : l.second};
}

int main(int argc, char const* argv[]) {
  /* code */
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

  cout << common_ancestor(a, d, g).second->val << endl;

  return 0;
}