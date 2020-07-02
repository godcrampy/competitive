#include <limits.h>

#include <iostream>
#include <memory>

using namespace std;

class BinaryTreeNode {
 public:
  int value_;
  BinaryTreeNode* left_;
  BinaryTreeNode* right_;

  BinaryTreeNode(int value) : value_(value), left_(nullptr), right_(nullptr) {}

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

bool isBST(const BinaryTreeNode* root, int low, int high) {
  if (root == NULL) {
    return true;
  }
  int v = root->value_;
  return (v > low && v < high) && isBST(root->left_, low, v) &&
         isBST(root->right_, v, high);
}

bool isBinarySearchTree(const BinaryTreeNode* root) {
  // determine if the tree is a valid binary search tree

  return isBST(root, INT_MIN, INT_MAX);
}
