#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(NULL) {}
};

void fill_map_dfs(TreeNode* head, int depth, map<int, pair<ListNode*, ListNode*>>& m) {
  if (head == NULL) return;
  if (m.find(depth) == m.end()) {
    // depth not found
    ListNode* a = new ListNode(head->val);
    pair<ListNode*, ListNode*> temp = {a, a};
    m.insert({depth, temp});
  } else {
    // depth found
    ListNode* node = new ListNode(head->val);
    m[depth].second->next = node;
    m[depth].second = node;
  }
  fill_map_dfs(head->left, depth + 1, m);
  fill_map_dfs(head->right, depth + 1, m);
}

vector<ListNode*> tree_to_depth_list(TreeNode* head) {
  // * Time: O(number of nodes)
  // * Space: O(number of nodes)
  map<int, pair<ListNode*, ListNode*>> m;  // depth => {first, last}
  fill_map_dfs(head, 0, m);

  vector<ListNode*> v(m.size());
  for (auto p : m) {
    v[p.first] = p.second.first;
  }

  return v;
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

  auto v = tree_to_depth_list(a);
  for (auto n : v) {
    while (n != NULL) {
      cout << n->val << " ";
      n = n->next;
    }
    cout << endl;
  }
  return 0;
}
