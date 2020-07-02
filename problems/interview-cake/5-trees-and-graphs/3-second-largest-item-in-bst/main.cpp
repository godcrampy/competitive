#include <limits.h>

#include <iostream>

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

int getMaxVal(const BinaryTreeNode* root) {
  if (root == NULL) {
    return INT_MIN;
  }
  if (root->right_ != NULL) {
    return getMaxVal(root->right_);
  }
  return root->value_;
}

int findSecondLargest(const BinaryTreeNode* root) {
  // find the second largest item in the binary search tree
  if (root == NULL) {
    throw "";
  }
  auto itr = root;

  if (itr->right_ == NULL) {
    if (itr->left_ == NULL) {
      throw "";
    }
    return getMaxVal(itr->left_);
  }

  while (itr->right_->right_ != NULL) {
    itr = itr->right_;
  }

  return max(itr->value_, getMaxVal(itr->right_->left_));
}
