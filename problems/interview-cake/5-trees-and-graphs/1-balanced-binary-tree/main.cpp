#include <iostream>
#include <memory>

using namespace std;

// Given
class BinaryTreeNode {
 public:
  int value_;
  BinaryTreeNode* left_;
  BinaryTreeNode* right_;

  BinaryTreeNode(int value) : value_(value),
                              left_(nullptr),
                              right_(nullptr) {
  }

  ~BinaryTreeNode() {
    delete left_;
    delete right_;
  }

  BinaryTreeNode* insertLeft(int value) {
    this->left_ = new BinaryTreeNode(value);
    return this->left_;
  }

  BinaryTreeNode* insertRight(int value) {
    this->right_ = new BinaryTreeNode(value);
    return this->right_;
  }
};

struct res {
  int minDepth;
  int maxDepth;
  bool isBalanced;
};

res isBalancedRec(const BinaryTreeNode* root, int depth) {
  if (root == NULL) {
    res r;
    r.minDepth = depth;
    r.maxDepth = depth;
    r.isBalanced = true;
    return r;
  }

  auto r1 = isBalancedRec(root->left_, depth + 1);
  auto r2 = isBalancedRec(root->right_, depth + 1);

  int newMin = min(r1.minDepth, r2.minDepth);
  int newMax = max(r1.maxDepth, r2.maxDepth);

  res r;
  r.minDepth = newMin;
  r.maxDepth = newMax;
  r.isBalanced = (newMax - newMin < 2) || root->left_ == NULL || root->right_ == NULL;
  return r;
}

bool isBalanced(const BinaryTreeNode* treeRoot) {
  // determine if the tree is superbalanced
  return isBalancedRec(treeRoot, 0).isBalanced;
}
