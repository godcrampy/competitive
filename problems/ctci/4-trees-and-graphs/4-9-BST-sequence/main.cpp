#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ! IMP Weave

void weave(list<int> first, list<int> second, list<int> prefix,
           vector<list<int>>& result) {
  if (first.size() == 0 || second.size() == 0) {
    prefix.insert(prefix.end(), first.begin(), first.end());
    prefix.insert(prefix.end(), second.begin(), second.end());
    result.push_back(prefix);
    return;
  }

  int first_last = first.front();
  first.pop_front();
  prefix.push_back(first_last);
  weave(first, second, prefix, result);
  first.push_front(first_last);
  prefix.pop_back();

  int second_last = second.front();
  second.pop_front();
  prefix.push_back(second_last);
  weave(first, second, prefix, result);
  second.push_front(first_last);
  prefix.pop_back();
}

vector<list<int>> sequence(TreeNode* root) {
  if (root == NULL) {
    return {{}};
  }

  vector<list<int>> res;

  list<int> prefix = {root->val};

  vector<list<int>> l = sequence(root->left);
  vector<list<int>> r = sequence(root->right);

  for (auto lv : l) {
    for (auto rv : r) {
      weave(lv, rv, prefix, res);
    }
  }

  return res;
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

  auto res = sequence(a);
  for (auto v : res) {
    for (auto n : v) {
      cout << n << " ";
    }
    cout << endl;
  }
  return 0;
}
