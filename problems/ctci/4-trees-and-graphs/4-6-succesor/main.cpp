#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* parent;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

TreeNode* left_most(TreeNode* node) {
  if (node == NULL) return NULL;
  if (node->left == NULL) return node;
  return left_most(node->left);
}

TreeNode* successor(TreeNode* node) {
  if (node == NULL) {
    return NULL;
  }

  if (node->right != NULL) {
    return left_most(node->right);
  }
  auto p = node->parent;
  while (p != NULL && p->left != node) {
    node = p;
    p = p->parent;
  }
  return p;
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
  b->parent = a;

  a->right = c;
  c->parent = a;

  b->left = d;
  d->parent = b;

  b->right = e;
  e->parent = b;

  e->left = f;
  f->parent = e;

  c->right = g;
  g->parent = c;

  cout << successor(e)->val << endl;
  return 0;
}
