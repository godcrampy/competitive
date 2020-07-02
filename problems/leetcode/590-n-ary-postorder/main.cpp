#include <stack>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class RecursiveSolution {
  vector<int> postorder(Node* root) {
    vector<int> res;
    postorder_rec(root, res);

    return res;
  }

  void postorder_rec(Node* root, vector<int>& res) {
    if (root == NULL) {
      return;
    }

    for (Node* n : root->children) {
      postorder_rec(n, res);
    }

    res.push_back(root->val);
  }
};

class IterativeSolution {
  vector<int> postorder(Node* root) {
    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
      Node* node = s1.top();
      s1.pop();
      if (node != NULL) {
        s2.push(node);
        for (Node* n : node->children) {
          s1.push(n);
        }
      }
    }

    vector<int> res;
    while (!s2.empty()) {
      res.push_back(s2.top()->val);
      s2.pop();
    }

    return res;
  }
};