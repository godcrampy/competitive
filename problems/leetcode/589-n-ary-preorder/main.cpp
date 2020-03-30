#include <stack>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class RecursiveSolution {
 public:
  vector<int> preorder(Node* root) {
    vector<int> res;
    preorder_rec(root, res);
    return res;
  }

  void preorder_rec(Node* root, vector<int>& res) {
    if (root == NULL) {
      return;
    }

    res.push_back(root->val);
    for (auto n : root->children) {
      preorder_rec(n, res);
    }
  }
};

class IterativeSolution {
 public:
  vector<int> preorder(Node* root) {
    stack<Node*> s;
    vector<int> res;
    if (root != NULL) {
      s.push(root);
    }

    while (!s.empty()) {
      auto node = s.top();
      s.pop();
      res.push_back(node->val);

      for (int i = node->children.size() - 1; i >= 0; --i) {
        s.push(node->children[i]);
      }
    }

    return res;
  }
};